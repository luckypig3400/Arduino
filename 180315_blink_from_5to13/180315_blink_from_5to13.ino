int start = 5;
int ledLen = 9;
void setup() {
  Serial.begin(115200);
  for(int i=4;i<14;i++){
    pinMode(i,OUTPUT);
  }
  digitalWrite(4,HIGH);
}

void loop() {
  for(int i=5;i<14;i++){
    digitalWrite(i,HIGH);
    delay(200);
    digitalWrite(i,LOW);
  }
//    int pin = i<start+ledLen?i:start*2+ledLen*2-i-1;
//    digitalWrite(pin, HIGH);
//    delay(100);
//    digitalWrite(pin, LOW);
//    delay(100);
//    Serial.println(pin);
//  }
}
