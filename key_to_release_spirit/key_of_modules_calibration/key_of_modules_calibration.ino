// OLED參考: https://blog.jmaker.com.tw/u8g2-oled/
// MQ系列感測器參考1: https://github.com/miguel5612/MQSensorsLib#getting-started
// MQ系列感測器參考2: https://sites.google.com/mail3.hwsh.tc.edu.tw/earth/arduinoadvanced/co-sensor-mq-7

#include <Arduino.h>
#include <U8g2lib.h>
#include "MQ7.h"

// *******OLED參數宣告區起點*******
#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif
//U8G2_SSD1306_128X64_NONAME_1_SW_I2C u8g2(U8G2_R0, /* clock=*/ D2, /* data=*/ D1, /* reset=*/ U8X8_PIN_NONE);  //NodeOLED用這行，或部份NodeMCU系列的板子也用這行
//U8G2_SSD1306_128X64_NONAME_1_SW_I2C u8g2(U8G2_R0, /* clock=*/ D2, /* data=*/ D1, /* reset=*/ U8X8_PIN_NONE);  //ESP8266板子搭配SSD1306用這行
//U8G2_SSD1306_128X64_NONAME_1_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE); //Arduino搭配SSD1306(0.96" OLED)用這行
U8G2_SH1106_128X64_NONAME_1_HW_I2C u8g2(U8G2_R0, /* reset=*/U8X8_PIN_NONE);  //Arduino搭配SH1106(1.3" OLED)用這行
//U8G2_SSD1306_128X32_UNIVISION_1_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);
//Arduino搭配SSD1306(0.91" OLED)用這行
// *******OLED參數宣告區結尾*******

// *******硬體腳位宣告區起點*******
// OLED的VCC接Arduino的3.3V pin
// MQ系列模組的VCC都接Arduino的5V pin
// 所有模組的GND都接在Arduino的GND，而不使用digtialWrite(pinNum, LOW);的方式來作為GND

int MQ9_A0_PIN = A14;
int MQ9_D0_PIN = A15;

int MQ7_A0_PIN = A0;
int MQ7_D0_PIN = A1;
// init MQ7 device
MQ7 mq7(MQ7_A0_PIN, 5);
// *******硬體腳位宣告區結尾*******

double MQ9_R0 = 28.56;  //可能沒用
double MQ7_R0 = 5.27;   //可能沒用

void setup(void) {
  u8g2.begin();
  u8g2.setFont(u8g2_font_profont15_tr);  //設定字型
  // 可用字型參考: https://github.com/olikraus/u8g2/wiki/fntlistall
  u8g2.drawStr(0, 13, "Calibrating MQ7...");
  mq7.calibrate();		// calculates R0
  u8g2.drawStr(0, 26, "Calibrating done! MQ9 R0=");
  u8g2.drawStr(0, 39, String(mq7.getR0()).c_str());
  delay(1000);
}

void loop(void) {
  String MQ9Voutput = "MQ9 Volt= ";
  String MQ9R0output = "MQ9 R0= ";
  String MQ7ppmOutput = "MQ7 ppm= ";
  float MQ9sensor_volt = 0;
  float MQ9_RS_air = 0;  //  Rs in clean air
  float MQ9_R0 = 0;      // R0 in 1000 ppm LPG
  float MQ9sensorValue = 0;

  //Average
  for (int x = 0; x < 100; x++) {
    MQ9sensorValue = MQ9sensorValue + analogRead(MQ9_A0_PIN);
  }
  MQ9sensorValue = MQ9sensorValue / 100.0;
  //-----------------------------------------------/

  MQ9sensor_volt = (MQ9sensorValue / 1024) * 5.0;
  MQ9_RS_air = (5.0 - MQ9sensor_volt) / MQ9sensor_volt;  // Depend on RL on yor module
  MQ9_R0 = MQ9_RS_air / 9.9;                           // According to MQ9 datasheet table

  MQ9Voutput += String(MQ9sensor_volt) += "V";
  MQ9R0output += String(MQ9_R0);

  MQ7ppmOutput += String(mq7.readPpm());

  u8g2.firstPage();
  do {
    u8g2.drawStr(0, 13, MQ9Voutput.c_str());  //輸出文字
    // https://forum.arduino.cc/t/how-to-display-a-string-variable-with-the-u8g2-library/622278/2
    u8g2.drawStr(0, 26, MQ9R0output.c_str());  //輸出文字
    u8g2.drawStr(0, 39, MQ7ppmOutput.c_str());
    // u8g2.drawXBMP(0,16, imgWidth, imgHeight, logo_bmp);  //繪圖
  } while (u8g2.nextPage());
  // delay(100);
}