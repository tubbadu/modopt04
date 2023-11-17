#ifndef TIMER_DRIVER_H
#define TIMER_DRIVER_H

// Here you must implement the timer_driver, withhave a port of type bus.

#define CLK_PER_SEC 1000000 // 1MHz clock
#define TIMER_COUNTER_ADDR 100
#define TIMER_MAX_VALUE_ADDR 104
#define TIMER_CONTROL_ADDR 108

SC_MODULE(TIMER_DRIVER), public timer_if{
	sc_port<bus_if> bus;
	
	SC_CTOR(TIMER_DRIVER): bus("bus"){
	}
	
	virtual void wait_for_sec(uint sec){
		bus->write(TIMER_MAX_VALUE_ADDR, sec * CLK_PER_SEC); // period
		bus->write(TIMER_CONTROL_ADDR, 0); // one-shot mode
		bus->write(TIMER_COUNTER_ADDR, 0); // restart timer
		while (!(bus->read(TIMER_CONTROL_ADDR)[2])) {
			//nop; // error???? or not error? // edit: yes, error
							// - William Shakespear, probably
		}
		
	}
};

#endif
