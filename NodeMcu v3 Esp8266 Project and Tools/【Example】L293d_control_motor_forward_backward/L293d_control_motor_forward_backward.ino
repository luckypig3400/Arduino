int output1=7;
int output2=6;
void setup() {
  pinMode(output1,OUTPUT);
  pinMode(output2,OUTPUT);
  digitalWrite(output1,LOW);
  digitalWrite(output2,LOW);
}

void loop() {
  motorRunForward();
  delay(3000);
  motorRunBackward();
  delay(3000);
  motorStop();
  delay(1000);
}

void motorRunForward(){
  digitalWrite(output2,LOW);  
  digitalWrite(output1,HIGH);
}
void motorRunBackward(){
  digitalWrite(output1,LOW);
  digitalWrite(output2,HIGH);
}
void motorStop(){
  digitalWrite(output1,LOW);
  digitalWrite(output2,LOW);
}

