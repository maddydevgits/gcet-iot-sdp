// Assessment-4: Rotate Servo Motor to 90 degress when saline is empty;

#include<ESP32Servo.h>
Servo motor;
int trig=12;
int echo=14;

void setup() {
  motor.attach(23);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  Serial.begin(9600);
}

void loop() {
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
  if(distance>15)
    motor.write(90);
  else
    motor.write(0);
}
