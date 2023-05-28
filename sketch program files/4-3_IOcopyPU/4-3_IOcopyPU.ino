int ev = 0;
void setup() {
  Serial.begin(9600);
  DDRC = 0x3F;
  DDRD = 0xC2; // PD[6..7] & PD[1]/TX as output
  PORTD = 0x7E; // PD[2..5] w/Pull-Up
}
void loop() {
  ev++;
  Serial.print(ev);
  PORTC = (PIND >> 2) & 0x0F;
  //PORTD = (~(PORTD & B11000000)) | (PORTD & B00111100);
  //PORTD = (~(PORTD&B11000000))|B111100;
  PORTD = (~(PORTD&B11000000));
  Serial.print("\t");
  Serial.print(PORTC, BIN);
  Serial.print("\t");
  Serial.println(PORTD & 0xC0, BIN);
  delay(500);
}
