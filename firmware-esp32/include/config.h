#ifndef CONFIG_H
#define CONFIG_H

#include <Arduino.h>

extern const float TDS_COEFFICIENT;
extern const int tdsPIN;
extern const int DHTPIN;
#define DHTTYPE DHT22
extern const int waterLevelPin;
extern const char* ssid;
extern const char* password;

#endif
