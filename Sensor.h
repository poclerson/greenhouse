#ifndef SENSOR_H
#define SENSOR_H

#include <DHT.h>

#define SENSOR_PIN 5
#define SENSOR_TYPE DHT22

class Sensor {
  public:
    Sensor(int pin = SENSOR_PIN, int type = SENSOR_TYPE);
    void begin();
    float getTemperature();
    float getHumidity();
  private:
    DHT sensor;
};

#endif