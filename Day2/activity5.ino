// Activity-5: Control LED from sensor input

int light=23;
int led=2;
void setup() {
  pinMode(light,INPUT);
  pinMode(led,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int m=digitalRead(light);
  Serial.println(m);
  if(m==1) 
    digitalWrite(led,1);
  else
    digitalWrite(led,0);
}
