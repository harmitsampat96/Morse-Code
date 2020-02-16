/*
  CMSC838J Assignment 2: Morse Code
  Author: Harmit Sampat 2020
  https://harmitsampat.com
*/
const int ledPin = 2;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin D2 as an output.
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {

  if (Serial.available() > 0) {
    
    // reading input
    int incomingByte = Serial.parseInt();

    // separating digits
    int num4 = incomingByte % 10;
    int num3 = (incomingByte / 10) % 10;
    int num2 = (incomingByte / 100) % 10;
    int num1 = (incomingByte / 1000) % 10;

    // sequentially displaying output for each digit
    blink(num1);
    blink(num2);
    blink(num3);
    blink(num4);
  }
}

void space() {
  digitalWrite(ledPin, LOW);    // turn the LED off by making the voltage LOW
  delay(100);
}

void dot(int val) {
  
  for(int i = 0; i < val; i++) {
    digitalWrite(ledPin, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(100);
    space();  
  }
}

void dash(int val) {
  for(int i = 0; i < val; i++) {
    digitalWrite(ledPin, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(300);                   // wait for a 300ms
    space();
  } 
}

void blink(int incomingByte) {

  Serial.println(incomingByte);
  
  switch (incomingByte) {
  case 1:
    dot(1); // output morse code for 1
    dash(4);
    break;
  case 3:
    dot(3); // output morse code for 3
    dash(2);
    break;
  case 4:
    dot(4); // output morse code for 4
    dash(1);
    break;
  case 5:
    dot(5); // output morse code for 5
    break;
  }

  space(); space();
}
