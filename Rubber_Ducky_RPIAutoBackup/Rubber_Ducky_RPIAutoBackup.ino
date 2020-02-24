/*

  Made By Jacob Still
  Published March 1, 2018
  
  This sketch injects keystrokes (like a rubber ducky)
  that take all the files in folder "AutoBackup"
  on a windows box and uploads to a Raspberry Pi via scp

  REQUIREMENTS TO FUNCTION:
  -Windows 10 with Bash on Ubuntu on Windows installed
  -Raspberry Pi on same network

  Commands Injected:
    Command Prompt:
      cls
      bash
      exit
    Linux (Inside bash):
      clear
      scp -r /mnt/c/Users/USERNAME/Desktop/AutoBackup/ pi@192.168.1.15:/home/pi/
      echo scp succeded
      cd /mnt/c/Users/USERNAME/Desktop
      echo cd succeded
      read -p \"would you like to delete files on local machine? \" -a prompt -t 5
      if [ $prompt = \"y\" ];then 
        rm -r AutoBackup/
        mkdir AutoBackup
        echo rm succeded
        echo Operation Failed
      ;
      elif [ $prompt = \"n\" ];then 
        echo Not Deleting Files
      ;
      else
        echo Not Deleting Files
      exit;
      fi
      exit
      echo Not Deleting Files
      exit
    In single Line form:
      clear && scp -r /mnt/c/Users/USERNAME/Desktop/AutoBackup/ pi@192.168.1.15:/home/pi/ && echo scp succeded && cd /mnt/c/Users/USERNAME/Desktop && echo cd succeded && read -p \"would you like to delete files on local machine? \" -a prompt -t 5 && if [ $prompt = \"y\" ]; then rm -r AutoBackup/ && mkdir AutoBackup && echo rm succeded || echo Operation Failed; elif [ $prompt = \"n\" ]; then echo Not Deleting Files; else echo Not Deleting Files && exit; fi && exit || echo Not Deleting Files && exit

*/
#include "Keyboard.h"

String foldloc = "/mnt/c/Users/USERNAME/Desktop/"; //path to AutoBackup (in bash, excluding AutoBackup itself)
String address = "192.168.1.15"; //IP of Pi (recommeded to use static on router)
String PASSWORD = "PASSWORD"; //Password

void typeKey(int key){
  Keyboard.press(key);
  delay(50);
  Keyboard.release(key);
}

void setup(){
  Keyboard.begin();
  delay(750);
  
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('r');
  Keyboard.releaseAll();
  delay(100);
  
  Keyboard.print("cmd");
  typeKey(KEY_RETURN);
  Keyboard.releaseAll();
  delay(100);
  
  Keyboard.print("cls && bash && exit");
  typeKey(KEY_RETURN);
  Keyboard.releaseAll();
  delay(600);

  Keyboard.print("clear && scp -r ");
  Keyboard.print(foldloc);
  Keyboard.print("AutoBackup/ pi@");
  Keyboard.print(address);
  Keyboard.print(":/home/pi/ && echo scp succeded && cd ");
  Keyboard.print(foldloc);
  Keyboard.print(" && echo cd succeded && read -p \"would you like to delete files on local machine? \" -a prompt -t 5 && if [ $prompt = \"y\" ]; then rm -r AutoBackup/ && mkdir AutoBackup && echo rm succeded || echo Operation Failed; elif [ $prompt = \"n\" ]; then echo Not Deleting Files; else echo Not Deleting Files && exit; fi && exit || echo Not Deleting Files && exit");
  typeKey(KEY_RETURN);

  Keyboard.releaseAll();
  delay(3000);

  Keyboard.print(PASSWORD);
  typeKey(KEY_RETURN);

  Keyboard.releaseAll();
  Keyboard.end();
}

// Not used
void loop(){
}
