// Activity-20: Notify the parent (75% Wet) via Blynk


#define BLYNK_TEMPLATE_ID ""
#define BLYNK_TEMPLATE_NAME ""
#define BLYNK_AUTH_TOKEN ""
#define BLYNK_PRINT Serial

#include<WiFi.h>
#include<BlynkSimpleEsp32.h>

int moisture=34;

const char* ssid="Mad";
const char* password="1234";


void setup() {
  pinMode(moisture,INPUT);
  Serial.begin(9600);
  Blynk.begin(BLYNK_AUTH_TOKEN,ssid,password);
}

void loop() {
  float m=analogRead(moisture);
  m=4095-m;
  float p=(m/4095)*100;
  Serial.println(p);
  
  Blynk.virtualWrite(V3,p);
  if(p>75){
    Serial.println("Alert");
    Blynk.logEvent("moisture_alert","It is 75% Wet");
  }
  delay(2000);
  Blynk.run();
}
