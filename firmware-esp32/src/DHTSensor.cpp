#include <DHT.h>

const int DHTPIN = 15;
#define DHTTYPE DHT22
// put function declarations here:
DHT dht(DHTPIN, DHTTYPE);

void initDHT22() {
  dht.begin();
}

void readDHT22(float& temp, float& humidity) {
  // put your main code here, to run repeatedly:
  float temperatureRead = dht.readTemperature();
  float humidityRead = dht.readHumidity();

  temp = temperatureRead;
  humidity = humidityRead;
}