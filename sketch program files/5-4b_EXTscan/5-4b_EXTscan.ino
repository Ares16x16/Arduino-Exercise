byte ev = 0, dir = 0;
void setup() {
  pinMode(2, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(2), cxDIR, LOW);
  Serial.begin(9600);
  DDRC = 0xFF;
}
void loop() {
  Serial.print(ev);
  if (dir) PORTC = 1 << ev;
  else PORTC = B100000 >> ev;
  ev = ++ev % 6;
  Serial.print("\t");
  Serial.println(PORTC, BIN);
  delay(500);
}
void cxDIR() {
  dir = (~dir);
  ev = 5 - ev;
}
