#include <Arduino.h>
#include "TDS.h"
#include "DHTSensor.h"
#include "WaterLevel.h"
#include "DataStruct.h"
#include "JsonManager.h"
#include "CommFlask.h"
#include "PHMeter.h"
#include "config.h"

HydroData sensorData;
extern pHSetup datapH;

unsigned long previousMillisRead = 0;
unsigned long previousMillisSend = 0;
const long intervalRead = 2000;
const long intervalSendData = 5000;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  initWifi();
  initDHT22();
  calibratePH(datapH.voltage1, datapH.voltage2, 
              datapH.pH1, datapH. pH2);
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillisRead >= intervalRead){
    previousMillisRead = currentMillis;
    readDHT22(sensorData.temp, sensorData.humidity);
    readAverageTDS(sensorData.tdsValue, sensorData.voltageTDS, 
            sensorData.temp, sensorData.rawValueTDS);
    readWaterLevel(sensorData.waterLevel);
    checkLoworHigh(sensorData.waterLevel, sensorData.needRefil);
    averagePH(sensorData.pHValue, sensorData.rawValuePH, sensorData.voltagePH);
  }
  

  String jsonData = createJson(sensorData);
  castingData(jsonData);
  
}

