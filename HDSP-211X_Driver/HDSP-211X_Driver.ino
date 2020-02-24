#define	WRTDSP		2
#define	DISD0		3
#define	DISD6		9
#define DISA0		10
#define DISA2		12
#define RST			13

#define HRFMT		12
#define SETTIME		12:00



void displayWrite(const char myChar[]){
	char tmp;
	int tmpin;
	for(int i=0; i<8; i++){
		tmp = myChar[i];
		tmpin = i;
		// Set Address
		for(int pin=DISA0; pin<=DISA2; pin++){
			digitalWrite(pin, tmpin & 1);
			tmpin = tmpin >> 1;
		}
		// Set Data
		for(int pin=DISD0; pin<=DISD6; pin++){
			digitalWrite(pin, tmp & 1);
			tmp = tmp >> 1;
		}
		// Write Data
		digitalWrite(WRTDSP, LOW);
		digitalWrite(WRTDSP, HIGH);
	}
}

void scrollText(const char myChar[]){
	char tmp[8];
	for(int i=0; i<28; i++){
		for(int w=0; w<8; w++){
			tmp[w] = myChar[w+i];
		}
		displayWrite(tmp);
		delay(115);
	}
}

char timeTmp[8] = {" 00:00  "};
int hr = 0;

void setup(){
	pinMode(RST, OUTPUT);
	digitalWrite(RST, LOW);		// Hold LOW till ready to display
	pinMode(WRTDSP, OUTPUT);
	digitalWrite(WRTDSP, HIGH);
	for(int pin=DISD0; pin<=DISD6; pin++){
		pinMode(pin, OUTPUT);
	}
	for(int pin=DISA0; pin<=DISA2; pin++){
		pinMode(pin, OUTPUT);
	}
	digitalWrite(RST, HIGH);
	displayWrite("        ");
	delay(1000);
	displayWrite("=       ");
	delay(400);
	displayWrite("==      ");
	delay(500);
	displayWrite("===     ");
	delay(450);
	displayWrite("====    ");
	delay(400);
	displayWrite("=====   ");
	delay(400);
	displayWrite("======  ");
	delay(550);
	displayWrite("======= ");
	delay(600);
	displayWrite("========");
	delay(450);
	displayWrite("--------");
	delay(700);
	displayWrite("        ");
	if(HRFMT == 12){
		timeTmp[1] = '1';
		timeTmp[2] = '2';
	}
	if(HRFMT == 24){
		timeTmp[1] = '0';
		timeTmp[2] = '0';
	}
}

void loop(){
	if(HRFMT == 12){
		if(hr > 12){
			timeTmp[6] = 'p';
		}else{
			timeTmp[6] = 'a';
		}
	}
	displayWrite(timeTmp);
	timeTmp[5]++;
	if(timeTmp[5] > 57){
			timeTmp[5] = 48;
			timeTmp[4]++;
	}
	if(timeTmp[4] > 53){
		timeTmp[4] = 48;
		timeTmp[2]++;
		hr++;
	}
	if(timeTmp[2] > 57){
		timeTmp[2] = 48;
		timeTmp[1]++;
	}
	if(HRFMT == 24){
		if(timeTmp[1] == 50){
			if(timeTmp[2] > 51){
				timeTmp[2] = 48;
				timeTmp[1] = 48;
			}
		}
	}else{
		if(timeTmp[1] == 49){
			if(timeTmp[2] > 50){
				timeTmp[2] = 49;
				timeTmp[1] = 48;
			}
		}
	}
	if(hr > 23){
		hr = 0;
	}
	delay(60000);
}














