int start = 5;
int ledLen = 9;
void setup() {
  Serial.begin(115200);
  for(int i=5;i<14;i++){
    pinMode(i,OUTPUT);
  }
}

void loop() {
  for(int i=start;i<start+ledLen*2;i++){
//    int pin;
//    if(i<start+ledLen){
//      pin = i;
//    }else{
//      pin = start+ledLen*2-i-1;
//    }
    int pin = i<start+ledLen?i:start*2+ledLen*2-i-1;
    digitalWrite(pin, HIGH);
    delay(100);
    digitalWrite(pin, LOW);
    delay(100);
    Serial.println(pin);
  }
//  int len = 14-5;
//  for(int i=5;i<14+len;i++){
//    int pin = i<14?i:14+len-i;
//    digitalWrite(pin,HIGH);
//    delay(200);
//    digitalWrite(pin,LOW);
//  }
}
