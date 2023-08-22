// OLED參考: https://blog.jmaker.com.tw/u8g2-oled/
// MQ系列感測器參考1: https://github.com/miguel5612/MQSensorsLib#getting-started
// MQ系列感測器參考2: https://sites.google.com/mail3.hwsh.tc.edu.tw/earth/arduinoadvanced/co-sensor-mq-7

#include <Arduino.h>
#include <U8g2lib.h>

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
int OLED_VCC_PIN = 22;
int OLED_GND_PIN = 23;
int MQ9_VCC_PIN = A13;
int MQ9_GND_PIN = A12;
int MQ9_A0_PIN = A14;
int MQ9_D0_PIN = A15;
int MQ7_VCC_PIN = A2;
int MQ7_GND_PIN = A3;
int MQ7_A0_PIN = A0;
int MQ7_D0_PIN = A1;
// *******硬體腳位宣告區結尾*******

double MQ9_R0 = 28.56;
double MQ7_R0 = 5.27;

void setup(void) {
  u8g2.begin();
  Serial.begin(9600);

  pinMode(OLED_VCC_PIN, OUTPUT);
  digitalWrite(OLED_VCC_PIN, HIGH);
  pinMode(OLED_GND_PIN, OUTPUT);
  digitalWrite(OLED_GND_PIN, LOW);

  pinMode(MQ9_VCC_PIN, OUTPUT);
  digitalWrite(MQ9_VCC_PIN, HIGH);
  pinMode(MQ9_GND_PIN, OUTPUT);
  digitalWrite(MQ9_GND_PIN, LOW);

  pinMode(MQ7_VCC_PIN, OUTPUT);
  digitalWrite(MQ7_VCC_PIN, HIGH);
  pinMode(MQ7_GND_PIN, OUTPUT);
  digitalWrite(MQ7_GND_PIN, LOW);
}

void loop(void) {
  u8g2.setFont(u8g2_font_HelvetiPixelOutline_te);  //設定字型
  // 可用字型參考: https://github.com/olikraus/u8g2/wiki/fntlistall
  u8g2.firstPage();
  do {
    u8g2.drawStr(0, 13, "Hello World !");  //輸出文字
    u8g2.drawStr(0, 28, "CO: 10PPM");      //輸出文字
    // u8g2.drawXBMP(0,16, imgWidth, imgHeight, logo_bmp);  //繪圖
  } while (u8g2.nextPage());
  //delay(1000);
}