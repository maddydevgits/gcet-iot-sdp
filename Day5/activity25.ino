#include <WiFi.h>
#include <HTTPClient.h>
#include <DHT.h>

DHT dht(5,DHT11);

const char* ssid="Geethanjali";
const char* password="campus@123456";
const char* apiRoute="http://10.1.6.140:2000/predict?h=";

void setup() {
  Serial.begin(9600);
  WiFi.mode(WIFI_STA);
  dht.begin();

  WiFi.begin(ssid,password);
  while(WiFi.status()!=WL_CONNECTED){
    Serial.print(".");
    delay(1000);
  }
  Serial.println("WIFI Connected");
}

void loop() {
  float h=dht.readHumidity();
  if(isnan(h)){
    Serial.println("DHT Error");
    return;
  }

  invokeAI(h);
}

void invokeAI(float h1){
  if(WiFi.status()==WL_CONNECTED){
    HTTPClient http;
    http.begin(apiRoute+String(h1));
    int responseCode=http.GET();
    Serial.println(responseCode);
    if(responseCode>0){
      String response=http.getString();
      Serial.println(response);
      http.end();
    }
  } else {
    Serial.println("AI Calling Failed");
    delay(4000);
  }
  delay(4000);
}
