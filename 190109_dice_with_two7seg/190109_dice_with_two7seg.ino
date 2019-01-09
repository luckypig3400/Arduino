//you must define a com pin first!!
int com1 = 6;
int com2 = A1;
int randNumber;
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
  randNumber = random(1, 7);//取亂數(最小值, 最大值+1)
  switch(randNumber){
    case 1:
      seg1Show1();
      break;
    case 2:
      seg1Show2();
      break;
    case 3:
      seg1Show3();
      break;
    case 4:
      seg1Show4();
      break;
    case 5:
      seg1Show5();
      break;
    case 6:
      seg1Show6();
      break;
    default:
      segClearAll();
      break;
  }
  delay(1000);
  segClearAll();
}
