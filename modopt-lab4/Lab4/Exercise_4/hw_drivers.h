#ifndef HW_DRIVERS_H
#define HW_DRIVERS_H

// Here you must implement a module that implements all three interfaces
// and has 3 I/O signals for car, main and secondary

SC_MODULE(HW_drivers), light_if, timer_if, car_if {
	sc_in<bool> car, clk; // Assuming 1 MHZ clock
	sc_out<color> M, S;
	SC_CTOR(HW_drivers){ }
	virtual void set_main(color c) {
		M.write(c);
	}
	virtual void set_sec(color c) {
		S.write(c);
	}
	virtual void wait_for_car() {
		while(car.read() == false) wait(clk.posedge_event());
	}
	virtual void wait_for_sec(unsigned int s) {
		for (int i = 0; i < 1e6 * s; i++)
			wait(clk.posedge_event());
	}
};

#endif
