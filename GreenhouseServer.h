#ifndef GREENHOUSESERVER_H
#define GREENHOUSESERVER_H

#include "Sensor.h"

class GreenhouseServer {
  public:
    GreenhouseServer();
    void begin(Sensor &sensor);
  // private:
  //   String sensorData(int temperature, int humidity);
};

#endif