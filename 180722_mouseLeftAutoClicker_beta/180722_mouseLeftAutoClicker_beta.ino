#include <Mouse.h>
void setup() {
  pinMode(5,INPUT);//LeftButton
  pinMode(7,INPUT);//Enable/Disable
  pinMode(6,INPUT);//RightButton
  Mouse.begin();
}
void loop() {
  if(digitalRead(5) == HIGH){
    Mouse.click(MOUSE_LEFT);
    delay(80);
  }
}
