/* REF:
  + https://forum.arduino.cc/t/using-analog-pins-for-push-buttons/309407
  + https://www.arduino.cc/reference/en/language/functions/usb/keyboard/keyboardwrite/

*/
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
}

void loop() {
  String allBtnState;
  for (int i = 1; i < 6; i++) {
    // read the state of the pushbutton value:
    buttonState[i] = digitalRead(buttonPin[i]);
    allBtnState = String(allBtnState + "Btn" + i + ":" + buttonState[i] + "\t");
    // https://www.arduino.cc/reference/en/language/variables/data-types/stringobject/
  }
  Serial.println(allBtnState);

  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if (buttonState[3] == LOW) {
    // turn LED on:
    digitalWrite(ledPin, HIGH);
  }
  else {
    // turn LED off:
    digitalWrite(ledPin, LOW);
  }
}
