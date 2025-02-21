// Activity-9: Rotate Servo Motor continuously

#include<ESP32Servo.h>

Servo motor;

void setup(){
    motor.attach(23);
}

void loop(){
    for(int i=0;i<180;i++){
        motor.write(i);
        delay(100);
    }

    for(int j=180;j>0;j--){
        motor.write(j);
        delay(100);
    }
}