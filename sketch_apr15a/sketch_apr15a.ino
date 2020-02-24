/**
 * This sketch programs the microcode EEPROMs for the 8-bit breadboard computer
 * See this video for more: https://youtu.be/JUVt_KYAp-I
 */
#define SHIFT_DATA 2
#define SHIFT_CLK 3
#define SHIFT_LATCH 4
#define EEPROM_D0 5
#define EEPROM_D7 12
#define WRITE_EN 13

#define HLT 0b10000000000000000000000000000000  // Halt clock
#define MI  0b01000000000000000000000000000000  // Memory address register in
#define RI  0b00100000000000000000000000000000  // RAM data in
#define RO  0b00010000000000000000000000000000  // RAM data out
#define IO  0b00001000000000000000000000000000  // Instruction register out
#define II  0b00000100000000000000000000000000  // Instruction register in
#define AI  0b00000010000000000000000000000000  // A register in
#define AO  0b00000001000000000000000000000000  // A register out
#define EO  0b00000000100000000000000000000000  // ALU out
#define SU  0b00000000010000000000000000000000  // ALU subtract
#define BI  0b00000000001000000000000000000000  // B register in
#define OI  0b00000000000100000000000000000000  // Output register in
#define CE  0b00000000000010000000000000000000  // Program counter enable
#define CO  0b00000000000001000000000000000000  // Program counter out
#define J   0b00000000000000100000000000000000  // Jump (program counter in)
#define RRC 0b00000000000000010000000000000000  // Reset ring counter

#define F   0b11111111111111111111111111111111
#define ZR  0b00000000000000000000000000000000

uint32_t data[] = {
  MI|CO,      RO|II|CE,  RRC,       0,          0,          0,          0,          0,          // 0000 - NOP
  MI|CO,      RO|II|CE,  IO|MI,     RO|AI,      RRC,        0,          0,          0,          // 0001 - LDA
  MI|CO,      RO|II|CE,  IO|MI,     RO|BI,      EO|AI,      RRC,        0,          0,          // 0010 - ADD
  MI|CO,      RO|II|CE,  IO|MI,     RO|BI,      EO|AI|SU,   RRC,        0,          0,          // 0011 - SUB
  MI|CO,      RO|II|CE,  IO|MI,     AO|RI,      RRC,        0,          0,          0,          // 0100 - STA
  MI|CO,      RO|II|CE,  IO|AI,     RRC,        0,          0,          0,          0,          // 0101 - LDI
  MI|CO,      RO|II|CE,  IO|J,      RRC,        0,          0,          0,          0,          // 0110 - JMP
  MI|CO,      RO|II|CE,  RRC,       0,          0,          0,          0,          0,          // 0111
  MI|CO,      RO|II|CE,  RRC,       0,          0,          0,          0,          0,          // 1000
  MI|CO,      RO|II|CE,  RRC,       0,          0,          0,          0,          0,          // 1001
  MI|CO,      RO|II|CE,  RRC,       0,          0,          0,          0,          0,          // 1010
  MI|CO,      RO|II|CE,  RRC,       0,          0,          0,          0,          0,          // 1011
  MI|CO,      RO|II|CE,  RRC,       0,          0,          0,          0,          0,          // 1100
  MI|CO,      RO|II|CE,  RRC,       0,          0,          0,          0,          0,          // 1101
  MI|CO,      RO|II|CE,  AO|OI,     RRC,        0,          0,          0,          0,          // 1110 - OUT
  HLT|RRC,    0,         0,         0,          0,          0,          0,          0,          // 1111 - HLT
};


/*
 * Output the address bits and outputEnable signal using shift registers.
 */
void setAddress(int address, bool outputEnable) {
  shiftOut(SHIFT_DATA, SHIFT_CLK, MSBFIRST, (address >> 8) | (outputEnable ? 0x00 : 0x80));
  shiftOut(SHIFT_DATA, SHIFT_CLK, MSBFIRST, address);

  digitalWrite(SHIFT_LATCH, LOW);
  digitalWrite(SHIFT_LATCH, HIGH);
  digitalWrite(SHIFT_LATCH, LOW);
}


