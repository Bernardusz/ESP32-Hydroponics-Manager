#include "PHMeter.h"
#include <Arduino.h>
#include "config.h"

float pHSlope;
float pHOffset;

void calibratePH(float v1, float v2, float pH1, float pH2) {
    pHSlope = (pH2 - pH1) / (v2 - v1);
    pHOffset = pH1 - (pHSlope * v1);
}
void readPH(float& pHValue, float& rawValue, float& voltage) {
    rawValue = analogRead(pHPIN);
    voltage = rawValue * 3.3 / 4096.0;

    pHValue = pHSlope * voltage + pHOffset;
}
void averagePH(float& pHValue, float& rawValue, float& voltage) {
    float sum = 0;
    float currentpH;

    for (int i = 0; i < 10; i++){
        readPH(currentpH, rawValue, voltage);
        sum += currentpH;
    }
    pHValue = sum / 10;
}