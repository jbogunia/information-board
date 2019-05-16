#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESPAsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include "FS.h"

AsyncWebServer server(80);

IPAddress localIp(192, 168, 1, 1);
IPAddress gateway(192, 168, 1, 1);
IPAddress subnet(255, 255, 255, 0);

void setup()
{

  Serial.begin(115200);
  Serial.print();

  WiFi.disconnect(true);
  WiFi.mode(WIFI_AP);

  Serial.print("Setting soft-AP configuration ... ");
  Serial.print(WiFi.softAPConfig(localIp, gateway, subnet) ? "Ready\n" : "Failed!\n");

  Serial.print("Setting soft-AP ... ");
  Serial.print(WiFi.softAP("teest") ? "Ready\n" : "Failed!\n");

  Serial.print("Soft-AP IP address = ");
  Serial.print(WiFi.softAPIP());

  // Initialize SPIFFS
  if (!SPIFFS.begin())
  {
    Serial.print("An Error has occurred while mounting SPIFFS\n");
    return;
  }
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send(SPIFFS, "/index.html");
    Serial.print("Index.html Request\n");
  });
  server.on("/posts", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send(SPIFFS, "/adverts.json", "application/json");
    Serial.print("Adverts Request\n");
  });
  server.on("/main.css", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send(SPIFFS, "/main.css");
    Serial.print("main.css Request\n");
  });
  server.on("/resources.js", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send(SPIFFS, "/resources.js");
    Serial.print("resources.js Request\n");
  });
  server.on("/main.js", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send(SPIFFS, "/main.js");
    Serial.print("main.js Request\n");
  });
  server.on("/information", HTTP_PUT, [](AsyncWebServerRequest *request) {
    request->send(SPIFFS, "/index.html");
    Serial.print("Information add request\n");
  });
  server.on("/information", HTTP_DELETE, [](AsyncWebServerRequest *request) {
    request->send(SPIFFS, "/index.html");
    Serial.print("Information remove request\n");
  });
  server.begin();
}

// the loop function runs over and over again forever
void loop()
{
}
