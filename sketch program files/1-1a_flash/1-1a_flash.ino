int ev = 0;
void setup() {
  Serial.begin(9600);
  DDRC = 0xFF;
  PORTC = B01010101;
}
void loop() {
  ev++;
  Serial.println(ev);
  if (PORTC == 0x55) PORTC =
      0xAA;
  else PORTC = 0x55;
  delay(500);
}
