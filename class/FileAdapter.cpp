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
    File adverts = SPIFFS.open("/adverts.json", "r");
    if (!adverts) {
        Serial.println("Reading adverts file failure...");
        return this->advertsArray;
    }

    adverts.setTimeout(5000);

    size_t size = adverts.size();
    Serial.print("Adverts file size: ");
    Serial.println(size);
    if (size == 0) {
        Serial.println("Adverts file is empty!");
        return this->advertsArray;
    }

    DynamicJsonDocument doc(400);

    adverts.find("\"adverts\":[");
    do {
        DeserializationError err = deserializeJson(doc, adverts);
        if (err) {
            Serial.print(F("deserializeJson() failed: "));
            Serial.println(err.c_str());
        }
        JsonObject object = doc.as<JsonObject>();
        this->advertsArray.add(object);
    } while (adverts.findUntil(",", "]"));
    serializeJsonPretty(this->rootObject, Serial);
    adverts.close();
    return this->advertsArray;
}

bool FileAdapter::saveAdvertsToJson() {
    File advertsFile = SPIFFS.open("/adverts.json", "w");
    if (!advertsFile) {
        Serial.println("Problem with opening adverts.json file");
        return false;
    }

    Serial.println("");
    Serial.println("Saving adverts to json file...");

    serializeJson(this->rootObject, advertsFile);
    serializeJsonPretty(this->rootObject, Serial);
    advertsFile.close();
    return true;
}

ErrorResponse FileAdapter::saveAdvert(JsonObject newAdvert) {
  int id = 0;
  Serial.print("Adverts count: ");
  Serial.println(this->advertsArray.size());
  if(this->advertsArray.size() > 0) {
    id = (int) this->advertsArray.getElement(this->advertsArray.size()-1)["id"];
    id++;
  }

  newAdvert["id"] = id;
  this->advertsArray.add(newAdvert);

  if(this->saveAdvertsToJson()){
      ErrorResponse response(200, "Advert saved");
      return response;
  } else {
      ErrorResponse response(500, "Something went wrong  :(");
      return response;
  }
}

int FileAdapter::getAdvertIndex(int advertId) {
  int index=0;
  Serial.print("Finding ");
  Serial.print(advertId);
  Serial.println(" advert");
  for (JsonObject advert : this->advertsArray) {
    JsonVariant variant = advert.getMember("id");
    int id = variant.as<int>();
      if(id == advertId){
        Serial.print("Advert found on ");
        Serial.print(index);
        Serial.println(" position");
        return index;
      }
      index++;
  }
  return -1;
}

/**
 * Remove advert
 * @param id - advert id
 * @param advertPassword - advert password, must match already saved one
 * @return response object with updated advert or error message
 */
ErrorResponse FileAdapter::removeAdvert(int id, String advertPassword) {
    int index = this->getAdvertIndex(id);
    if(index != -1){
        Serial.print("Removing advert on ");
        Serial.print(index);
        Serial.println(" position in array");
        JsonVariant variant = this->advertsArray.getElement(index);
        Serial.println(variant.getMember("password").as<String>());
        if(variant.getMember("password").as<String>() == advertPassword){
            this->advertsArray.remove(index);
            ErrorResponse response(200, "Advert removed!");
            return response;
        } else {
            Serial.println("Given password does not match");
            ErrorResponse response(401, "Given password does not match");
            return response;
        }
    } else {
        ErrorResponse response(400, "Given advert not found :(");
        return response;
    }
}

ErrorResponse FileAdapter::editAdvert(int id, String title, String body, String password) {
  int index = this->getAdvertIndex(id);
  if(index != -1){
    Serial.print("Editing advert on ");
    Serial.print(index);
    Serial.println(" position in array");
    JsonVariant variant = this->advertsArray.getElement(index);
	Serial.println(variant.getMember("password").as<String>());
	if(variant.getMember("password").as<String>() == password){
		variant.getMember("title").set(title);
		variant.getMember("body").set(body);
		this->saveAdvertsToJson();
    ErrorResponse response(200, "Advert edited!");
    return response;
	} else {
		Serial.println("Given password does not match");
    ErrorResponse response(401, "Given password does not match");
    return response;
	}
  } else {
    Serial.println("Given advert not found :(");
    ErrorResponse response(400, "Given advert not found :(");
    return response;
  }
}
