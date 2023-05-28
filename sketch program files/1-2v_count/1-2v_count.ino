int ev = 0, cntr = 0; //
void setup() {
  Serial.begin(9600);
  DDRC = 0xFF;
}
void loop() {
  ev++;
  cntr = ++cntr & 0x0F;
  Serial.print(ev);
  Serial.print("/");
  Serial.print(cntr);
  //PORTC = cntr; // counter binary value for debug
  if ( (cntr & 0x04) && (cntr & 0x01) ) PORTC = PORTC | B010000;
  else PORTC = PORTC & B101111;
  if ( (cntr & 0x08) && (cntr & 0x04) ) PORTC = PORTC | B100000;
  else PORTC = PORTC & B011111;
  Serial.print("-");
  Serial.println(PORTC & B110000, HEX);
  delay(100);
}
