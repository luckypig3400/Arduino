// OLED參考: https://blog.jmaker.com.tw/u8g2-oled/
// MQ系列感測器參考1: https://github.com/miguel5612/MQSensorsLib#getting-started
// MQ系列感測器參考2: https://sites.google.com/mail3.hwsh.tc.edu.tw/earth/arduinoadvanced/co-sensor-mq-7

#include <Arduino.h>
#include <U8g2lib.h>
#include <MQUnifiedsensor.h>

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
// *******硬體腳位宣告區結尾*******

MQUnifiedsensor MQ9("Arduino MEGA", 5, 10, MQ9_A0_PIN, "MQ-9");
MQUnifiedsensor MQ7("Arduino MEGA", 5, 10, MQ9_A0_PIN, "MQ-7");

double MQ9_R0 = 25.60;  //放置數小時後將校準值紀錄於此
double MQ7_R0 = 8.82;  //放置數小時後將校準值紀錄於此

void setup(void) {
  Serial.begin(115200);

  MQ9.setRegressionMethod(1);  //_PPM =  a*ratio^b
  MQ9.setA(599.65);
  MQ9.setB(-2.244);  // Configure the equation to to calculate CO concentration
  // https://github.com/miguel5612/MQSensorsLib/blob/master/examples/MQ-9/MQ-9.ino

  MQ7.setRegressionMethod(1);  //_PPM =  a*ratio^b
  MQ7.setA(99.042);
  MQ7.setB(-1.518);  // Configure the equation to to calculate CO concentration
  // https://github.com/miguel5612/MQSensorsLib/blob/master/examples/MQ-7/MQ-7.ino

  //init the sensor
  MQ9.init();
  MQ7.init();

  //Print in serial monitor
  Serial.println("MQ9 & MQ7 Sensors CO Detection");
  MQ9.setR0(MQ9_R0);
  MQ7.setR0(MQ7_R0);
  Serial.println("Using previous recorded R0");

  MQ9.serialDebug(true);
  MQ7.serialDebug(true);

  u8g2.begin();
  u8g2.setFont(u8g2_font_profont15_tr);  //設定字型
  // 可用字型參考: https://github.com/olikraus/u8g2/wiki/fntlistall
}

void loop(void) {
  MQ9.update();
  MQ7.update();
  //Read the sensor and print in serial port
  float MQ9_value = MQ9.readSensor();
  float MQ7_value = MQ7.readSensor();

  String MQ9_CO_output = "MQ9 read " + String(MQ9_value) + "PPM";
  String MQ7_CO_output = "MQ7 read " + String(MQ7_value) + "PPM";

  // Serial.println(String(MQ9_value) + " | " + String(MQ7_value));
  MQ9.serialDebug(); // Will print the table on the serial port
  MQ7.serialDebug(); // Will print the table on the serial port

  u8g2.firstPage();
  do {
    u8g2.drawStr(0, 13, MQ9_CO_output.c_str());  //輸出文字
    // https://forum.arduino.cc/t/how-to-display-a-string-variable-with-the-u8g2-library/622278/2
    u8g2.drawStr(0, 26, MQ7_CO_output.c_str());
    // u8g2.drawStr(0, 39, "MQ7_String".c_str());
    // u8g2.drawXBMP(0,16, imgWidth, imgHeight, logo_bmp);  //繪圖
  } while (u8g2.nextPage());

  delay(100);
}