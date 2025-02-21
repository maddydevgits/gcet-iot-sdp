// Activity-13: Upload DHT11 to IoT Cloud

#include<WiFi.h>
#include<ThingSpeak.h>
#include<DHT.h>

DHT dht(5,DHT11);

int channelid=2849346;
const char* apikey="JZ9SEGP95Y02L8OA";

const char* ssid="Madhu's iPhone";
const char* password="1234";

WiFiClient client;

void setup() {
  Serial.begin(9600);
  dht.begin();

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid,password);
  
  while(WiFi.status()!=WL_CONNECTED){
    Serial.print(".");
    delay(1000);
  }
  Serial.println("Connected to Internet");

  ThingSpeak.begin(client);
}

void loop() {
  float h=dht.readHumidity();
  float t=dht.readTemperature();

  if(isnan(h)||isnan(t)){
    Serial.println("Error");
    return;
  }

  Serial.print("H:");
  Serial.print(h);
  Serial.print(",T:")
  Serial.println(t);

  ThingSpeak.setField(1,h);
  ThingSpeak.setField(2,t);

  int code=ThingSpeak.writeFields(channelid,apikey);
  if(code==200)
    Serial.println("Data Uploaded");
  else
    Serial.println("Data not Uploaded");
  
  delay(15000);
}
