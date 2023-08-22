// OLED參考: https://blog.jmaker.com.tw/u8g2-oled/
// MQ9參考: https://www.instructables.com/How-to-Calibrate-Use-MQ9-Gas-Sensor-W-Arduino/

#include <Arduino.h>
#include <U8g2lib.h>

#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif

//U8G2_SSD1306_128X64_NONAME_1_SW_I2C u8g2(U8G2_R0, /* clock=*/ D2, /* data=*/ D1, /* reset=*/ U8X8_PIN_NONE);  //NodeOLED用這行，或部份NodeMCU系列的板子也用這行
//U8G2_SSD1306_128X64_NONAME_1_SW_I2C u8g2(U8G2_R0, /* clock=*/ D2, /* data=*/ D1, /* reset=*/ U8X8_PIN_NONE);  //ESP8266板子搭配SSD1306用這行
//U8G2_SSD1306_128X64_NONAME_1_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE); //Arduino搭配SSD1306(0.96" OLED)用這行
U8G2_SH1106_128X64_NONAME_1_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE); //Arduino搭配SH1106(1.3" OLED)用這行
//U8G2_SSD1306_128X32_UNIVISION_1_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);
//Arduino搭配SSD1306(0.91" OLED)用這行

void setup(void) {
  u8g2.begin();  
}

void loop(void) {
  u8g2.setFont(u8g2_font_HelvetiPixelOutline_te); //設定字型
  // 可用字型參考: https://github.com/olikraus/u8g2/wiki/fntlistall
  u8g2.firstPage();
  do {
    u8g2.drawStr(0,13,"Hello World !");  //輸出文字
    u8g2.drawStr(0,17,"CO: 10PPM");  //輸出文字
    // u8g2.drawXBMP(0,16, imgWidth, imgHeight, logo_bmp);  //繪圖
  } while ( u8g2.nextPage() );
  //delay(1000);
}