// Activity-8: Plot the Gas Data

int gas=35;

void setup(){
    Serial.begin(9600);
    pinMode(gas,INPUT);
}

void loop(){
    int m=analogWrite(gas);
    Serial.println(m);
    delay(100);
}