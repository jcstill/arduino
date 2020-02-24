void ledOn(uint8_t led){
  if((led >> 0) && 0x00000001 == 0x01){
    digitalWrite(9, LOW);
    digitalWrite(7, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(3, LOW);
  }
  if((led >> 1) && 0x00000001 == 0x01){
    digitalWrite(9, HIGH);
    digitalWrite(7, LOW);
    digitalWrite(5, HIGH);
    digitalWrite(3, LOW);
  }
  if((led >> 2) && 0x00000001 == 0x01){
    digitalWrite(9, LOW);
    digitalWrite(7, HIGH);
    digitalWrite(5, LOW);
    digitalWrite(3, HIGH);
  }
  if((led >> 3) && 0x00000001 == 0x01){
    digitalWrite(9, HIGH);
    digitalWrite(7, LOW);
    digitalWrite(5, LOW);
    digitalWrite(3, HIGH);
  }
}

void setup() {
  pinMode(9, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(3, OUTPUT);
  digitalWrite(9, LOW);
  digitalWrite(7, LOW);
  digitalWrite(5, LOW);
  digitalWrite(3, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  ledOn(0x00000010);
  delay(100);
}
