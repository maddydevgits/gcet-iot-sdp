// Activity-12: Connect Internet to ESP32

#include<WiFi.h>
const char* ssid="Madhu's iPhone";
const char* password="1234";

void setup() {
  Serial.begin(9600);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid,password);
  while(WiFi.status()!=WL_CONNECTED){
    Serial.print(".");
    delay(1000);
  }
  Serial.println("Connected to Internet");
}

void loop() {
  // put your main code here, to run repeatedly:

}
