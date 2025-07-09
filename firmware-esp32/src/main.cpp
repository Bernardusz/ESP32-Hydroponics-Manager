#include <Arduino.h>
#include "TDS.h"
#include "DHTSensor.h"
#include "WaterLevel.h"
#include "DataStruct.h"
#include "JsonManager.h"
#include "CommFlask.h"

HydroData sensorData;

unsigned long previousMillisRead = 0;
unsigned long previousMillisSend = 0;
const long intervalRead = 2000;
const long intervalSendData = 5000;

void serialPrint();

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  initWifi();
  initDHT22();
  
  
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillisRead >= intervalRead){
    previousMillisRead = currentMillis;
    readDHT22(sensorData.temp, sensorData.humidity);
    readAverageTDS(sensorData.tdsValue, sensorData.voltage, 
            sensorData.temp, sensorData.rawValue);
    readWaterLevel(sensorData.waterLevel);
    checkLoworHigh(sensorData.waterLevel, sensorData.needRefil);
    serialPrint();
  }
  

  String jsonData = createJson(sensorData);
  castingData(jsonData);
  
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
