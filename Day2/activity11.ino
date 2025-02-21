// Activity-11: Read Humidity and Temperature

#include <DHT.h>

DHT dht(2,DHT11);

void setup(){
    dht.begin();
    Serial.begin(9600);
}

void loop(){
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
    delay(4000);
}