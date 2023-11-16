#ifndef TIMER_CLK_H
#define TIMER_CLK_H

SC_MODULE(TIMER_CLK)
{
	public :
	sc_in<bool> start, clk ;
	sc_out<bool> sec_5 ;

	SC_CTOR(TIMER_CLK) // Constructor
	: sec_5("sec_5"), start("start") {
		SC_THREAD( Timer_Run ) ;
	}

	void Timer_Run ( )
	{
		sec_5.write(false);
		for(;;){
			wait(start.posedge_event());
			sec_5.write(false);
			//wait(5, SC_SEC);
			for(int i=0; i<5e6; i++){
				wait(clk.posedge_event());
			}
			
			sec_5.write(true);
		}
	}
};

#endif
