int ev = 0, keyPX, keyPXD;
void setup() {
  Serial.begin(9600);
  DDRC = 0x3F;
  DDRD = 0xC2; // PD[6..7] & PD[1]/TX as output
  PORTD = 0x3C; // PD[2..5] w/Pull-Up
}
byte KeyPress() {
  keyPXD = 0xF;
  PORTD = 0xBC; // scan C1/PD6
  delay(2);
  keyPX = (PIND >> 2) & 0x0F;
  if (keyPX == B0111) keyPXD = 10;
  if (keyPX == B1011) keyPXD = 7;
  if (keyPX == B1101) keyPXD = 4;
  if (keyPX == B1110) keyPXD = 1;
  
  PORTD = 0x7C; // scan C2/PD7
  delay(2);
  keyPX = (PIND >> 2) & 0x0F;
  if (keyPX == B0111) keyPXD = 0;
  if (keyPX == B1011) keyPXD = 8;
  if (keyPX == B1101) keyPXD = 5;
  if (keyPX == B1110) keyPXD = 2;
  
  PORTD = 0xFC; // scan C3/GND
  delay(2);
  keyPX = (PIND >> 2) & 0x0F;
  if (keyPX == B0111) keyPXD = 12;
  if (keyPX == B1011) keyPXD = 9;
  if (keyPX == B1101) keyPXD = 6;
  if (keyPX == B1110) keyPXD = 3;
  
  PORTD = 0x3C;
  return (keyPXD);
}
void loop() {
  ev++;
  Serial.print(ev);
  PORTC = KeyPress();
  Serial.print("\t");
  Serial.println(PORTC, HEX);
  delay(100);
}
