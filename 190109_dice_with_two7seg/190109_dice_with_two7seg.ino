//you must define a com pin first!!
int com1 = 6;
int com2 = A1;
void setup() {
  //Serial.begin(9600);//debug
  delay(1000);
  for(int i=2;i<=11;i++){
    pinMode(i,OUTPUT);
    //Serial.println(i);//debug
  }
  pinMode(com1,OUTPUT);
  digitalWrite(com1,HIGH);
  pinMode(com2,OUTPUT);
  digitalWrite(com2,HIGH);
}

void loop() {
  segClearAll();
  seg1Show0();
  delay(1000);
  segClearAll();
  seg1Show1();
  delay(1000);
  segClearAll();
  seg1Show2();
  delay(1000);
  segClearAll();
  seg1Show3();
  delay(1000);
  segClearAll();
  seg1Show4();
  delay(1000);
  segClearAll();
  seg1Show5();
  delay(1000);
  segClearAll();
  seg1Show6();
  delay(1000);
  segClearAll();
  seg1Show7();
  delay(1000);
  segClearAll();
  seg1Show8();
  delay(1000);
  segClearAll();
  seg1Show9();
  delay(1000);
}
