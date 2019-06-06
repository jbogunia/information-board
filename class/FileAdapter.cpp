#include <ArduinoJson.h>
#include "FS.h"
#include "ErrorResponse.cpp"

class FileAdapter {

private:
    FileAdapter();
    bool saveAdvertsToJson();

public:
    JsonArray loadAdverts();
    ErrorResponse saveAdvert(JsonObject newAdvert);
    ErrorResponse removeAdvert(int id, String advertPassword);
    ErrorResponse editAdvert(int id, String title, String body, String password);
    char getAdverts();
    int getAdvertIndex(int advertId);
    static FileAdapter& getInstance();
    StaticJsonDocument<2000> arrayDoc;
    JsonObject rootObject;
    JsonArray advertsArray;
	  ~FileAdapter();
};

FileAdapter::FileAdapter () {
    SPIFFS.begin();
    Serial.println("File adapter initialized ... Ready");
    this->rootObject = this->arrayDoc.to<JsonObject>();
    this->advertsArray = this->rootObject.createNestedArray("adverts");
};

FileAdapter& FileAdapter::getInstance() {
  static FileAdapter instance;
  return instance;
}

FileAdapter::~FileAdapter() {
    this->arrayDoc.clear();
}

JsonArray FileAdapter::loadAdverts() {

}

bool FileAdapter::saveAdvertsToJson(){

}

ErrorResponse FileAdapter::saveAdvert(JsonObject newAdvert) {

}

int FileAdapter::getAdvertIndex(int advertId){

}

ErrorResponse FileAdapter::removeAdvert(int id, String advertPassword){
  
}

ErrorResponse FileAdapter::editAdvert(int id, String title, String body, String password){
  
}
