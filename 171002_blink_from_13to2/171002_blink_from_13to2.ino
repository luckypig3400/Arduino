int Led = 13;
int addLed = 1;
void setup() {
  // put your setup code here, to run once:
  pinMode(Led,OUTPUT);
}
void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(Led,HIGH);
  delay(300);
  digitalWrite(Led,LOW);
  delay(100);
  if(Led == 2)addLed = -1;
  if(Led == 13)addLed = 1;
  Led-=addLed;
  setup();
}
