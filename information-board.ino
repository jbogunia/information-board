#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESPAsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include "FS.h"

AsyncWebServer server(80);

IPAddress localIp(192, 168, 1, 1);
IPAddress gateway(192, 168, 1, 1);
IPAddress subnet(255, 255, 255, 0);

void setup() {

  Serial.begin(115200);
  Serial.println();

  WiFi.disconnect(true);
  WiFi.mode(WIFI_AP);

  Serial.print("Setting soft-AP configuration ... ");
  Serial.println(WiFi.softAPConfig(localIp, gateway, subnet) ? "Ready" : "Failed!");

  Serial.print("Setting soft-AP ... ");
  Serial.println(WiFi.softAP("teest") ? "Ready" : "Failed!");

  Serial.print("Soft-AP IP address = ");
  Serial.println(WiFi.softAPIP());

  // Initialize SPIFFS
  if (!SPIFFS.begin()) {
    Serial.println("An Error has occurred while mounting SPIFFS");
    return;
  }

  server.on("/", HTTP_GET, [](AsyncWebServerRequest * request) {
    request->send(SPIFFS, "/index.html");
    Serial.println("Information list request");
  });

  server.on("/information", HTTP_PUT, [](AsyncWebServerRequest * request) {
    request->send(SPIFFS, "/index.html");
    Serial.println("Information add request");
  });

  server.on("/information", HTTP_DELETE, [](AsyncWebServerRequest * request) {
    request->send(SPIFFS, "/index.html");
    Serial.println("Information remove request");
  });

  server.begin();
}

// the loop function runs over and over again forever
void loop() {

}
