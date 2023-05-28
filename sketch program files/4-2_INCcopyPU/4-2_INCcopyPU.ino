int ev = 0;
void setup() {
  Serial.begin(9600);
  DDRC = 0x3F;
  DDRD = 0x02; // PD[1]/TX as output
  PORTD = 0xFC;
}
void loop() {
  ev++;
  Serial.print(ev);
  PORTC = PIND >> 2;
  Serial.print("\t");
  Serial.print(PORTC, BIN);
  Serial.println();
  delay(500);
}
