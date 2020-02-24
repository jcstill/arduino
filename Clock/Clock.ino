char get_l;
char tim[8];
int count =0;

void dispt(char tim[8]){
  
}

void setup(){
	Serial.begin(9600);
}

void loop(){
	if(Serial.available()){
		get_l = Serial.read();
	tim[count] = get_l;
	count++;
	}
	if(count == 8){
		count = 0;
	}
	dispt(tim);
}
