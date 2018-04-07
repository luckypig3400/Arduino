int com = 13,s1=12,s2=11;
int a=2,b=3,c=4,d=5,e=6,f=7,g=8;
void setup() {
  // put your setup code here, to run once:
  pinMode(com,OUTPUT);
  pinMode(s1,INPUT);
  pinMode(s2,INPUT);
  for(int i = 2;i<9;i++){
    pinMode(i,OUTPUT);
    digitalWrite(i,HIGH);
  }
  digitalWrite(com,HIGH);
}
int s1state=digitalRead(s1);
int s2state=digitalRead(s2);
void loop() {
  for(int i=2;i<9;i++){
    digitalWrite(i,HIGH);
  }
  //above is to reset OUTPUT pin
  s1state=digitalRead(s1);
  s2state=digitalRead(s2);
  //above is to read state of input
  if(s1state==HIGH && s2state==HIGH){
    digitalWrite(a,LOW);
    digitalWrite(c,LOW);
    digitalWrite(d,LOW);
    digitalWrite(e,LOW);
    digitalWrite(f,LOW);
    digitalWrite(g,LOW);
  }
  //above is to show "6" when s1=1 and s2=1
  else if(s1state==LOW && s2state==HIGH){
      digitalWrite(a,LOW);
      digitalWrite(b,LOW);
      digitalWrite(c,LOW);
      digitalWrite(f,LOW);
      digitalWrite(g,LOW);
  }
  //above is to show "9" when s1=0 and s2=1
  else if(s1state==HIGH && s2state==LOW){
      digitalWrite(a,LOW);
      digitalWrite(b,LOW);
      digitalWrite(c,LOW);
      digitalWrite(d,LOW);
      digitalWrite(g,LOW);
  }
  //above is to show "3" when s1=1 and s2=0
  else if(s1state==LOW && s2state==LOW){
      digitalWrite(a,LOW);
      digitalWrite(b,LOW);
      digitalWrite(c,LOW);
      digitalWrite(d,LOW);
      digitalWrite(e,LOW);
      digitalWrite(f,LOW);
  }
  //above is to show "0" when s1=0 and s2=0
}
