#include <Arduino.h>
#include "WaterLevel.h"
#include <config.h>

void readWaterLevel(float& waterLevel){
    waterLevel = analogRead(waterLevelPin);
}

void checkLoworHigh(float waterLevel, bool& needRefil){
    if (waterLevel >= 50){
        needRefil = false;
    }
    else {
        needRefil = true;
    }
}