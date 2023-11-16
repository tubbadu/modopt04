#ifndef OS_DRIVERS_H
#define OS_DRIVERS_H

// Here you must implement a module that implements all three interfaces
static const char *NAMES[] = { "RED", "YELLOW", "GREEN" };

SC_MODULE(OS_drivers), public light_if, public timer_if, public car_if {
	
	SC_CTOR(OS_drivers){ } // Nothing to do
	
	virtual void set_main(color c) {
		cout << sc_time_stamp() << " main " << NAMES[c]) << endl; 
	}
	virtual void set_sec(color c) {
		cout << sc_time_stamp() << " sec. " << NAMES[c]) << endl;
	}
	virtual void wait_for_car() {
		time_t start = time(); // Since 01/01/1970 in seconds
		cout << "Press enter when car arrives, or type STOP to end";
		string s;
		cin >> s; 
		if (s=="STOP") {
			sc_stop();
		}
		wait(time() – start, SC_SEC);
	}
	virtual void wait_for_sec(unsigned int s) {
		sleep(s * 1000); // Sleep for s*1000 milliseconds
		wait(s, SC_SEC); // advance simulation time
	}
	virtual void reset() {
		
	} 
};

#endif
