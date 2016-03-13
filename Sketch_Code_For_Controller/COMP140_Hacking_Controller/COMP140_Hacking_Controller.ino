int xPin = A1;
int yPin = A0;
int buttonPin3 = 1;

// constants won't change. They're used here to
// set pin numbers:
const int buttonPin = 2;     // the number of the pushbutton pin
const int buttonPin2 = 3;     // the number of the pushbutton pin
const int ledPin =  8;      // the number of the LED pin
const int ledPin2 =  9;      // the number of the LED pin
const int ledPin3 =  13; 
const int ledPin4 =  12;
const int ledPin5 =  11;
const int ledPin6 =  10;

// variables will change:
int xPosition = 0;
int yPosition = 0;
int buttonState3 = 0;        // variable for reading the pushbutton status on the joystick
int buttonState = 0;         // variable for reading the pushbutton status
int buttonState2 = 0;         // variable for reading the pushbutton status

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600); 
  
  pinMode(xPin, INPUT);
  pinMode(yPin, INPUT);

  //activate pull-up resistor on the push-button pin
  pinMode(buttonPin3, INPUT_PULLUP); 
  
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
  pinMode(ledPin5, OUTPUT);
  pinMode(ledPin6, OUTPUT);

  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
  pinMode(buttonPin2, INPUT);
}

void loop() {
  // HERE IS THE JOYSTICK LOOP
  xPosition = analogRead(xPin);
  yPosition = analogRead(yPin);
  buttonState3 = digitalRead(buttonPin3);

  Serial.print("X: ");
  Serial.print(xPosition);
  Serial.print(" | Y: ");
  Serial.print(yPosition);
  Serial.print(" | Button: ");
  Serial.println(buttonState);
  
    if (xPosition > 800) {
    // turn LED on:
    digitalWrite(ledPin3, LOW);
  } else {
    // turn LED off:
    digitalWrite(ledPin3, HIGH);
  }
    if (xPosition < 400) {
    // turn LED on:
    digitalWrite(ledPin4, LOW);
  } else {
    // turn LED off:
    digitalWrite(ledPin4, HIGH);
  }
    if (yPosition > 600) {
    // turn LED on:
    digitalWrite(ledPin5, LOW);
  } else {
    // turn LED off:
    digitalWrite(ledPin5, HIGH);
  }
    if (yPosition < 300) {
    // turn LED on:
    digitalWrite(ledPin6, LOW);
  } else {
    // turn LED off:
    digitalWrite(ledPin6, HIGH);
  }

  delay(100); // add some delay between reads
  //END OF JOYSTICK LOOP

  //BUTTON LOOP
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);
  buttonState2 = digitalRead(buttonPin2);

  // check if the pushbutton is pressed.
  // if it is, the buttonState is LOW:
  if (buttonState == HIGH) {
    // turn LED on:
    digitalWrite(ledPin, LOW);
  } else {
    // turn LED off:
    digitalWrite(ledPin, HIGH);
  }
    if (buttonState2 == HIGH) {
    // turn LED on:
    digitalWrite(ledPin2, LOW);
  } else {
    // turn LED off:
    digitalWrite(ledPin2, HIGH);
  }
}

