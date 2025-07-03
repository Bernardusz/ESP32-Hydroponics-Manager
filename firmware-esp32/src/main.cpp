#include <Arduino.h>
#include "TDS.h"
#include "DHTSensor.h"
#include "WaterLevel.h"
#include "DataStruct.h"
#include "JsonManager.h"
#include "CommJava.h"

HydroData sensorData;

unsigned long previousMillis = 0;
const long intervalRead = 2000;
const long intervalSendData = 5000;

void serialPrint();

void setup() {
  // put your setup code here, to run once:
  initWifi();
  initDHT22();
  Serial.begin(115200);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= intervalRead){
    previousMillis = currentMillis;
    readDHT22(sensorData.temp, sensorData.humidity);
    readTDS(sensorData.tdsValue, sensorData.voltage, 
            sensorData.temp, sensorData.rawValue);
    readWaterLevel(sensorData.waterLevel);
    checkLoworHigh(sensorData.waterLevel, sensorData.needRefil);
    serialPrint();
  }
  
  if (currentMillis - previousMillis >= intervalSendData){
    String jsonData = createJson(sensorData);
    castingData(jsonData);
  }
  
  

}

void serialPrint(){
  Serial.print("TDS Value : ");
  Serial.print(sensorData.tdsValue);

  Serial.print(" | ");

  Serial.print("Voltage : ");
  Serial.print(sensorData.voltage);

  Serial.print(" | ");
  
  Serial.print("Raw Value : ");
  Serial.print(sensorData.rawValue);

  Serial.println(" | ");

  Serial.print("Temp : ");
  Serial.print(sensorData.temp);

  Serial.print(" | ");

  Serial.print("Humidity : ");
  Serial.println(sensorData.humidity);

  Serial.println(" | ");
  
  Serial.print("Water Level : ");
  Serial.print(sensorData.waterLevel);

  Serial.print(" | ");

  Serial.print("Need Refil : ");
  Serial.println(sensorData.needRefil);
  Serial.println("=========================");
}
