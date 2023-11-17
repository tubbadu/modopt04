#ifndef BUS_H
#define BUS_H

// This must implement the bus interface and have a port of type bus called 
// timer.

#define TIMER_COUNTER_ADDR 100
#define TIMER_MAX_VALUE_ADDR 104
#define TIMER_CONTROL_ADDR 108

const sc_time BUS_DELAY(1,SC_US); // 1MHZ bus clock

SC_MODULE(BUS), public bus_if {
	sc_port<bus_if> timer;
	SC_CTOR(BUS) { }
	virtual void write(sc_uint<32> addr, sc_uint<32> data) {
		switch (addr) {
			case TIMER_COUNTER_ADDR:
				timer->write(0, data); break;
			case TIMER_MAX_VALUE_ADDR: timer->write(1, data); break;
			case TIMER_CONTROL_ADDR:
				timer->write(2, data); break;
			default:
				SC_REPORT_ERROR(name(), "write address not correct");
				break;
		}
		wait(BUS_DELAY);
	}
	
	virtual sc_uint<32> read(sc_uint<32> addr) {
		sc_uint<32> result = 0;
		switch (addr) {
			case TIMER_COUNTER_ADDR:
				result = timer->read(0); break;
			case TIMER_MAX_VALUE_ADDR: result = timer->read(1); break;
			case TIMER_CONTROL_ADDR:
				result = timer->read(2); break;
			default:
				SC_REPORT_ERROR(name(), "read address not correct");
				break;
		}
		wait(BUS_DELAY);
		return result;
	}
};

#endif
