/* 
Pushup Counter 
Stephen Low
Wearable Computing GDES-3015-001 
OCAD University 
Created on March 23, 2017 
Based on: 
 Mapping example, Kate Hartman, https://github.com/katehartman/Make-Wearable-Electronics/blob/master/MWE_Ch07_Mapping/MWE_Ch07_Mapping.ino
Boolean, Arduino, https://www.arduino.cc/en/reference/boolean
Arduino – Using a Sharp IR Sensor for Distance Calculation, Larry, http://luckylarry.co.uk/arduino-projects/arduino-using-a-sharp-ir-sensor-for-distance-calculation/
*/

// initialize variable for sensor reading
int SensorValue = 0;
int SensorValue2 = 0;
// initialize variable for sensor pin
int SensorPin = A1;
int SesnorPin2 = A2;
// initialize variable for mapped sensor value
int mappedSensorValue = 0;
//initialize variable for outputs
int GreenLEDPin= 13;
int RedLEDPin=12;
int prev = 0;


void setup() {
  // initialize serial communication at 9600 bps 
  Serial.begin(9600);
}

void loop() {
  // read pin and store value in a variable: 
  SensorValue = analogRead(SensorPin); 

  SensorValue2 = analogRead(A2);
  // map sensor value to match relative distance range
  mappedSensorValue = map(SensorValue, 0, 1023, 30, 0);
  
//if the person is not facing the ground (not exposed to enough light), sensors are off
if (SensorValue2 >600){
  digitalWrite (GreenLEDPin, LOW);
  digitalWrite (RedLEDPin, LOW);
  delay(1000);
}

//else if the person is facing the ground (light sensor is covered), the motion sensor is responsive
if (mappedSensorValue <= 15){
    digitalWrite(GreenLEDPin, HIGH);
    digitalWrite(RedLEDPin, LOW);
}

int val = mappedSensorValue;
// if sensor value is between 15 and 21, with a value that is greating then the previous it plays the beep
if (mappedSensorValue >15 && mappedSensorValue <21 && val >prev){
    digitalWrite(RedLEDPin, HIGH);
    delay(500);
    digitalWrite(RedLEDPin, LOW);
}

  // print the values to serial monitor: 
  Serial.print("Sensor Value: ");
  Serial.print(SensorValue);
  Serial.print(", Mapped Sensor Value: ");
  Serial.print(mappedSensorValue);
  Serial.print(", Sensor Value2:");
  Serial.println(SensorValue2);
  // delay between readings:
  delay(100);
}
