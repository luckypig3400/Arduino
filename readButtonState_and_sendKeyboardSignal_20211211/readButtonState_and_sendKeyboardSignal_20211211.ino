/* REF:
+ https://forum.arduino.cc/t/using-analog-pins-for-push-buttons/309407
+ https://www.arduino.cc/reference/en/language/functions/usb/keyboard/keyboardwrite/

*/
// constants won't change. They're used here to set pin numbers:
const int buttonPin1 = A1;
const int buttonPin2 = A2;
const int buttonPin3 = A3; // the number of the pushbutton pin
const int buttonPin4 = A4;
const int buttonPin5 = A5;
const int ledPin =  LED_BUILTIN; // the number of the LED pin

// variables will change:
int buttonState3 = 0; // variable for reading the pushbutton status

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);      
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(buttonPin3, INPUT);
  pinMode(buttonPin4, INPUT);
  pinMode(buttonPin5, INPUT);
  Serial.begin(9600);
}

void loop(){
  // read the state of the pushbutton value:
  buttonState3 = digitalRead(buttonPin3);
  Serial.println(buttonState3);
  
  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if (buttonState3 == LOW) {
    // turn LED on:    
    digitalWrite(ledPin, HIGH); 
  } 
  else {
    // turn LED off:
    digitalWrite(ledPin, LOW); 
  }
}
