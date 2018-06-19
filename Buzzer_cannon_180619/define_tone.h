#define NOTE_D0 -1
#define NOTE_D1 294
#define NOTE_D2 330
#define NOTE_D3 350
#define NOTE_D4 393
#define NOTE_D5 441
#define NOTE_D6 495
#define NOTE_D7 556

#define NOTE_DL1 147
#define NOTE_DL2 165
#define NOTE_DL3 175
#define NOTE_DL4 196
#define NOTE_DL5 221
#define NOTE_DL6 248
#define NOTE_DL7 278

#define NOTE_DH1 589
#define NOTE_DH2 661
#define NOTE_DH3 700
#define NOTE_DH4 786
#define NOTE_DH5 882
#define NOTE_DH6 990
#define NOTE_DH7 112
//以上部分是定義是把每個音符和頻率值對應起來，其實不用打這麼多，
//但是都打上了，後面可以隨意編寫D調的各種歌，我這裡用NOTE_D+數位表示音符，
//NOTE_DH+數位表示上面有點的那種音符，NOTE_DL+數位表示下面有點的那種音符。
//這樣後面寫起來比較好識別。
#define WHOLE 1
#define HALF 0.5
#define QUARTER 0.25
#define EIGHTH 0.25
#define SIXTEENTH 0.625
//這部分是用英文對應了拍子，這樣後面也比較好看
