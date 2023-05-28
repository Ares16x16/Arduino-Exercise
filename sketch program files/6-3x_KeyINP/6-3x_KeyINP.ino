int ev = 0;
byte cx = 0, sx;
byte dg[] = {10, 10, 10};
byte keyPX, keyPXD;
//----------- pgfedcba pgfedcba
const byte dx[] = {B00111111,B00000110,B01011011,B01001111,
B01100110,B01101101,B01111100,B00000111,B01111111,B01100111,
B01000000,B01111100,B01011000,B01011110,B01111001,B01110001};

byte KeyPress() {
  keyPXD = 0xF;
  
  PORTD = 0xBC; // scan C1/PD6 row
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
ISR(TIMER2_COMPA_vect) {
  sx = dx[dg[cx]];
  PORTB = PORTB | B011100;
  PORTC = sx & 0x3F;
  PORTB = ((PORTB & 0xFC) | (sx >> 6));
  PORTB = PORTB & (~(4 << cx));
  cx = ++cx % 3;
}
void setup() {
  Serial.begin(9600);
  DDRC = 0x3F; //PC[0..5] as output
  DDRB = 0x3F; //PB[0..5] as output
  DDRD = 0xC2; // PD[6..7] & PD[1]/TX asoutput
  PORTD = 0x3E; //PD[2..5] w/Pull-Up
  TCCR2A = 0x02; //setup Timer#2 as CTC
  TCCR2B = B100; //prescaler with clk/64
  OCR2A = 128;
  TIMSK2 = 0x02; //enable OCR2A interrupt
  sei();
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
    dg[0] = dg[1];
    dg[1] = dg[2];
    dg[2] = KeyPress();
    while ((PIND & 0x3C) != 0x3C);
  }
  delay(10);
}
