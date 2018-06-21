#include <Servo.h>
Servo myServo;

const int POTENT_PIN = A0;
float potentRead = 0;
int servoAngle = 0;

void setup() {
  myServo.attach(9);
  
  Serial.begin(9600);

}

void loop() {
  potentRead = analogRead(POTENT_PIN);
  Serial.print("Potentiometer value: "); Serial.print(potentRead);
  servoAngle = map(potentRead, 0,1023,0,179);
  Serial.print("'\t Servo Angle: "), Serial.println(servoAngle);
  myServo.write(servoAngle);
  delay(15);

}
