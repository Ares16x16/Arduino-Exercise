int ev = 0, fwd = 0;
void setup() {
  Serial.begin(9600);
  DDRC = 0xFF;
}
void loop() {
  Serial.print(ev);
  for (ev = 0; ev < 6; ev++) {
    if (fwd) PORTC = 1 << ev;
    else PORTC = B100000 >> ev;
    delay(500);
  }
  fwd = ~fwd;
}
