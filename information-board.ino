#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESPAsyncTCP.h>
#include <ESPAsyncWebServer.h>

AsyncWebServer server(80);

void setup() {

  Serial.begin(115200);
  Serial.println();

  JsonArray adverts = fileAdapter.loadAdverts();

  WiFi.disconnect(true);
  WiFi.mode(WIFI_AP);

  Serial.print("Setting soft-AP configuration ... ");
  Serial.println(WiFi.softAPConfig(localIp, gateway, subnet) ? "Ready" : "Failed!");

  Serial.print("Setting soft-AP ... ");
  Serial.println(WiFi.softAP("Information-Board") ? "Ready" : "Failed!");

  Serial.print("Soft-AP IP address = ");
  Serial.println(WiFi.softAPIP());

  // Initialize SPIFFS
  if (!SPIFFS.begin()) {
    Serial.println("An Error has occurred while mounting SPIFFS");
    return;
  }

  //Tutaj obsługiwane są requuesty, poniższy zwraca plik index.html z pamięci urządzenia
  server.on("/", HTTP_GET, [](AsyncWebServerRequest * request) {
    request->send(SPIFFS, "/index.html");
    Serial.println("Index.html GET Request");
  });

  //Ten endpoint odpowiada za zwrócenie listy wszystkich ogłoszeń w formacie JSON
  //(wraca z pamięci podręcznej, ale wszystkie ogłoszenia zapisywane/modyfikowane są równiez w pliku adverts.json - dostępne są po restartie urządzenia)
  server.on("/advert", HTTP_GET, [](AsyncWebServerRequest * request) {
    Serial.println("Adverts GET Request");
    AsyncResponseStream *response = request->beginResponseStream("application/json");
    serializeJson(fileAdapter.advertsArray, *response);
    request->send(response);
  });

  //Zwraca kaskadowy arkusz stylów z pamięci urządzenia
  server.on("/main.css", HTTP_GET, [](AsyncWebServerRequest * request) {
    request->send(SPIFFS, "/main.css");
    Serial.println("main.css Request");
  });

  //Zwraca js idk co to xD (pytać Karola)
  server.on("/resources.js", HTTP_GET, [](AsyncWebServerRequest * request) {
    request->send(SPIFFS, "/resources.js");
    Serial.println("resources.js Request");
  });

  //Zwraca js, zapewne logika frontendu
  server.on("/main.js", HTTP_GET, [](AsyncWebServerRequest * request) {
    request->send(SPIFFS, "/main.js");
    Serial.println("main.js Request");
  });


  //Endpoint umożliwiający dodanie nowego ogłoszenia
  //Wymagane pola: title, body, password (trzeba by zrobić ich validacje, aktualnie tylko sprawdza, czy są w requescie)
  server.on("/advert", HTTP_PUT, [](AsyncWebServerRequest * request) {
    
  });

  //Endpoint służący do edycji ogłoszenia
  //Wymagane pola: id,title, body, password (rówież rzydała by się validacja)
  server.on("/advert", HTTP_PATCH, [](AsyncWebServerRequest * request) {
    
  });

  //Endpoint służący do usuwania ogłoszenia
  //Wymagane pola: id, password
  server.on("/advert", HTTP_DELETE, [](AsyncWebServerRequest * request) {
    
  });
  server.begin();
}

// the loop function runs over and over again forever
void loop() {

}
