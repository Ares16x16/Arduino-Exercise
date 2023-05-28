int ev = 0, i = 1;
void setup() {
  Serial.begin(9600);
  DDRC = 0xFF;
}

void loop() {
  Serial.print(ev);
  
  PORTC = i;
  i = i + i; //i=2i
  if (i == 0x40) i = 1;
  
  Serial.print("\t");
  Serial.print(i, DEC);
  Serial.println(PORTC, DEC);
  delay(500); // ignore for speed test
}
