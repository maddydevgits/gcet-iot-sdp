#include<DHT.h>

DHT dht(5,DHT11);
String out;

// AI is past observation
// I/P, O/P
// I/P is DHT11
// O/P is Outcome

void setup() {
  dht.begin();
  Serial.begin(9600);
}

void loop() {
  float h=dht.readHumidity();
  float t=dht.readTemperature();

  if(isnan(h)||isnan(t)){
    Serial.println("DHT Error");
    return;
  }

  if(h>20 && h<60){
    out="no rain";
  } else if(h>60 && h<80) {
    out="rain may fall";
  } else if(h>80 && h<100){
    out="raining";
  }

  Serial.print("#");
  Serial.print(",");
  Serial.print(h);
  Serial.print(",");
  Serial.print(out);
  Serial.print(",");
  Serial.println("~");
  delay(4000);

  
}
