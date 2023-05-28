int ev = 0, cx = 0, sx;
//----------- pgfedcba pgfedcba pgfedcba pgfedcba
const byte dx[] = {B00111111,B00000110,B01011011,B01001111,
B01100110,B01101101,B01111100,B00000111,B01111111,B01100111,
B01110111,B01111100,B01011000,B01011110,B01111001,B01110001};
void setup() {
  Serial.begin(9600);
  DDRC = 0x3F; //PC[0..5] as output
  DDRB = 0x3F; //PB[0..5] as output
}
void loop() {
  //Serial.print(ev);
  PORTB = (PORTB | B011100) & (~(4 << cx));
  sx = dx[cx];
  PORTC = sx & 0x3F;
  PORTB = (PORTB & 0xFC) | sx >> 6;
  cx = ++cx % 3;
  ev = ++ev & 0xF;
  //Serial.print("\t");
  //Serial.print(ev,HEX);
  //Serial.print("\t");
  //Serial.println(cx,HEX);
  delayMicroseconds(100);
  //shadowing 10000->5~2000->100
}
