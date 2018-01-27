int switchState = 0;
void setup() {
  // The following statements make use of the built-in function pinMode to set whether a pin will be used as input or output
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(2, INPUT);

}

void loop() {
  // Following statement determines whether there is voltage at pin two. digitalRead() returns either HIGH or LOW
  switchState = digitalRead(2);
  // If there is no voltage at pin 2, green LED will be on and red LEDs will be off. Occurs when button is pressed
  if (switchState == LOW) {
    digitalWrite(3, HIGH); //green LED
    digitalWrite(4, LOW); //red LED
    digitalWrite(5, LOW); //red LED
  }
  // If the button is pressed
  else {
    digitalWrite(3, LOW); //green LED
    digitalWrite(4, LOW); //red LED
    digitalWrite(5, HIGH); //red LED

    delay(250); //wait for 0.250 seconds
    // toggle the LEDs
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    delay(250);
  } // iterates through loop again

}

