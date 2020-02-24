#include "SPI.h"
#include "MFRC522.h"
#define SS_PIN 10
#define RST_PIN 5
#define KEY_RETURN 0xB0                       // Hex value for return key.
 
MFRC522 mfrc522 (SS_PIN, RST_PIN);
char Enter = KEY_RETURN;                      // Return key is declared Enter.
String readid;
String card1 = "80429a4";                     // UID of card/device.
unsigned long previousMillis = 0;             // Stores last time Serial was sent.
const long interval = 1000;                  // Interval to send Serial (milliseconds).

void setup(){
  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();
}

void temp(byte *buffer, byte bufferSize){     // Store UID as string datatype.
  readid="";
  for(byte i = 0;i<bufferSize; i++){
    readid=readid+String(buffer[i], HEX);
  }
}

void loop(){
  if(!mfrc522.PICC_IsNewCardPresent()){
    return;
  }
  if(!mfrc522.PICC_ReadCardSerial()){
    return;
  }
  mfrc522.PICC_DumpToSerial(&(mfrc522.uid));   // Display card details in serial Monitor.
  temp(mfrc522.uid.uidByte, mfrc522.uid.size);
  if(readid==card1){ 
    Serial.println(".");
  }else{
   return;
  }
  unsigned long currentMillis = millis();     // This helps with keeping ATmegaU32 connected on COM
  if (currentMillis - previousMillis >= interval){
    previousMillis = currentMillis;
    //Serial.println();
  }
}
