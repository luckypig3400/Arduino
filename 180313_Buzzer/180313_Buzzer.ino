int pin8=8,pin9=9,pin10=10,pin11=11,pin12=12;
#include "pitches.h"
int speakerPin=11;
char notes[] = "ccggaagffeeddc ";
// 決定每個音階的拍子，注意這邊用 unsigned long 所以拍子只能是正整數
unsigned long beats[] = {1,1,1,1,1,1,2,1,1,1,1,1,1,2,4}; 
// 利用 sizeof()，算出總共要多少音符
int length = sizeof(notes); 
// 決定一拍多長，這邊一拍 300 ms
int tempo = 300;
// notes in the melody:
int melody[] = {
  NOTE_C5, NOTE_D5, NOTE_E5, NOTE_F5, NOTE_G5, NOTE_A5, NOTE_B5, NOTE_C6};
int duration = 500;  // 500 miliseconds

void setup() {
  pinMode(pin11,OUTPUT);
}

void loop() {
  // 利用 for 來播放我們設定的歌曲，一個音一個音撥放
  for (int i = 0; i < length; i++) {
 // 如果是空白的話，不撥放音樂
    if (notes[i] == ' ') {
      delay(beats[i] * tempo); // rest
    } else {
  // 呼叫 palyNote() 這個 function，將音符轉換成訊號讓蜂鳴器發聲
      playNote(speakerPin,notes[i], beats[i] * tempo);
    } 
    // 每個音符之間的間隔，這邊設定的長短會有連音 or 段音的效果
    delay(tempo/10); 
  }
}

void playNote(int OutputPin, char note, unsigned long duration) {
   // 音符字元與對應的頻率由兩個矩陣表示
  char names[] = { 'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C' };
  int tones[] = { 261, 294, 330, 349, 392, 440, 494, 523 };
  // 播放音符對應的頻率
  for (int i = 0; i < 8; i++) {
    if (names[i] == note) {
      tone(OutputPin,tones[i], duration);
  //下方的 delay() 及 noTone ()，測試過後一定要有這兩行，整體的撥放出來的東西才不會亂掉，可能是因為 Arduino 送出tone () 頻率後會馬上接著執行下個指令，不會等聲音播完，導致撥出的聲音混合而亂掉
      delay(duration);
      noTone(OutputPin);
    }
  }
}

/*
void loop() {
  for(int thisNote=0;thisNote<8;thisNote++){
    tone(pin9,melody[thisNote],duration);
    delay(1000);
  }
}
*/
