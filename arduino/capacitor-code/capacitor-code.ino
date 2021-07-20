#include <CapacitiveSensor.h>

CapacitiveSensor Sensor = CapacitiveSensor(7, 5); //7 is charge pin.  5 is sense pin.
long sum = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  sum = 0;
  for (int i = 0; i < 1000; i++) {
    long sensorValue = Sensor.capacitiveSensor(1000);      //Change the number of samples to get the required timing and sensitivity.
    //delay(10);
    sum += sensorValue;
    delay(1);
  }
  Serial.println(sum / 1000);
}
