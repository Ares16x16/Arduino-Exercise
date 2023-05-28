byte ev = 0, dir = 0;
void setup() {
  pinMode(2, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(2), cxDIR, FALLING);
  Serial.begin(9600);
  DDRC = 0xFF;
}
void loop() {
  Serial.print(ev);
  if (dir) PORTC = 1 << ev;
  else PORTC = B1000 >> ev;
  ev = ++ev & B11;
  Serial.print("\t");
  Serial.println(PORTC, BIN);
  delay(500);
}
void cxDIR() {
  dir = (~dir);
  ev = 3 - ev;
}
