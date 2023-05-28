int ev = 0;
void setup() {
  Serial.begin(9600);
  DDRC = 0xFF;
}
void loop() {
  Serial.print(ev);
  if (ev == 0) PORTC = 0;
  else {
    PORTC = PORTC + (1 << (ev - 1));
  }
  ev = ++ev % 7;
  Serial.print("\t");
  Serial.print(ev);
  Serial.println(PORTC, DEC);
  delay(500); // ignore for speed test
}
