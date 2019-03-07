#include "pitches.h"
#include "music.h"
//使用100歐姆以上電阻
const int btnPin = 49;
const int tonePin = 11; //蜂鳴器的pin
int length;//這裡定義一個變數，後面用來表示共有多少個音符
void setup()
{
  pinMode(tonePin, OUTPUT); //設置蜂鳴器的pin為輸出模式
  pinMode(btnPin, INPUT);
  length = sizeof(tune) / sizeof(tune[0]);
  //這裡用了一個sizeof函式，可以查出tone序列裡有多少個音符
  pinMode(45,OUTPUT);//按鈕的VCC
  digitalWrite(45,HIGH);
}
int noteCount = 0;
void loop()
{
  if(noteCount >= length - 1)noteCount = 0;
  if (digitalRead(btnPin) == 1) {
    delay(3);//反彈跳
    if (digitalRead(btnPin) == 1) {
      while (digitalRead(btnPin) == 1) {
        tone(tonePin, tune[noteCount]); //此函數依次播放tune序列裡的陣列，即每個音符
      }
      noTone(tonePin);//停止當前音符，進入下一音符
      noteCount += 1;
    }
  }
}
