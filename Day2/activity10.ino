// Activity-10: Read Distance from Object

int trig=12;
int echo=14;

void setup(){
    Serial.begin(9600);
    pinMode(trig,OUTPUT);
    pinMode(echo,INPUT);
}

void loop(){
    digitalWrite(trig,0);
    delayMicroseconds(2);
    digitalWrite(trig,1);
    delayMicroseconds(10);
    digitalWrite(trig,0);

    float duration=pulseIn(echo,1);
    duration=duration/2;

    float distance=(0.034)*duration;
    Serial.print(distance);
    Serial.println(" cm");
    delay(1000);
}