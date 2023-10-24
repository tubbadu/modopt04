#include "Full_adder.h"

void Full_adder::full_adder_method(void) {
    sc_logic s1, c_out1, c_out2;
	s1 = b->read() ^ c_in->read();
    c_out1 = b->read() & c_in->read();
    c_out2 = a->read() ^ s1;
    s->write(a->read() & s1);
    c_out->write(c_out1 | c_out2);
	//cout << "Stim object '" << name() << "' sends out a value : " << cnt << " @ " << sc_time_stamp() << endl;
}
