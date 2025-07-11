#ifndef JSONMANAGER_H
#define JSONMANAGER_H
#include "DataStruct.h"

void initSD();
String listFiles();
String createJson(HydroData sensorData);
void writeJSON(HydroData sensorData);
String readJSON(String filename);
void writetoJson(String filename);
String createNewFile(String filename);

#endif