#include "GreenhouseServer.h"
#include <ESPAsyncWebServer.h>

GreenhouseServer::GreenhouseServer() {}

String sensorData(int temperature, int humidity) {
  String html = "<h1>Greenhouse data</h1>";
  html += "<p>Temperature: " + String(temperature) + " °C</p>";
  html += "<p>Humidity" + String(humidity) + " %";
  return html;
}

void GreenhouseServer::begin(Sensor &sensor) {
  AsyncWebServer server(80);

  server.on("/", HTTP_GET, [&](AsyncWebServerRequest *request) {
    float temperature = sensor.getTemperature();
    float humidity = sensor.getHumidity();

    String sensorDataHtml = sensorData(temperature, humidity);
    String html = "<html><body>";
    html += sensorDataHtml;
    html += "</body></html>";

    request->send(200, "text/html", html);
  });
}