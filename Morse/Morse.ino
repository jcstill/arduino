char* morseLetters[] = {"01100001", "01100010", "01100011", "01100100", "01100101", "01100110", "01100111", "01101000", "01101001","01101010", "01101011", "01101100", "01101101", "01101110", "01101111", "01110000", "01110001", "01110010" ,"01110011", "01110100", "01110101", "01110110", "01110111", "01111000", "01111001", "01111010" };

void setup(){
  Serial.begin(9600);
}

void loop(){
  char info;
  if (Serial.available() > 0){
    info = Serial.read();
    if(info >= 'a' && info <= 'z'){
      letterId(morseLetters[info - 'a']);
    }else if(info >= 'A' && info <= 'Z'){
      letterId(morseLetters[info - 'A']);
    }else if(info == ' '){
      Serial.print("00100000 "); 
    }else{
      Serial.println();
    }
  }
}

void letterId(char* character){
  int i = 0;
   while(character[i] != '\0'){
    output(character[i]);
    i++;
  }
  Serial.print(" ");
}

void output(char ID){
  if (ID == '0'){
    Serial.print("0");          
  }else{
    Serial.print("1");          
  }
}
