#ifndef DATASTRUCT_H
#define DATASTRUCT_H
#include <Arduino.h>

struct HydroData{
  float temp;
  float humidity;
  float tdsValue;
  float voltage;
  float rawValue;
  float waterLevel;
  bool needRefil;
};

#endif