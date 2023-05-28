byte ev = 0, dir = 0, exec = 0;
void setup() {
  pinMode(2, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(2), cxDIR, FALLING);
  pinMode(3, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(3), cxHOME, FALLING);
  Serial.begin(9600);
  DDRC = 0xFF;
  PORTC = 0x21;
}
void loop() {
  Serial.print(ev);
  if (exec) {
    if (dir) PORTC = 1 << ev;
    else PORTC = B100000 >> ev;
    ev = ++ev % 6;
    Serial.print("\t");
    Serial.println(PORTC, BIN);
    delay(500);
  }
}
void cxDIR() {
  dir = (~dir);
  ev = 5 - ev;
  exec = 1;
}
void cxHOME() {
  ev = 0;
  exec = 1;
}
