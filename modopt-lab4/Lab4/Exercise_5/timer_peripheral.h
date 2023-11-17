#ifndef TIMER_PERIPHERAL_H
#define TIMER_PERIPHERAL_H


// This must implement the bus interface for the timer functionality


SC_MODULE(TIMER_PERIPHERAL), public bus_if {
	sc_uint<32> control, max_value, counter;
	
	sc_event start;
	sc_in<bool> clk;
	
	SC_CTOR(TIMER_PERIPHERAL){
		SC_THREAD(count);
		sensitive << clk.pos();
	}
	
	void count() {
		counter = 0;
		control = 0;
		max_value = 0;
		
		wait(start);
		
		for(;;){
			wait();
			counter++;
			
			if(counter >= max_value){
				// control = control | 0b100;
				control[2] = true;
				counter = 0;
				
				if(!control[1]){
					wait(start);
				}
			}
		}
	}
	
	virtual void write(sc_uint<32> addr, sc_uint<32> data) {
		switch (addr) {
			case 0: 
				counter = data; 
				start.notify(SC_ZERO_TIME);  // we will keep it but we're angry about it
				break;
			case 1: 
				max_value = data; 
				break;
			case 2: 
				control = data;
				control[2] = false;
				break;
		}
	}
	
	virtual sc_uint<32> read(sc_uint<32> addr) {
		sc_uint<32> result;
		switch (addr) {
			case 0: 
				result = counter; 
				break;
			case 1: 
				result = max_value; 
				break;
			case 2: 
				result = control; 
				break;
			default:
				SC_REPORT_ERROR(name(), "read address not correct");
				break;
		}
		return result;
	}
};

#endif
	