#include <DHT.h>
#include <ArduinoJson.h>

#define dhtpin 2
#define dhttype DHT11

DHT dht(dhtpin, dhttype);

void setup() {
  dht.begin();
  Serial.begin(9600);

}

void loop() {
  int temp = dht.readTemperature();
  int umi = dht.readHumidity();

  StaticJsonDocument<100>json;

  json["Temperatura"] = temp;
  json["Umidade"] = umi;

  serializeJson(json, Serial);
  Serial.println();
  delay(2000);

}
