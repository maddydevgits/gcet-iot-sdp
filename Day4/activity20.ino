// Control LED from Blynk App

#define BLYNK_TEMPLATE_NAME ""
#define BLYNK_AUTH_TOKEN ""
#define BLYNK_TEMPLATE_ID ""


#define BLYNK_PRINT Serial

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

// Your WiFi credentials.
char ssid[] = "";
char pass[] = "";

int led=2;

BLYNK_WRITE(V1) { //move forward
  int state = param.asInt();
  if(state==1)
    digitalWrite(led,1);
  else
    digitalWrite(led,0);
}

void setup()
{
  // Debug console
  Serial.begin(115200);

  pinMode(led,OUTPUT);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}

void loop()
{
  Blynk.run();
}