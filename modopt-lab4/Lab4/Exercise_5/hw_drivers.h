#ifndef HW_DRIVERS_H
#define HW_DRIVERS_H

// Here you must implement a module that implements all three interfaces
// and has 3 I/O signals for car, main and secondary

SC_MODULE(HW_DRIVERS), light_if, car_if {
	sc_in<bool> car, clk; // Assuming 1 MHZ clock
	sc_out<color> M, S;
	
	SC_CTOR(HW_DRIVERS){ }
	virtual void set_main(color c) {
		M.write(c);
	}
	virtual void set_sec(color c) {
		S.write(c);
	}
	virtual void wait_for_car() {
		while(car.read() == false) wait(clk.posedge_event());
	}
};

#endif
