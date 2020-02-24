String dip = "";
void setup() {
  Serial.begin(9600);

  dip = "";

  pinMode(6, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);

  if(digitalRead(6) == LOW){dip += "1";}else{dip += "0";}
  if(digitalRead(7) == LOW){dip += "1";}else{dip += "0";}
  if(digitalRead(8) == LOW){dip += "1";}else{dip += "0";}
  if(digitalRead(9) == LOW){dip += "1";}else{dip += "0";}

  Serial.println(dip);
}

void loop() {
  dip = "";
  if(digitalRead(6) == LOW){dip += "1";}else{dip += "0";}
  if(digitalRead(7) == LOW){dip += "1";}else{dip += "0";}
  if(digitalRead(8) == LOW){dip += "1";}else{dip += "0";}
  if(digitalRead(9) == LOW){dip += "1";}else{dip += "0";}

  Serial.println(dip);
  delay(1000);
}
