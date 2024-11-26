#include "Sensor.h"
#include "Display.h"
#include "GreenhouseServer.h"
#include "WiFi.h"

#define WIFI_SSID "La maison du SWAG"
#define WIFI_PASSWORD "1wannak111mys3lf__bruvv"

Sensor sensor;
Display display;
GreenhouseServer webServer;

void setup() {
  Serial.begin(9600);

  sensor.begin();
  display.begin();

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    display.print("Wifi: connecting...");
  }

  display.print("Wifi: " + WiFi.localIP());

  webServer.begin(sensor);
}

void loop() {
  float temperature = sensor.getTemperature();
  float humidity = sensor.getHumidity();

  if (isnan(temperature) || isnan(humidity)) {
    display.printTo("Sensor Error", 1);
  } else {
    display.printTo("Temp: " + String(temperature) + " C", 1);
    display.printTo("Humidity: " + String(humidity) + " %", 2);
  }

  delay(2000);
}