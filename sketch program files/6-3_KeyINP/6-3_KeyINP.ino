int ev = 0;
byte cx = 0, sx;
byte dg[] = {10, 10, 10};
byte keyPX, keyPXD;
//----------- pgfedcba pgfedcba
const byte dx[] = {B00111111, B00000110, B01011011, B01001111,
                   B01100110, B01101101, B01111101, B00000111, B01111111, B01100111};
void setup() {
  Serial.begin(9600);
  DDRC = 0x3F; //PC[0..5] as output
  DDRB = 0x3F; //PB[0..5] as output
  DDRD = 0xC2; // PD[6..7] & PD[1]/TX as output
  PORTD = 0x3E; //PD[2..5] w/Pull-Up
}
byte KeyPress() {
  keyPXD = 0xF;
  PORTD = 0xBC; // scan C1/PD6 row
  delay(2);
  keyPX = (PIND >> 2) & 0x0F;
  if (keyPX == B0111) keyPXD = 10;
  if (keyPX == B1011) keyPXD = 7;
  if (keyPX == B1101) keyPXD = 4;
  if (keyPX == B1110) keyPXD = 1;
  PORTD = 0x7C; // scan C1/PD7 row
  delay(2);
  keyPX = (PIND >> 2) & 0x0F;
  if (keyPX == B0111) keyPXD = 0;
  if (keyPX == B1011) keyPXD = 8;
  if (keyPX == B1101) keyPXD = 5;
  if (keyPX == B1110) keyPXD = 2;
  PORTD = 0xFC; // scan C3/GND row
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
  sx = dx[dg[cx]];
  PORTB = PORTB | B011100;
  PORTC = sx & 0x3F;
  PORTB = ((PORTB & 0xFC) | (sx >> 6));
  PORTB = PORTB & (~(4 << cx));
  cx = ++cx % 3;
  if ((PIND & 0x3C) != 0x3C) {
    dg[2] = dg[1];
    dg[1] = dg[0];
    dg[0] = KeyPress();
    while ((PIND & 0x3C) != 0x3C);
  }
  Serial.print(keyPXD);
  Serial.print("\t");
  Serial.print(dg[2], HEX);
  Serial.print(dg[1], HEX);
  Serial.println(dg[0], BIN);
  delay(10);
}
