//http://blog.xuite.net/chycahock/EDA/224660163-Ardunio%2B%E8%9C%82%E9%B3%B4%E5%99%A8%28Buzzer%29%E6%92%AD%E9%9F%B3%E6%A8%82
const int buzzer = 9; 
// 用Pin8 輸出方波至蜂鳴器
void setup() {
    pinMode(buzzer,OUTPUT);
}

void loop() {
    // simulate phone call
    for ( int ii=0; ii<10; ii++ ) {
        tone(buzzer,1000);
        delay(50);
        tone(buzzer,500);
        delay(50);
    }
    noTone(buzzer);
    delay(2000);
}
