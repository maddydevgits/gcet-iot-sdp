// Activity-4: Control LED from user input

int led=2;
void setup() {
  pinMode(led,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  while(Serial.available()){
    String s=Serial.readString();
    if(s=="on" || s=="ON")
      digitalWrite(led,1);
    else if(s=="off" || s=="OFF")
      digitalWrite(led,0);
  }
}
