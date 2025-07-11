#include "JsonManager.h"
#include <ArduinoJson.h>
#include <SPI.h>
#include <SD.h>
#include "config.h"

String root = "/ESP32-Hydroponics-Logging";
String currentFile =  "/defaultlog.json";

void initSD(){
    SD.begin(CSPin);
    
}

String listFiles() {
    File openSD = SD.open(root);
    String fileList = "{";
    while (true){
        File entry = openSD.openNextFile();
        if (!entry) {
            fileList += "}";
            break;
        }
        fileList += "\"" + String(entry.name()) + "\"" + ",";
        entry.close();
    }

    return fileList;
}

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



void writeJSON(HydroData sensorData) {
  File logFile = SD.open(root + currentFile, FILE_READ);
  JsonDocument doc;  // adjust size if needed
  // Create JSON from sensor data
  JsonDocument data;
  deserializeJson(data, createJson(sensorData));

  // Create new entry with millis as key
  JsonObject newEntry = doc.createNestedObject(String(millis()));
  for (JsonPair kv : data.as<JsonObject>()) {
    newEntry[kv.key()] = kv.value();
  }

  // Write updated doc back to file
  logFile = SD.open(root + currentFile, FILE_WRITE);
  if (logFile) {
    serializeJson(doc, logFile);
    logFile.println();
    logFile.close();
    Serial.println("Data written.");
  } 
  else {
    Serial.println("Failed to open file for writing.");
  }
}

String readJSON(String filename) {
  File logFile = SD.open(root + filename, FILE_READ);
  String JsonData = "[";

  while (logFile.available()){
    String line = logFile.readStringUntil('\n');

    if (line.length() == 0) continue;

    JsonDocument dataHolder;
    DeserializationError error = deserializeJson(dataHolder, line);

    if (!error){
      String JsonLine;
      serializeJson(dataHolder, JsonLine);
      JsonData += JsonLine + ",";
    }
    
  }
  if (JsonData.endsWith(",")){
      JsonData.remove(JsonData.length() - 1);
    }
  JsonData += "]";
  return JsonData;
}

void writetoJson(String filename){
  currentFile = "/" + filename;
}

String createNewFile(String filename) {
  if (!SD.exists(root + filename)){
    File newFile = SD.open(root + filename, FILE_WRITE);
      if (newFile){
        newFile.close();
        return "OK";
      }
      else {
        return "NO";
      }
  }
  else{
    return "EXIST";
  }
}
