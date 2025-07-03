#include <Arduino.h>
#include <TDS.h>
#include <DHTSensor.h>
#include <WaterLevel.h>

float temp;
float humidity;
float tdsValue;
float voltage;
float rawValue;
float waterLevel;
bool needRefil;

void setup() {
  // put your setup code here, to run once:
  initDHT22();
  Serial.begin(115200);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  readDHT22(temp, humidity);
  readTDS(tdsValue, voltage, temp, rawValue);
  readWaterLevel(waterLevel);
  checkLoworHigh(waterLevel, needRefil);
  
  Serial.print("TDS Value : ");
  Serial.print(tdsValue);

  Serial.print(" | ");

  Serial.print("Voltage : ");
  Serial.print(voltage);

  Serial.print(" | ");
  
  Serial.print("Raw Value : ");
  Serial.print(rawValue);

  Serial.println(" | ");

  Serial.print("Temp : ");
  Serial.print(temp);

  Serial.print(" | ");

  Serial.print("Humidity : ");
  Serial.println(humidity);

  Serial.println(" | ");
  
  Serial.print("Water Level : ");
  Serial.print(waterLevel);

  Serial.print(" | ");

  Serial.print("Need Refil : ");
  Serial.println(needRefil);
  Serial.println("=========================");
  delay(4000);
}


