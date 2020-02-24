#define DOT 5
#define TOP 8
#define TOPLEFT 9
#define TOPRIGHT 6
#define MIDDLE 10
#define BOTTOMLEFT 12
#define BOTTOMRIGHT 7
#define BOTTOM 11



void setup() {
  pinMode(DOT, OUTPUT);
  pinMode(TOP, OUTPUT);
  pinMode(TOPLEFT, OUTPUT);
  pinMode(TOPRIGHT, OUTPUT);
  pinMode(MIDDLE, OUTPUT);
  pinMode(BOTTOMLEFT, OUTPUT);
  pinMode(BOTTOMRIGHT, OUTPUT);
  pinMode(BOTTOM, OUTPUT);
}

void loop() {
  for(int i=0; i<11; i++){
    if(i == 0){
      digitalWrite(TOP, HIGH);
      digitalWrite(TOPLEFT, HIGH);
      digitalWrite(TOPRIGHT, HIGH);
      digitalWrite(BOTTOMLEFT, HIGH);
      digitalWrite(BOTTOMRIGHT, HIGH);
      digitalWrite(BOTTOM, HIGH);
    }
    if(i == 1){
      digitalWrite(TOPRIGHT, HIGH);
      digitalWrite(BOTTOMRIGHT, HIGH);
    }
    if(i == 2){
      digitalWrite(TOP, HIGH);
      digitalWrite(TOPRIGHT, HIGH);
      digitalWrite(MIDDLE, HIGH);
      digitalWrite(BOTTOMLEFT, HIGH);
      digitalWrite(BOTTOM, HIGH);
    }
    if(i == 3){
      digitalWrite(TOP, HIGH);
      digitalWrite(TOPRIGHT, HIGH);
      digitalWrite(MIDDLE, HIGH);
      digitalWrite(BOTTOMRIGHT, HIGH);
      digitalWrite(BOTTOM, HIGH);
    }
    if(i == 4){
      digitalWrite(TOPRIGHT, HIGH);
      digitalWrite(TOPLEFT, HIGH);
      digitalWrite(MIDDLE, HIGH);
      digitalWrite(BOTTOMRIGHT, HIGH);
    }
    if(i == 5){
      digitalWrite(TOP, HIGH);
      digitalWrite(TOPLEFT, HIGH);
      digitalWrite(MIDDLE, HIGH);
      digitalWrite(BOTTOMRIGHT, HIGH);
      digitalWrite(BOTTOM, HIGH);
    }
    if(i == 6){
      digitalWrite(TOP, HIGH);
      digitalWrite(TOPLEFT, HIGH);
      digitalWrite(MIDDLE, HIGH);
      digitalWrite(BOTTOMLEFT, HIGH);
      digitalWrite(BOTTOMRIGHT, HIGH);
      digitalWrite(BOTTOM, HIGH);
    }
    if(i == 7){
      digitalWrite(TOP, HIGH);
      digitalWrite(TOPRIGHT, HIGH);
      digitalWrite(BOTTOMRIGHT, HIGH);
    }
    if(i == 8){
      digitalWrite(TOP, HIGH);
      digitalWrite(TOPLEFT, HIGH);
      digitalWrite(TOPRIGHT, HIGH);
      digitalWrite(MIDDLE, HIGH);
      digitalWrite(BOTTOMLEFT, HIGH);
      digitalWrite(BOTTOMRIGHT, HIGH);
      digitalWrite(BOTTOM, HIGH);
    }
    if(i == 9){
      digitalWrite(TOP, HIGH);
      digitalWrite(TOPLEFT, HIGH);
      digitalWrite(TOPRIGHT, HIGH);
      digitalWrite(MIDDLE, HIGH);
      digitalWrite(BOTTOMRIGHT, HIGH);
      digitalWrite(BOTTOM, HIGH);
    }
    if(i == 10){
      digitalWrite(DOT, HIGH);
    }
    delay(500);
    digitalWrite(DOT, LOW);
    digitalWrite(TOP, LOW);
    digitalWrite(TOPLEFT, LOW);
    digitalWrite(TOPRIGHT, LOW);
    digitalWrite(MIDDLE, LOW);
    digitalWrite(BOTTOMLEFT, LOW);
    digitalWrite(BOTTOMRIGHT, LOW);
    digitalWrite(BOTTOM, LOW);
    delay(500);
  }
}
