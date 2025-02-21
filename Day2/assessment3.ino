// Assessment-3: Rotate Servo Motor to 90 degress when 50% Wet

#include<ESP32Servo.h>
Servo motor;

int moisture=34;

void setup() {
  motor.attach(23);
  pinMode(moisture,INPUT);
  Serial.begin(9600);
}

void loop() {
  float m=analogRead(moisture);
  m=4095-m;
  float p=(m/4095)*100;
  Serial.print(p);
  Serial.println("% wet");
  delay(1000);
  if(p>50)
    motor.write(90);
  else
    motor.write(0);
}
