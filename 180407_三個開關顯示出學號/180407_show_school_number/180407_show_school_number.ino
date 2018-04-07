int com=5;
int s1=12,s2=11,s3=10;
void setup() {
  for(int i=1;i<8;i++)pinMode(i,OUTPUT);
  for(int j=30;j<37;j++)pinMode(j,OUTPUT);
  for(int j=10;j<13;j++)pinMode(j,INPUT);
  for(int i=1;i<4;i++)digitalWrite(i,HIGH);
  digitalWrite(com,HIGH);
}
int s1state=digitalRead(s1);
int s2state=digitalRead(s2);
int s3state=digitalRead(s3);
void loop() {
  s1state=digitalRead(s1);
  s2state=digitalRead(s2);
  s3state=digitalRead(s3);
  segClearAll();
  //my school number 0503232
  if(s1state==LOW && s2state==LOW &&s3state==LOW){
    //s1 s2 s3 = 000
    segShow0();
  }
  if(s1state==LOW && s2state==LOW &&s3state==HIGH){
    //s1 s2 s3 = 001
    segShow5();
  }
  if(s1state==LOW && s2state==HIGH &&s3state==LOW){
    //s1 s2 s3 = 010
    segShow0();
  }
  if(s1state==LOW && s2state==HIGH &&s3state==HIGH){
    //s1 s2 s3 = 011
    segShow3();
  }
  if(s1state==HIGH && s2state==LOW &&s3state==LOW){
    //s1 s2 s3 = 100
    segShow2();
  }
  
  if(s1state==HIGH && s2state==LOW &&s3state==HIGH){
    //s1 s2 s3 = 101
    segShow3();
  }
  if(s1state==HIGH && s2state==HIGH &&s3state==LOW){
    //s1 s2 s3 = 110
    segShow2();
  }
  if(s1state==HIGH && s2state==HIGH && s3state==HIGH){
    // s1 s2 s3 = 111
    segShow0();delay(300);segClearAll();
    segShow5();delay(300);segClearAll();
    segShow0();delay(300);segClearAll();
    segShow3();delay(300);segClearAll();
    segShow2();delay(300);segClearAll();
    segShow3();delay(300);segClearAll();
    segShow2();delay(300);segClearAll();
  }
}
