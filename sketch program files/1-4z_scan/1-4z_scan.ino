int ev = 0;
void setup() {
  Serial.begin(9600);
  DDRC = 0xFF;
}
void loop() {
  Serial.print(ev);
  
  if (ev & 0x4 )
    PORTC = 1 << (ev & B11);
  else
    PORTC = B10000 >> (ev & B11);
  ev = ++ev & B111;
  
  Serial.print("\t");
  Serial.print(ev);
  Serial.println(PORTC, DEC);
  delay(500); // ignore for speed test
}
