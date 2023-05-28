int ev = 0, i = 1;

void setup() {
  Serial.begin(9600);
  //DDRC = 0xFF;
  pinMode(14, OUTPUT); //PC[0]
  pinMode(15, OUTPUT); //PC[1]
  pinMode(16, OUTPUT); //PC[2]
  pinMode(17, OUTPUT); //PC[3]
  pinMode(18, OUTPUT); //PC[4]
  pinMode(19, OUTPUT); //PC[5]
}

void loop() {
  Serial.print(ev);
  digitalWrite(ev + 14, LOW);
  ev = ++ev % 6;
  digitalWrite(ev + 14, HIGH);
  Serial.print("\t");
  Serial.print(i, DEC);
  Serial.println(PORTC, DEC);
  delay(500); 
}
