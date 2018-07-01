//------------------以下是歌曲的音符及節奏---------------------
int tune[] = 
{//整首歌的音符
  NOTE_DH3,NOTE_DH2,NOTE_DH1,NOTE_D7,
  NOTE_D6,NOTE_D5,NOTE_D6,NOTE_D7,
  NOTE_DH3,NOTE_DH3,NOTE_DH1,NOTE_DH2,NOTE_D7,NOTE_DH1,NOTE_DH1,NOTE_D6,NOTE_D7,NOTE_D5
};//這部分就是整首曲子的音符部分，用了一個序列定義為tune，整數

float duration[]=
{//整首歌的節奏
  1,1,1,1,
  1,1,1,1,
  0.5,0.25,0.25,0.75,0.25,0.5,0.25,0.25,0.75,0.25
};//這部分是整首曲子的接拍部分，也定義個序列duration，
//浮點（陣列的個數和前面音符的個數是一樣的，一一對應麼）

