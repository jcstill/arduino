char spec;

void setup() {
  Serial.begin(9600);
  while(!Serial);
  
}






















void loop() {
  if(Serial.available()){
    spec = Serial.read();
    Serial.print(spec);
  }
  
}
