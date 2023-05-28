int ev = 0, keyPX, keyPXD;
void setup() {
  Serial.begin(9600);
  DDRC = 0x3F;
  DDRD = 0xC2; // PD[6..7] & PD[1]/TX as output
  PORTD = 0x3C; // PD[2..5] w/Pull-Up
}
byte KeyPress() {
  PORTD = 0xFC; // scan C3/GND
  delay(2);
  keyPX = (PIND >> 2) & 0x0F;
  if (keyPX == B0111) return (12);
  if (keyPX == B1011) return (9);
  if (keyPX == B1101) return (6);
  if (keyPX == B1110) return (3);
  PORTD = 0x7C; // scan C2/PD7
  delay(2);
  keyPX = (PIND >> 2) & 0x0F;
  if (keyPX == B0111) return (0);
  if (keyPX == B1011) return (8);
  if (keyPX == B1101) return (5);
  if (keyPX == B1110) return (2);
  PORTD = 0xBC; // scan C1/PD6
  delay(2);
  keyPX = (PIND >> 2) & 0x0F;
  if (keyPX == B0111) return (10);
  if (keyPX == B1011) return (7);
  if (keyPX == B1101) return (4);
  if (keyPX == B1110) return (1);
  return (0xF);
}
void loop() {
  ev++;
  Serial.print(ev);
  PORTC = KeyPress();
  Serial.print("\t");
  Serial.println(PORTC, HEX);
  delay(100);
}
