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
extern const int pHPIN;
extern const int CSPin;

struct PPMnVoltage {
    const float V1;    // Air Isi Ulang
    const float V2;    // Tap Water
    const float V3;    // Low Nutrient
    const float V4;    // Medium Nutrient
    const float V5;    // High Nutrient
    const float V6;    // Overclock

    const float PPM1;
    const float PPM2;
    const float PPM3;
    const float PPM4;
    const float PPM5;
    const float PPM6;

};

struct pHSetup {
    const float voltage1;
    const float voltage2;

    const float pH1;
    const float pH2;
};




#endif