/*
 * Read a byte from the EEPROM at the specified address.
 */
byte readEEPROM(int address) {
  for (int pin = EEPROM_D0; pin <= EEPROM_D7; pin += 1) {
    pinMode(pin, INPUT);
  }
  setAddress(address, /*outputEnable*/ true);

  byte data = 0;
  for (int pin = EEPROM_D7; pin >= EEPROM_D0; pin -= 1) {
    data = (data << 1) + digitalRead(pin);
  }
  return data;
}


/*
 * Write a byte to the EEPROM at the specified address.
 */
void writeEEPROM(int address, byte data) {
  setAddress(address, /*outputEnable*/ false);
  for (int pin = EEPROM_D0; pin <= EEPROM_D7; pin += 1) {
    pinMode(pin, OUTPUT);
  }

  for (int pin = EEPROM_D0; pin <= EEPROM_D7; pin += 1) {
    digitalWrite(pin, data & 1);
    data = data >> 1;
  }
  digitalWrite(WRITE_EN, LOW);
  delayMicroseconds(1);
  digitalWrite(WRITE_EN, HIGH);
  delay(10);
}


/*
 * Read the contents of the EEPROM and print them to the serial monitor.
 */
void printContents() {
  for (int base = 0; base <= 2047; base += 16) {
    byte data[16];
    for (int offset = 0; offset <= 15; offset += 1) {
      data[offset] = readEEPROM(base + offset);
    }

    char buf[80];
    sprintf(buf, "%04x:  %02x %02x %02x %02x %02x %02x %02x %02x   %02x %02x %02x %02x %02x %02x %02x %02x",
            base, data[0], data[1], data[2], data[3], data[4], data[5], data[6], data[7],
            data[8], data[9], data[10], data[11], data[12], data[13], data[14], data[15]);

    Serial.println(buf);
  }
}


void setup() {
  // put your setup code here, to run once:
  pinMode(SHIFT_DATA, OUTPUT);
  pinMode(SHIFT_CLK, OUTPUT);
  pinMode(SHIFT_LATCH, OUTPUT);
  digitalWrite(WRITE_EN, HIGH);
  pinMode(WRITE_EN, OUTPUT);
  Serial.begin(57600);

  // Program data bytes
  Serial.print("Programming EEPROM");

  // Program the 8 high-high-order bits of microcode into the first 128 bytes of EEPROM
  for (int address = 0; address < sizeof(data)/sizeof(data[0]); address += 1) {
    writeEEPROM(address, data[address] >> 24);

    if (address % 64 == 0) {
      Serial.print(".");
    }
  }

  // Program the 8 high-low-order bits of microcode into the second 128 bytes of EEPROM
  for (int address = 0; address < sizeof(data)/sizeof(data[0]); address += 1) {
    writeEEPROM(address + 128, data[address] >> 16);

    if (address % 64 == 0) {
      Serial.print(".");
    }
  }

  // Program the 8 low-high-order bits of microcode into the third 128 bytes of EEPROM
  for (int address = 0; address < sizeof(data)/sizeof(data[0]); address += 1) {
    writeEEPROM(address + 256, data[address] >> 8);

    if (address % 64 == 0) {
      Serial.print(".");
    }
  }

  // Program the 8 low-low-order bits of microcode into the fourth 128 bytes of EEPROM
  for (int address = 0; address < sizeof(data)/sizeof(data[0]); address += 1) {
    writeEEPROM(address + 384, data[address]);

    if (address % 64 == 0) {
      Serial.print(".");
    }
  }


  Serial.println(" done");


  // Read and print out the contents of the EERPROM
  Serial.println("Reading EEPROM");
  printContents();
}


void loop() {
  // put your main code here, to run repeatedly:

}

