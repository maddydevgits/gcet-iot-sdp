// Toggling LED at D2

int led=2;

void setup(){
    pinMode(led,OUTPUT);
}

void loop(){
    digitalWrite(led,1);
    delay(400);
    digitalWrite(led,0);
    delay(400);
}