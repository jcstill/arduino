#include <Servo.h>
Servo xaxis;
Servo yaxis;
int pos = 0;
int del = 150;

void setup() {
  xaxis.attach(2);
  yaxis.attach(3);
  xaxis.write(80);
  yaxis.write(80);
}

void loop() {
  xaxis.write(80);
  yaxis.write(80);
  delay(del);
  xaxis.write(100);
  yaxis.write(80);
  delay(del);
  xaxis.write(100);
  yaxis.write(100);
  delay(del);
  xaxis.write(80);
  yaxis.write(100);
  delay(del);
}
