#include <DHT.h>
#include "Sensor.h"

Sensor::Sensor(int pin, int type): sensor(pin, type) {}

void Sensor::begin() {
  sensor.begin();
}

float Sensor::getTemperature() {
  return sensor.readTemperature();
}

float Sensor::getHumidity() {
  return sensor.readHumidity();
}