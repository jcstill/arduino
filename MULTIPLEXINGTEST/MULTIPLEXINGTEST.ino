void ledOn(int led){
  switch(led){
    case 0:
      digitalWrite(9, LOW);
      digitalWrite(7, LOW);
      digitalWrite(5, LOW);
      digitalWrite(3, LOW);
      break;
    case 1:
      digitalWrite(9, LOW);
      digitalWrite(3, LOW);
      digitalWrite(7, HIGH);
      digitalWrite(5, HIGH);
      break;
    case 2:
      digitalWrite(3, LOW);
      digitalWrite(7, LOW);
      digitalWrite(5, HIGH);
      digitalWrite(9, HIGH);
      break;
    case 3:
      digitalWrite(9, LOW);
      digitalWrite(5, LOW);
      digitalWrite(7, HIGH);
      digitalWrite(3, HIGH);
      break;
    case 4:
      digitalWrite(7, LOW);
      digitalWrite(5, LOW);
      digitalWrite(9, HIGH);
      digitalWrite(3, HIGH);
      break;
  }
}

void setup() {
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);
  
  pinMode(9, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(3, OUTPUT);
  digitalWrite(9, LOW);
  digitalWrite(7, LOW);
  digitalWrite(5, LOW);
  digitalWrite(3, LOW);
}

int multiplier = 5;

void loop() {
  // put your main code here, to run repeatedly:
  for(int i=0; i<100 * multiplier; i++){
    ledOn(1);
    delay(1);
  }
  for(int i=0; i<100 * multiplier; i++){
    ledOn(2);
    delay(1);
  }
  for(int i=0; i<100 * multiplier; i++){
    ledOn(3);
    delay(1);
  }
  for(int i=0; i<100 * multiplier; i++){
    ledOn(4);
    delay(1);
  }
  //--------
  for(int i=0; i<50 * multiplier; i++){
    ledOn(1);
    delay(1);
    ledOn(2);
    delay(1);
  }
  for(int i=0; i<50 * multiplier; i++){
    ledOn(1);
    delay(1);
    ledOn(3);
    delay(1);
  }
  for(int i=0; i<50 * multiplier; i++){
    ledOn(4);
    delay(1);
    ledOn(2);
    delay(1);
  }
  for(int i=0; i<50 * multiplier; i++){
    ledOn(4);
    delay(1);
    ledOn(3);
    delay(1);
  }
  //--------
  for(int i=0; i<50 * multiplier; i++){
    ledOn(1);
    delay(1);
    ledOn(4);
    delay(1);
  }
  for(int i=0; i<50 * multiplier; i++){
    ledOn(2);
    delay(1);
    ledOn(3);
    delay(1);
  }
  //--------
  for(int i=0; i<33 * multiplier; i++){
    ledOn(1);
    delay(1);
    ledOn(2);
    delay(1);
    ledOn(3);
    delay(1);
  }
  for(int i=0; i<33 * multiplier; i++){
    ledOn(1);
    delay(1);
    ledOn(3);
    delay(1);
    ledOn(4);
    delay(1);
  }
  for(int i=0; i<33 * multiplier; i++){
    ledOn(2);
    delay(1);
    ledOn(3);
    delay(1);
    ledOn(4);
    delay(1);
  }
  for(int i=0; i<33 * multiplier; i++){
    ledOn(1);
    delay(1);
    ledOn(2);
    delay(1);
    ledOn(4);
    delay(1);
  }
  //--------
  for(int i=0; i<25 * multiplier; i++){
    ledOn(1);
    delay(1);
    ledOn(2);
    delay(1);
    ledOn(3);
    delay(1);
    ledOn(4);
    delay(1);
  }
}















