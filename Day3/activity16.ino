// Activity-16: Control LED from Mobile

#include<WiFi.h>
#include<ThingSpeak.h>

const char* ssid="Madhu's iPhone";
const char* password="1234";

int channelid=2849585;
int led=2;

WiFiClient client;

void setup() {
  pinMode(led,OUTPUT);
  Serial.begin(9600);
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
  int value=ThingSpeak.readIntField(channelid,1);
  Serial.println(value);
  if(value>0)
    digitalWrite(led,1);
  else
    digitalWrite(led,0);
  delay(5000);
}
