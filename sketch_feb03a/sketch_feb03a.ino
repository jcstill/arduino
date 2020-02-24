#include<Wire.h>
#include<Servo.h>
Servo xservo;
Servo yservo;
unsigned long pMillis = 0;
unsigned long cMillis;
int CDSet = 0;
int g = 0;
const int MPU_addr=0x68;  // I2C address of the MPU-6050
int16_t AcX,AcY,Tmp;
int16_t mAcX,mAcY;
int ypos = 0;
int xpos = 0;

int countdown = 10;
const long FinSens = 10;
int limit = 2;
int xang = 0; //degrees from 0 (vertical)
int yang = 0; // (WIP)

void UpdateFins(){
  cMillis = millis();
  if (cMillis - pMillis >= FinSens) {
    pMillis = cMillis;
    //Serial.print("X "); Serial.println(xpos);
    //Serial.print("Y "); Serial.println(ypos);
    //Serial.print(" | Tmp = "); Serial.println(((Tmp/340.00+36.53)*1.8)+32);  //equation for temperature in degrees C from datasheet
    xservo.write(xpos);
    yservo.write(ypos);
  }
}

void LimitCalc(){
  if(limit == 2){
    xpos = (mAcX/limit) + 45;
    ypos = (mAcY/limit) + 45;
  }else if(limit == 3){
    xpos = (mAcX/limit) + 60;
    ypos = (mAcY/limit) + 60;
  }else if(limit == 4){
    xpos = (mAcX/limit) + 67.5;
    ypos = (mAcY/limit) + 67.5;
  }else if(limit == 5){
    xpos = (mAcX/limit) + 72;
    ypos = (mAcY/limit) + 72;
  }else if(limit == 6){
    xpos = (mAcX/limit) + 75;
    ypos = (mAcY/limit) + 75;
  }else{
    xpos = 90;
    ypos = 90;
    return;
  }
  if((xpos%2)!=0){
    xpos = xpos + 1;
  }
  if((ypos%2)!=0){
    ypos = ypos + 1;
  }
}

void UpdateHeading(){
  ypos = ypos + yang;
  xpos = xpos + xang;
}

void Countdown(){
  int l = 0;
  while(l < countdown){
    digitalWrite(13, HIGH);
    delay(250);
    digitalWrite(13, LOW);
    delay(750);
    l = l + 1;
  }
  CDSet = 1;
}

void setup(){
  Wire.begin();
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x6B);  // PWR_MGMT_1 register
  Wire.write(0);     // set to zero (wakes up the MPU-6050)
  Wire.endTransmission(true);
  xservo.attach(9);
  yservo.attach(8);
  Serial.begin(9600);
}

void loop(){
  while(Serial.available() > 0){
    yang = Serial.parseInt();
  }
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x3B);  // starting with register 0x3B (ACCEL_XOUT_H)
  Wire.endTransmission(false);
  Wire.requestFrom(MPU_addr,14,true);  // request a total of 14 registers
  AcX=Wire.read()<<8|Wire.read();  // 0x3B (ACCEL_XOUT_H) & 0x3C (ACCEL_XOUT_L)    
  AcY=Wire.read()<<8|Wire.read();  // 0x3D (ACCEL_YOUT_H) & 0x3E (ACCEL_YOUT_L)
  Wire.read()<<8|Wire.read();
  Tmp=Wire.read()<<8|Wire.read();  // 0x41 (TEMP_OUT_H) & 0x42 (TEMP_OUT_L)

  mAcX = map(AcX, -17000, 17000, 0, 180);
  mAcY = map(AcY, -17000, 17000, 0, 180);

  if(CDSet < 1){
    Countdown();
  }else if(CDSet = 1){
    if(g < 2){
      digitalWrite(13, HIGH);
      delay(50);
      digitalWrite(13, LOW);
      delay(50);
      g = g + 1;
    }
    CDSet = 2;
  }
  LimitCalc();
  UpdateHeading();
  UpdateFins();
}









