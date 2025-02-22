// Activity-18: Log the data on Blynk App

#define BLYNK_TEMPLATE_ID ""
#define BLYNK_TEMPLATE_NAME ""
#define BLYNK_AUTH_TOKEN ""
#define BLYNK_PRINT Serial

#include<WiFi.h>
#include<BlynkSimpleEsp32.h>
#include<DHT.h>

DHT dht(5,DHT11);

const char* ssid="Mad";
const char* password="12345678";

void setup() {
  Serial.begin(9600);
  dht.begin();
  Blynk.begin(BLYNK_AUTH_TOKEN,ssid,password);
}

void loop() {
    float h=dht.readHumidity();
    float t=dht.readTemperature();

    if(isnan(h)||isnan(t)){
      Serial.println("DHT Error");
      return;
    }

    Serial.print("H: ");
    Serial.print(h);
    Serial.print(",T: ");
    Serial.println(t);

    Blynk.virtulWrite(V0,h);
    Blynk.virtualWrite(V1,t);

    delay(2000);
}
