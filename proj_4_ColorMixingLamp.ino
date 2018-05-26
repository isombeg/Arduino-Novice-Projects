const int RED_LED = 11; // pin 11 will power red LED
const int BLUE_LED = 10; // pin 10 will power blue LED
const int GREEN_LED = 9; // pin 9 will power green LED

const int PHOTO_RES_RED = A0; 
const int PHOTO_RES_GREEN = A1;
const int PHOTO_RES_BLUE = A2;

// Varialbles that will store data from the photoresistors
int photoReadRed = 0;
int photoReadGreen = 0;
int photoReadBlue = 0;

int redVal = 0;
int greenVal = 0;
int blueVal = 0;

void setup() {
  Serial.begin(9600);
  // set digital pin 9 to 11 as output
  for (int pinNumber = 9; pinNumber<12; pinNumber++){
    pinMode(pinNumber, OUTPUT);
  }

}

void loop() {
  photoReadRed = analogRead(PHOTO_RES_RED); // collect data from first photoresistor on A0
  delay(5);
  photoReadGreen = analogRead(PHOTO_RES_GREEN); // collect data from second photoresistor on A1
  delay(5);
  photoReadBlue = analogRead(PHOTO_RES_BLUE); // collect data from third photoresistor on A2

  // Display photoresitor readings on Serial monitor
  Serial.print("Raw Sensor Values \t Red: "); Serial.print(photoReadRed);
  Serial.print("\t Green: "); Serial.print(photoReadGreen);
  Serial.print("\t Blue: "); Serial.println(photoReadBlue);

  // Determining duty cycle for LEDs and storing them within folloing variables
  redVal = photoReadRed/4;
  greenVal = photoReadGreen/4;
  blueVal = photoReadBlue/4;
  
  // Use PWM while lighting up LEDs with previously determined duty cycles
  analogWrite(RED_LED, redVal);
  analogWrite(GREEN_LED, greenVal);
  analogWrite(BLUE_LED, blueVal);

  // Display duty cycles on Serial Monitor
  Serial.print("LED Light Levels \t");
  Serial.print("Red: "); Serial.print(redVal);
  Serial.print("\t Green: "); Serial.print(greenVal);
  Serial.print("\t Blue: "); Serial.println(blueVal);

}
