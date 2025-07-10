#ifndef PHMETER_H
#define PHMETER_H

void calibratePH(float v1, float v2, float pH1, float pH2);
void readPH(float& pHValue, float& rawValue, float& voltage);
void averagePH(float& pHValue, float& rawValue, float& voltage);

#endif