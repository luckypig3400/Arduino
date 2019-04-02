//Avicii wake me up 譜來源:
//https://www.youtube.com/watch?v=LA7HvXXvxbM
/*音符對應轉換表
	Do,	Re,	Mi,	Fa,	So,	La,	Si
	C,	D,	E,	F,	G,	A,	B
	1,	2,	3,	4,	5,	6,	7
*/
/*$PS: 在Arduino，音符(英文字母)後面的數字是指升降key
	如:C4 指的是 標準Do 的降一個八度音
	#標準Do指的是C5
	所以C6 就是 標準Do 的高一個八度音
*/
//------------------以下是歌曲的音符及節奏---------------------
int tune[] =
{ 
  A4, A4, G4, A4, C5, A4, G4, A4, G4,
  C5, C5, C5, D5, C5, D5, E5, C5,
  A4, A4, G4, A4, C5, A4, G4, A4, G4,
  C5, C5, C5, D5, C5, D5, E5, C5,
  A4, A4, G4, A4, C5, A4, G4, A4, G4,
  C5, C5, C5, D5, C5, D5, E5, C5,
  A4, A4, G4, A4, C5, A4, G4, A4, G4,
  C5, C5, C5, D5, C5, D5, E5, C5,
  A4, A4, G4, A4, C5, A4, G4, A4, G4,
  C5, C5, C5, D5, C5, D5, E5, C5,
  A4, A4, G4, A4, C5, A4, G4, A4, G4,
  C5, C5, C5, D5, C5, D5, E5, C5,
  A4, A4, G4, A4, C5, A4, G4, A4, G4,
  C5, C5, C5, D5, C5, D5, E5, C5,
  A4, A4, G4, A4, C5, A4, G4, A4, G4,
  C5, C5, C5, D5, C5, D5, E5, C5,
  A4, A4, G4, A4, C5, A4, G4, A4, G4,
  C5, C5, C5, D5, C5, D5, E5, C5,
  A4, A4, G4, A4, C5, A4, G4, A4, G4,
  C5, C5, C5, D5, C5, D5, E5, C5,
  A4, A4, G4, A4, C5, A4, G4, A4, G4,
  C5, C5, C5, D5, C5, D5, E5, C5,
  A4, A4, G4, A4, C5, A4, G4, A4, G4,
  C5, C5, C5, D5, C5, D5, E5, C5,

};//這部分就是整首曲子的音符部分，用了一個序列定義為tune，整數
