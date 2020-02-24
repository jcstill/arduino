String variable;

void setup() {
  Serial.begin(9600);
}

void loop() {
  while(Serial.available() > 0){
    variable = Serial.readString();
    Serial.println(variable);
  }
}

