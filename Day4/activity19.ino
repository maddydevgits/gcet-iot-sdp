// Activity-19: Control LED from Blynk App

#define BLYNK_TEMPLATE_ID ""
#define BLYNK_TEMPLATE_NAME ""
#define BLYNK_AUTH_TOKEN ""
#define BLYNK_PRINT Serial

#include<WiFi.h>
#include<BlynkSimpleEsp32.h>

int led=2;

BLYNK_WRITE(V2){
  int state=param.asInt();
  if(state==1)
    digitalWrite(led,1);
  else
    digitalWrite(led,0);
}

const char* ssid="Mad";
const char* password="123456";


void setup() {
  pinMode(led,OUTPUT);
  Serial.begin(9600);
  Blynk.begin(BLYNK_AUTH_TOKEN,ssid,password);
}

void loop() {
  Blynk.run();
}
