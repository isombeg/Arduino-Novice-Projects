const int sensorPin = A0; // analog pin A0 connects to temp sensor
const float baselineTemp = 17.0;

void setup() {
  Serial.begin(9600);
  
  // Setting digital pins 2 through 4 as OUTPUT
  for(int pinNumber = 2; pinNumber<5; pinNumber++){
    pinMode(pinNumber, OUTPUT);
    digitalWrite(pinNumber, LOW);
  }

}

void loop() {
  int sensorVal = analogRead(sensorPin); // store reading from temp sensor in sensorVal
  Serial.print("Sensor Value: "); Serial.print(sensorVal); // print the temp sensor value to Serial monitor
  
  float voltage = (sensorVal/1024.0) * 5.0; // calculate voltage consumed by temp sensor
  Serial.print(" Voltage: "); Serial.print(voltage); // print temp sensor voltage to Serial monitor
  
  float temperature = (voltage - 0.5) * -100; // calculate temp from voltage of the temp sensor
  Serial.print(" Temperature: "); Serial.println(temperature); // print temp to Serial monitor

  // if room temp is lesser than the baselineTemp, no LEDs light up
  if(temperature < baselineTemp){
    for(int pinNumber = 2; pinNumber<5; pinNumber++){
       digitalWrite(pinNumber, LOW);
    }
  }
  
  // if room temp is between 2 and 4 degrees above baselineTemp: one LED lights up
  else if(temperature >= baselineTemp+2 && temperature < baselineTemp+4){
    digitalWrite(2, HIGH); digitalWrite(3, LOW); digitalWrite(4,LOW);
  }
  
  // if room temp is between 4 and 6 degrees above baselineTemp: two LEDs light up
  else if(temperature >= baselineTemp+4 && temperature < baselineTemp+6){
    digitalWrite(2, HIGH); digitalWrite(3, HIGH); digitalWrite(4, LOW);
  }
  
  // if room temp is exceed 6 degrees above baselineTemp: all LEDs light up
  else if(temperature >= baselineTemp+6){
    for(int pinNumber = 2; pinNumber < 5; pinNumber++){
      digitalWrite(pinNumber, HIGH);
    }
  }
    

}
