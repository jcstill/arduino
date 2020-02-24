#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);
#define NUMFLAKES 10
#define XPOS 0
#define YPOS 1
#define DELTAY 2
#define LOGO16_GLCD_HEIGHT 16 
#define LOGO16_GLCD_WIDTH  16 
#if (SSD1306_LCDHEIGHT != 64)
#error("Wrong Hieght. Fix Adafruit_SSD1306.h");
#endif
// Set Variables
int arrowx = 100;
int timeVal = 1;
float oldVal;
float inputVal;
String variable;
float top;
float btop;
float bot;
float percha;

void setup(){
  Serial.begin(9600);
  // Initial Display Sequence
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.fillCircle(42, 6, 2, WHITE);
  display.fillCircle(47, 3, 2, WHITE);
  display.fillCircle(47, 9, 2, WHITE);
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(60,0);
  display.println("XRP");
  display.setTextSize(3);
  display.setTextColor(WHITE);
  display.setCursor(0,16);
  display.println("$");
  display.setCursor(17,16);
  display.println("0.0000");
  display.display();
}

void loop(){
  while(Serial.available() > 0){
    // Get Serial Dada (for now, later will be from web using ehternet sheild)
    variable = Serial.readString();
    inputVal = variable.toFloat();
    // Display Sequence for Icon and "XRP"
    display.clearDisplay();
    display.fillCircle(42, 6, 2, WHITE);
    display.fillCircle(47, 3, 2, WHITE);
    display.fillCircle(47, 9, 2, WHITE);
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setCursor(60,0);
    display.println("XRP");
    // Display Sequence for Value of XRP
    display.setTextSize(3);
    display.setTextColor(WHITE);
    display.setCursor(0,16);
    display.println("$");
    display.setCursor(17,16);
    // Moving Decimal for Easy Reading and no Overflow
    if(inputVal < 10){
      display.println(inputVal, 4);
    }else if(inputVal < 100){
      display.println(inputVal, 3);
    }else if(inputVal < 1000){
      display.println(inputVal, 2);
    }else if(inputVal < 10000){
      display.println(inputVal, 1);
    }else if(inputVal > 999999){
      display.println("-E-");
    }else{
      display.println(inputVal, 0);
    }
    // Display Sequence for Change Icon (up/down arrow, flat bar)
    if(inputVal > oldVal){
      // Up Arrow
      display.drawLine(arrowx+1, 64, arrowx+26, 39, WHITE);
      display.drawLine(arrowx, 64, arrowx+26, 38, WHITE);
      display.drawLine(arrowx, 63, arrowx+25, 39, WHITE);
      display.fillTriangle(arrowx+1, 38, arrowx+26, 38, arrowx+27, 64, WHITE);
    }else if(inputVal < oldVal){
      // Down Arrow
      display.drawLine(arrowx+1, 38, arrowx+26, 63, WHITE);
      display.drawLine(arrowx, 38, arrowx+26, 64, WHITE);
      display.drawLine(arrowx, 39, arrowx+25, 64, WHITE);
      display.fillTriangle(arrowx+1, 64, arrowx+26, 38, arrowx+27, 64, WHITE);
    }else if(inputVal = oldVal){
      // Flat Bar
      display.drawLine(arrowx, 50, arrowx+26, 50, WHITE);
      display.drawLine(arrowx, 51, arrowx+26, 51, WHITE);
      display.drawLine(arrowx, 52, arrowx+26, 52, WHITE);
    }
    // Percent Change Calculation
    top = inputVal - oldVal;
    bot = abs(oldVal);
    percha = top / bot * 100;
    percha = abs(percha);
    // Display Sequence for Percent Change
    display.setTextSize(3);
    display.setTextColor(WHITE);
    display.setCursor(0,40);
    // Formatting of Percent Change
    if(inputVal != oldVal){
      if(percha < 9.99){
        display.println(percha, 2);
        display.setCursor(72,40);
        display.println("%");
      }else if(percha < 99.99){
        display.println(percha, 1);
        display.setCursor(72,40);
        display.println("%");
      }else if(percha < 999.9){
        display.println(percha, 0);
        display.setCursor(54,40);
        display.println("%");
      }else if(percha > 1000){
        display.println("-E-");
      }
    }else if(inputVal = oldVal){
      display.println("nochg");
    }
    display.display();  // Actually displaying everything from the top of void loop()
    oldVal = inputVal;  // Used for Percent Change and Change Icon
  }
}














