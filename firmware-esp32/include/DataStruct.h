#ifndef DATASTRUCT_H
#define DATASTRUCT_H
#include <Arduino.h>

struct HydroData{
  float temp;
  float humidity;
  float tdsValue;
  float voltageTDS;
  float rawValueTDS;
  float waterLevel;
  bool needRefil;
  float voltagePH;
  float rawValuePH;
  float pHValue;

};

#endif