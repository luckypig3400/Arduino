int ledPin = 12;
int buttonPin = 2;
int buttonState = 0;         
// variable for reading the pushbutton status

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin,OUTPUT);
  pinMode(buttonPin,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonState = digitalRead(buttonPin);
  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if (buttonState == HIGH) {    
    // turn LED on:   
    digitalWrite(ledPin, HIGH); 
  }
  else {
    // turn LED off:
    digitalWrite(ledPin, LOW);
  }
}
