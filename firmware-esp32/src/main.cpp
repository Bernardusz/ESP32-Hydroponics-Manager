#include <Arduino.h>
#include <DHTSensor.h>
// put function declarations here:

float temp;
float humidity;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  initDHT22();
}

void loop() {
  // put your main code here, to run repeatedly:
  readDHT22(temp, humidity);
  Serial.print("Temp : ");
  Serial.print(temp);
  Serial.print(" | ");
  Serial.print("Humidity");
  Serial.println(humidity);

  delay(2000);

}

// put function definitions here:
