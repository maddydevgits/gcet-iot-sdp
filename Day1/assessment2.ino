// Assessment-2: Toggling LED finite times

int led=2;

void setup(){
    pinMode(led,OUTPUT);
    for(int i=0;i<5;i++){
        digitalWrite(led,1);
        delay(400);
        digitalWrite(led,0);
        delay(400);
    }
}

void loop(){

}