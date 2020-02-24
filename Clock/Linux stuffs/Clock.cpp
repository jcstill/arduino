#include <iostream>
#include <iomanip>
#include <fstream>
#include <chrono>
#include <thread>

#define SCREEN 1

using namespace std;


void printt(){
	// Get the time
	time_t timz = time(0);
	tm *theTime = localtime(&timz);
	int hr = theTime->tm_hour;
	
	
	// Print to serial
	ofstream srlclk;
	srlclk.open("/dev/ttyUSB0");
	if(hr > 12){
		srlclk << right << setfill('0') << setw(2) << hr-12;
	}else{
		srlclk << hr;
	}
	srlclk << ':' << right << setfill('0') << setw(2) << theTime->tm_min << ':' << right << setfill('0') << setw(2) << theTime->tm_sec << '\n';
	srlclk.close();
	
	// if(SCREEN){
		// if(hr > 12){
			// cout << right << setfill('0') << setw(2) << hr-12;
		// }else{
			// cout << hr;
		// }
		// cout << ':' << right << setfill('0') << setw(2) << theTime->tm_min << ':' << right << setfill('0') << setw(2) << theTime->tm_sec << '\n';
	// }
}

int main(){
	using namespace std::this_thread; // sleep_for, sleep_until
    using namespace std::chrono; // nanoseconds, system_clock, seconds

    
	while(1){
		printt();
		sleep_until(system_clock::now() + seconds(1));
	}
}