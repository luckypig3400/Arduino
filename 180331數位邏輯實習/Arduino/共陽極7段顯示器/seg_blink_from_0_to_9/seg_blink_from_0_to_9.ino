int com = 13;
void setup() {
  for(int i=2;i<9;i++){
    pinMode(i,OUTPUT);
  }
  pinMode(com,OUTPUT);
  digitalWrite(com,HIGH);
}

void loop() {
  segClearAll();
  segShow0();
  delay(1000);
  segClearAll();
  segShow1();
  delay(1000);
  segClearAll();
  segShow2();
  delay(1000);
  segClearAll();
  segShow3();
  delay(1000);
  segClearAll();
  segShow4();
  delay(1000);
  segClearAll();
  segShow5();
  delay(1000);
  segClearAll();
  segShow6();
  delay(1000);
  segClearAll();
  segShow7();
  delay(1000);
  segClearAll();
  segShow8();
  delay(1000);
  segClearAll();
  segShow9();
  delay(1000);
}
