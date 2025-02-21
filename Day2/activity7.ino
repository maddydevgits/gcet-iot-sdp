// Activity-7: Detect Dry or Wet and percentage of wet

int moisture=34;

void setup() {
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
}
