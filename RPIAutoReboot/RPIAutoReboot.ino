#include "TimeLib.h"
const int relay = 9;
int houroff = 3;
int minoff = 00;
int houron = 5;
int minon = 00;

void printDigits(int digits){
  Serial.print(":");
  if(digits < 10)
    Serial.print('0');
  Serial.print(digits);
}

void setup(){
  Serial.begin(9600);
  pinMode(relay, OUTPUT);
  setTime(0,0,0,1,1,18);
  digitalWrite(relay, LOW);
}

void loop(){
  if(hour() <= houron){
    if(hour() >= houroff){
      Serial.print(hour());
      printDigits(minute());
      printDigits(second());
      Serial.println();
      if(minute()+(hour()*60) < minon+(houron*60)){
        if(minute()+(hour()*60) >= minoff+(houroff*60)){
          digitalWrite(relay, HIGH);
        }
      }else{
        digitalWrite(relay, LOW);
      }
    }
  }
  delay(10000);
}

/*
 * 112:34:56
#include "TimeLib.h"
const int relay = 13;
float timeon;
float timeoff;
float n;

void printDigits(int digits){
  Serial.print(":");
  if(digits < 10)
    Serial.print('0');
  Serial.print(digits);
}

void setup(){
  Serial.begin(9600);
  pinMode(relay, OUTPUT);
  setTime(12,0,0,1,1,18);
}

void loop(){
  if(Serial.available()){
    n = Serial.read();
    Serial.println(n, DEC);
  }
  Serial.print(hour());
  printDigits(minute());
  printDigits(second());
  Serial.println();
  delay(1000);
}


*/
