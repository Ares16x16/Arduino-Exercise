int ev = 0;
void setup() {
  Serial.begin(9600);
  DDRC = 0xFF;
}
void loop() {
  Serial.print(ev);
  PORTC = 1 << ev;
  ev = ++ev % 6; //irregular range control ++x%n [0..n]
  //ev = ++ev & 0x03; //regular range control ++x&(2^n) [0..2^n]
  Serial.print("\t");
  Serial.println(PORTC, DEC);
  delay(500); // ignore for speed test
}
