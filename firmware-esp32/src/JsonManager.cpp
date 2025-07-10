#include "JsonManager.h"
#include <ArduinoJson.h>

String createJson(HydroData sensorData){
    JsonDocument doc;

    doc["temp"] = sensorData.temp;
    doc["humidity"] = sensorData.humidity;
    doc["tds"] = sensorData.tdsValue;
    doc["pH"] = sensorData.pHValue;
    doc["Need_refil"] = sensorData.needRefil;
    doc["voltageTDS"] = sensorData.voltageTDS;
    doc["rawValuePH"] = sensorData.rawValuePH;
    doc["voltagePH"] = sensorData.voltagePH;

    String output;
    serializeJson(doc, output);
    return output;
}