#include "JsonManager.h"
#include <ArduinoJson.h>

String createJson(HydroData sensorData){
    JsonDocument doc;

    doc["temp"] = sensorData.temp;
    doc["humidity"] = sensorData.humidity;
    doc["tds"] = sensorData.tdsValue;
    doc["pH"] = "Placeholder";
    doc["Need_refil"] = sensorData.needRefil;

    String output;
    serializeJson(doc, output);
    return output;
}