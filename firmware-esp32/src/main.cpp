#include <Arduino.h>
#include <TDS.h>

float tdsValue;
float voltage;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

}

void loop() {
  // put your main code here, to run repeatedly:
  readTDS(tdsValue, voltage);
  Serial.print("TDS Value : ");
  Serial.println(tdsValue);
  Serial.print("Voltage : ");
  Serial.println(voltage);
  Serial.println("=========================");
  delay(2000);
}


