#include <Arduino.h>
#include "TDS.h"
#include <config.h>
const float temporaryTemp = 29.8;
void readTDS(float& tdsValue, float& voltage, float temp, float& rawValue){
    rawValue = analogRead(tdsPIN);
    voltage = rawValue * 3.3 / 4096.0;
    float rawTDSValue = (133.42 * pow(voltage, 3)
                    - 255.86 * pow(voltage, 2)
                    + 857.39 * voltage) * TDS_COEFFICIENT;

    // Temperature compensation
    tdsValue = rawTDSValue * (1.0 + 0.02 * (temp - 25));

}