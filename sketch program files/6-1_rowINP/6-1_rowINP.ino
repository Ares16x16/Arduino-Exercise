int ev = 0;
void setup() {
  Serial.begin(9600);
  DDRC = 0x3F;
  DDRD = 0xC2; // PD[6..7] & PD[1]/TX as output
  PORTD = 0x3C; // PD[2..5]w/Pull-Up & PD[6..7] + GND@Low
}
void loop() {
  ev++;
  Serial.print(ev);
  PORTC = (PIND >> 2) & 0x0F;
  Serial.print("\t");
  Serial.println(PORTC, BIN);
  delay(100);
}
