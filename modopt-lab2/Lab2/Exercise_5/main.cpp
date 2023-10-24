#include "systemc.h"
#include "Testbench.h"
#include "Full_adder.h"

int sc_main(int argc, char * argv[]) {
	sc_signal<sc_logic>	channela;	// define a channel
	sc_signal<sc_logic>	channelb;
	sc_signal<sc_logic>	channelcin;
	sc_signal<sc_logic>	channels;
	sc_signal<sc_logic>	channelcout;

	Full_adder	adder("Full_adder_Obj");
	Testbench	tb("Testbench_Obj");

	adder.s(channels);	// connect Stim_inst's output port "out" to channel1
	adder.c_out(channelcout);
	adder.a(channela);		// connect Stim_inst's input port "in" to channel2
	adder.b(channelb);
	adder.c_in(channelcin);

	tb.s(channels);	// connect Stim_inst's output port "out" to channel1
	tb.c_out(channelcout);
	tb.a(channela);		// connect Stim_inst's input port "in" to channel2
	tb.b(channelb);
	tb.c_in(channelcin);

	sc_start();

	return 0;
}