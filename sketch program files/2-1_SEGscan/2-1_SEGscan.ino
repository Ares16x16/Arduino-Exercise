int ev = 0, sx;
void setup() {
  Serial.begin(9600);
  DDRC = 0x3F; //PC[0..5] as output
  DDRB = 0x3F; //PB[0..5] as output
}
void loop() {
  Serial.print(ev);
  sx = 1 << ev;
  PORTC = sx & 0x3F;
  PORTB = (PORTB & 0xFC) | sx >> 6;
  ev = ++ev & B111;
  Serial.print("\t");
  Serial.println(sx, HEX);
  delay(500); // ignore for speed test
}
