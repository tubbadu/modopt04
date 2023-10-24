#include "systemc.h"
#include <iostream>
using std::cout;
using std::endl;

SC_MODULE(Testbench) {
	sc_in<sc_logic> s, c_out;	// declare an output port
	sc_out<sc_logic> a, b, c_in;	// declare an input port

	SC_CTOR(Testbench) {
		SC_THREAD(Testbench_thread);

        SC_METHOD(Testbench_method);
        sensitive << s << c_out;
	}

	void Testbench_thread(void);
    void Testbench_method(void);
};