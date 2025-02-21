// Activity-6: Print the Object Status

int ir=21;
void setup() {
  pinMode(ir,INPUT);
  Serial.begin(9600);
}

void loop() {
  int m=digitalRead(ir);
  Serial.println(m);
  delay(1000);
  if(m==0)
    Serial.println("Object Detected");
  else
    Serial.println("Normal");
}
