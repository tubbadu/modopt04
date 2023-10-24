#include "Testbench.h"

void Testbench::Testbench_thread(void) {
    sc_int<3> counter=0;
    do {
        counter--;
        a->write(counter.range(0,0));
        b->write(counter.range(1,1));
        c_in->write(counter.range(2,2));
        wait(10, SC_NS);
    } while (counter>0);
	cout << "a, b and c generated by are : " << a->read() << ", " << b->read() << "and " << c_in->read() << " @ " << sc_time_stamp() << endl;
}

void Testbench::Testbench_method (void) {
    cout << "s and c_out evaluated by the adder are " << s->read() << ", " << c_out->read() << " @ " << sc_time_stamp() << endl;
}