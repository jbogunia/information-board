#include <ArduinoJson.h>
#include "FS.h"

class FileAdapter
{

private:
  JsonObject adverts;
};

void FileAdapter::FileAdapter()
{
  SPIFFS.begin();
};

bool FileAdapter::loadAdverts()
{
  File adverts = SPIFFS.open("/adverts.json", "r");
  if (!adverts)
  {
    return false;
  }

  size_t size = adverts.size();
  char *buf = new char[size];

  adverts.readBytes(buf, size);

  StaticJsonBuffer<5000> jsonBuffer;
  JsonObject &json = jsonBuffer.parseObject(buf);

  if (!json.success())
  {
    delete buf;
    return false;
  }

  this->adverts = json["adverts"];

  delete buf;
  configFile.close();
  return true;
}

bool FileAdapter::saveAdvert(JsonObject newAdvert)
{
  StaticJsonBuffer<500> jsonBuffer;
  JsonObject &json = jsonBuffer.createObject();
  json["adverts"] = this->adverts;

  File configFile = SPIFFS.open("/adverts.json", "w");
  if (!configFile)
  {
    return false;
  }

  json.printTo(configFile);
  configFile.close();
  return true;
}
