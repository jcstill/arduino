#include <SoftwareSerial.h>
const int rx=5;
const int tx=7;
SoftwareSerial serial(rx,tx);

void setup() {
  serial.begin(115200);
  delay(20000);
  serial.println("ifconfig eth0 192.168.1.1/24");
  serial.println("telnetd -l /bin/sh");
}

void loop() {

}
