/* REF:
  + https://forum.arduino.cc/t/using-analog-pins-for-push-buttons/309407
  + https://www.arduino.cc/reference/en/language/functions/usb/keyboard/keyboardwrite/

*/
#include <Keyboard.h>;
// constants won't change. They're used here to set pin numbers:
const int buttonPin[6] = {696969, A1, A2, A3, A4, A5};
// the number of the pushbutton pin

const int ledPin =  LED_BUILTIN; // the number of the LED pin

int buttonState[6] = {0, 0, 0, 0, 0, 0};
// variable for reading the pushbutton status

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  for (int i = 1; i < 6; i++) {
    // initialize the pushbutton pin as an input:
    pinMode(buttonPin[i], INPUT);
  }
  Serial.begin(9600);
  Keyboard.begin();
}

int buttonLock[6] = {0, 0, 0, 0, 0, 0};

void loop() {
  String allBtnState;
  for (int i = 1; i < 6; i++) {
    // read the state of the pushbutton value:
    buttonState[i] = digitalRead(buttonPin[i]);
    allBtnState = String(allBtnState + "Btn" + i + ":" + buttonState[i] + "," + buttonLock[i] + "\t");
    // https://www.arduino.cc/reference/en/language/variables/data-types/stringobject/
  }
  Serial.println(allBtnState);

  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  for (int i = 1; i < 6; i++) {
    if (buttonState[i] == LOW) {
      //如果有任何按鈕被按下，其對應的接收腳位狀態為低電位
      buttonLock[i] += 1;
      if (buttonLock[i] == 69) {
        //連續偵測到69次按下狀態，確認為人為操作非雜訊
        Keyboard.write(48 + i);// ASCII code 48 represent '0';
        Keyboard.write(10);// Send Enter
        // The ASCII Code of ENTER KEY is 10 in Decimal or 0x0A in Hexadecimal.
      }
    } else {
      buttonLock[i] = 0;
      //該按鈕按下的狀態中斷，重新計算按下狀態
    }
  }

  //test area
  if (buttonState[3] == LOW) {//3號按鈕被按下
    // turn LED on:
    digitalWrite(ledPin, HIGH);
  }
  else {
    // turn LED off:
    digitalWrite(ledPin, LOW);
  }
}
