// Assessment-1: Printing your team name finite times

void setup(){
    Serial.begin(9600);
    for(int i=0;i<5;i++){
        Serial.println("CSE");
        delay(1000);
    }
}

void loop(){

}