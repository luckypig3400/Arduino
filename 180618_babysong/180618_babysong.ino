//http://www.geek-workshop.com/thread-288-1-1.html
#include "define_tone.h"
#include "music.h"

const int tonePin=9;//蜂鳴器的pin
int length;//這裡定義一個變數，後面用來表示共有多少個音符
void setup()
{
  pinMode(tonePin,OUTPUT);//設置蜂鳴器的pin為輸出模式
  length = sizeof(tune)/sizeof(tune[0]);
  //這裡用了一個sizeof函式，可以查出tone序列裡有多少個音符
}

void loop()
{
  for(int x=0;x<length;x++)//迴圈音符的次數
  {
    tone(tonePin,tune[x]);//此函數依次播放tune序列裡的陣列，即每個音符
    delay(400*duration[x]);//每個音符持續的時間，即節拍duration，
    //400是調整時間的越大，曲子速度越慢，越小曲子速度越快，自己掌握吧
    noTone(tonePin);//停止當前音符，進入下一音符
  }
  delay(5000);//等待5秒後，迴圈重新開始
}


