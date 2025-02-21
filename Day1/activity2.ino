// Making LED On at D2

int led=2;

void setup(){
    pinMode(led,OUTPUT);
}

void loop(){
    digitalWrite(led,1);
}