int ev = 0;

void setup() {
  Serial.begin(9600);
  DDRC = 0x3f;
  PORTC = B01010101;
}

void loop() {
  ev++;
  Serial.print(ev);
  
  if (PORTC == 0x55) {
    PORTC = 0xAA;
  }
  else {
    PORTC = 0x55;
  }
  
  Serial.print(" ");
  Serial.print(PORTC);
  Serial.print(" ");
  Serial.print(PORTC, HEX);
  Serial.print(" ");
  Serial.print(PORTC, BIN);
  Serial.println();
  delay(1500);
}
