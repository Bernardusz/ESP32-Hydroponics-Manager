#include <Arduino.h>
#include "TDS.h"
#include <config.h>

void readTDS(float& tdsValue, float& voltage, float temp){
    int rawValue = analogRead(tdsPIN);
    float voltage = rawValue * 3.3 / 4096.0;

    float tdsValue = (133.42 * pow(voltage, 3)
                    - 255.86 * pow(voltage, 2)
                    + 857.39 * voltage) * TDS_COEFFICIENT;

    // Temperature compensation
    tdsValue = tdsValue * (1.0 + 0.02 * (temp - 25));

}