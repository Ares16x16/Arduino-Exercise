int ev = 0, ev2 = 0;
const byte dx[] = {B00111111, B00000110, B01011011, B01001111,
                   B01100110, B01101101, B01111101, B00000111, B01111111,
                   B01101111, 0x3F,0,0x3F,0,0xFF};//endcode
void setup() {
  Serial.begin(9600);
  DDRC = 0xFF;
  TCCR2A = 0x02; //setup Timer#2 as CTC
  TCCR2B = B111; //prescaler with clk/n
  OCR2A = 255;
  TIMSK2 = 0x02; //enable OCR2A interrupt
  sei();
}
ISR(TIMER2_COMPA_vect) {
  ev++;
  if (ev == 100) {
    ev = 0;
    if ( dx[ev2] == 0xFF ) ev2 = 0;
    PORTC = dx[ev2];
    ev2++;
  }
}
void loop() {
  Serial.print(ev2);
  Serial.print("\t");
  Serial.print(ev);
  Serial.print(" ");
  Serial.println(PORTC, BIN);
}
