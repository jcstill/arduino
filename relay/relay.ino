void(* resetFunc) (void) = 0;
void setup(){
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  while(!Serial);
  digitalWrite(2, LOW);
}
void loop(){
  if(Serial.available()){
    char x=Serial.read();
    switch(x){
      case '1':
        digitalWrite(2, HIGH);
        Serial.print("Relay On");
        break;
      case '0':
        digitalWrite(2, LOW);
        Serial.print("Relay Off");
        break;
      case 'r':
        Serial.print("Resetting");
        delay(100);
        resetFunc();
        break;
    }
  }
}

/*
--------------------------------------------------------------------------
int Reset = 4;
void setup(){
  digitalWrite(Reset, HIGH);
  delay(200); 
  pinMode(Reset, OUTPUT);
  Serial.begin(9600);
  Serial.println("How to Reset Arduino Programmatically");
  delay(200);
}
void loop(){
  Serial.println("A");
  delay(1000);
  Serial.println("B");
  delay(1000);
  Serial.println("Now we are Resetting Arduino Programmatically");
  Serial.println();
  delay(1000);
  digitalWrite(Reset, LOW);
  Serial.println("Arduino will never reach there.");
}
--------------------------------------------------------------------------
void(* resetFunc) (void) = 0;
void setup(){
  Serial.begin(9600);
  Serial.println("How to Reset Arduino Programmatically");
  delay(200);
}
void loop(){
  Serial.println("A");
  delay(1000);
  Serial.println("B");
  delay(1000);
  Serial.println("Now we are Resetting Arduino Programmatically");
  Serial.println();
  delay(1000);
  resetFunc();
  Serial.println("Arrduino will never reach there.");
}
--------------------------------------------------------------------------
*/