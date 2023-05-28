int ev = 1;

void setup() {
  Serial.begin(9600);
  Serial.println("Hello");
}

void loop() {
  Serial.println(ev);
  ev = ev + 1;
  delay(500);
}
