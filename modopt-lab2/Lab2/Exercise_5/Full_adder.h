#include "systemc.h"
#include <iostream>
using std::cout;
using std::endl;

SC_MODULE(Full_adder) {
	sc_out<sc_logic> s, c_out;	// declare an output port
	sc_in<sc_logic>	a, b, c_in;	// declare an input port

	SC_CTOR(Full_adder) {
		SC_METHOD(full_adder_method);
		sensitive << a << b << c_in;
	}

	void full_adder_method(void);
};