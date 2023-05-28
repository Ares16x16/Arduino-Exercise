int ev = 0;
void setup() {
  Serial.begin(9600);
  DDRC = 0xFF;
  PORTC = 0xFF; //B010101,B001100,B000111,B111111
}
void loop() {
  ev++;
  Serial.print(ev);
  PORTC = ~PORTC;
  Serial.print("\t");
  Serial.println(PORTC, DEC);
  delay(500);
}
