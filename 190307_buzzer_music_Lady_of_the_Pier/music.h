//碼頭姑娘(Lady of the Pier) 譜來源:
//http://thaleschou.pixnet.net/blog/post/F5A5G5F58E500-%E9%8D5%8F5%E9%AC5%98%EA5%8F%9D5%EA5%9B%BD5%EF%BC%9A%EB5%AD5%BC%E9%A0%AD%EG5%AB5%9C5%EG5%A8%98----%EF5%B8%8D%EG5%B0%88%EA5%AG5%AD%EG5%9A5%AE%E9%9F%BE5%EB5%B0%AC5%E8%AD%9C
/*音符對應轉換表
  Do, Re, Mi, Fa, So, La, Si
  C,  D,  E,  F,  G,  A,  B
  1,  2,  3,  4,  5,  6,  7
*/
/*$PS: 在Arduino，音符(英文字母)後面的數字是指升降key
  如:C4 指的是 標準Do 的降一個八度音
  #標準Do指的是C5
  所以C6 就是 標準Do 的高一個八度音
*/
//------------------以下是歌曲的音符及節奏---------------------
int tune[] =
{ //整首歌的音符
  //P前奏
  E5,D5,E5,G5,D5,E5,D5,E5,G5,      E5,D5,E5,G5,A5,G5,F5,E5,F5,G5,
  F5,E5,F5,E5,G5,G5,F5,E5,F5,G5,    E5,D5,E5,A5,G5,A5,E5,D5,E5,A5,B5,C5,G5,
  //A
  A5,G5,G5,G5,E5,G5,    E5,G5,D5,E5,C5,    E5,G5,G5,E5,G5,    E5,D5,D5,C5,D5,
  A5,G5,G5,G5,E5,G5,    E5,C5,C5,G5,A5,    C5,A5,C5,A5,C5,    G5,E5,G5,E5,
  //B
  E5,D5,E5,E5,G5,E5,D5,E5,E5,    D5,E5,G5,E5,D5,C5,
  E5,D5,E5,G5,    E5,D5,E5,E5,    D5,E5,E5,C5,C5,G5,
  E5,D5,E5,G5,    E5,D5,E5,E5,    D5,E5,G5,E5,D5,C5,
  E5,D5,E5,G5,    G5,G5,E5,      D5,E5,E5,C5,C5,D5,
  //Q
  E5,D5,E5,G5,    E5,D5,E5,E5,    D5,A5,
  E5,D5,E5,G5,    E5,D5,E5,E5,    D5,B5,C5,D5,
  //R
  E5,D5,E5,G5,D5,C5,B5,A5,G5,A5,E5,D5,G5,    G5,B5,E5,G5,
  //C
  D5,C5,D5,D5,C5,D5,D5,B5,C5
  //註:整首歌的repeat段: P AB Q ABB R C
  
};//這部分就是整首曲子的音符部分，用了一個序列定義為tune，整數
/*
char duration[] =
{ //整首歌的節奏
  
};//這部分是整首曲子的接拍部分，也定義個序列duration，
//浮點（陣列的個數和前面音符的個數是一樣的，一一對應麼）
*/
