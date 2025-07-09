#include "config.h"

const float TDS_COEFFICIENT = 0.37;
const int tdsPIN = 34;
const int DHTPIN = 17;
const int waterLevelPin = 33;
const char* ssid = "ESP32-Hydroponics";
const char* password = "SecretAF123";
const int pHPIN = 35;

PPMnVoltage dataPPMnVoltage = {0.32, 0.63, 1.80, 1.85, 2.17, 2.23, 64, 127, 697, 965, 1230, 1800};