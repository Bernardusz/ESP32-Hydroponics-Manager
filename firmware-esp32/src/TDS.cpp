#include <Arduino.h>
#include "TDS.h"
#include "config.h"

extern PPMnVoltage dataPPMnVoltage;

void readTDS(float& tdsValue, float& voltage, float temp, float& rawValue) {
    rawValue = analogRead(tdsPIN);
    voltage = rawValue * 3.3 / 4096.0;

    float A, B;

    // Define ranges and coefficients based on config.h values
    if (voltage >= dataPPMnVoltage.V1 && voltage < dataPPMnVoltage.V2) {
        A = (dataPPMnVoltage.PPM2 - dataPPMnVoltage.PPM1) / 
            (dataPPMnVoltage.V2 - dataPPMnVoltage.V1);
        B = dataPPMnVoltage.PPM1 - (A * dataPPMnVoltage.V1);
    } else if (voltage >= dataPPMnVoltage.V2 && voltage < dataPPMnVoltage.V3) {
        A = (dataPPMnVoltage.PPM3 - dataPPMnVoltage.PPM2) / 
            (dataPPMnVoltage.V3 - dataPPMnVoltage.V2);
        B = dataPPMnVoltage.PPM2 - (A * dataPPMnVoltage.V2);
    } else if (voltage >= dataPPMnVoltage.V3 && voltage < dataPPMnVoltage.V4) {
        A = (dataPPMnVoltage.PPM4 - dataPPMnVoltage.PPM3) / 
            (dataPPMnVoltage.V4 - dataPPMnVoltage.V3);
        B = dataPPMnVoltage.PPM3 - (A * dataPPMnVoltage.V3);
    } else if (voltage >= dataPPMnVoltage.V4 && voltage < dataPPMnVoltage.V5) {
        A = (dataPPMnVoltage.PPM5 - dataPPMnVoltage.PPM4) / 
            (dataPPMnVoltage.V5 - dataPPMnVoltage.V4);
        B = dataPPMnVoltage.PPM4 - (A * dataPPMnVoltage.V4);
    } else if (voltage >= dataPPMnVoltage.V5 && voltage <= dataPPMnVoltage.V6) {
        A = (dataPPMnVoltage.PPM6 - dataPPMnVoltage.PPM5) / 
            (dataPPMnVoltage.V6 - dataPPMnVoltage.V5);
        B = dataPPMnVoltage.PPM5 - (A * dataPPMnVoltage.V5);
    } else if (voltage >= dataPPMnVoltage.V6) {
        // Optional: linear projection beyond V6
        A = 0.0;
        B = 0.0;
        
    }

    float rawTDSValue = A * voltage + B;

    // Temperature compensation
    tdsValue = rawTDSValue * (1.0 + 0.02 * (temp - 25));
}

void readAverageTDS(float& tdsValue, float& voltage, float temp, float& rawValue){
    float sum = 0;
    float currentTDS;
    
    for (int i = 0; i < 10; i++){
        readTDS(currentTDS, voltage, temp, rawValue);
        sum += currentTDS;
    }
    tdsValue = sum / 10;
}