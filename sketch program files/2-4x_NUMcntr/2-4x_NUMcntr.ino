int ev = 0;
byte cx = 0, sx;
byte dg[] = {9, 2, 8};
int cntr;
//----------- pgfedcba pgfedcba pgfedcba pgfedcba
const byte dx[] = {B00111111,B00000110,B01011011,B01001111,
B01100110,B01101101,B01111101,B00000111,B01111111,B01101111};
void setup() {
  Serial.begin(9600);
  DDRC = 0x3F; //PC[0..5] as output
  DDRB = 0x3F; //PB[0..5] as output
}
void loop() {
  sx = dx[dg[cx]];
  PORTB = PORTB | B011100;
  PORTC = sx & 0x3F;
  PORTB = ((PORTB & 0xFC) | (sx >> 6));
  PORTB = PORTB & (~(4 << cx));
  cx = ++cx % 3;
  ev++;
  if (ev == 25) {
    ev = 0;
    cntr = ++cntr % 1000;
    dg[2] = cntr % 10 ;
    dg[0] = cntr / 100 ;
    dg[1] = (cntr / 10) % 10 ;
    
  }
  delay(5); //50-10
  //delayMicroseconds(5000);
}
