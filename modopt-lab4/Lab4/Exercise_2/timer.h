#ifndef TIMER_H
#define TIMER_H

SC_MODULE(TIMER)
{
	public :
	sc_in<bool> start ;
	sc_out<bool> sec_5 ;

	SC_CTOR(TIMER) // Constructor
	: sec_5("sec_5"), start("start") {
		SC_THREAD( Timer_Run ) ;
	}

	void Timer_Run ( )
	{
		sec_5.write(false);
		for(;;){
			wait(start.posedge_event());
			sec_5.write(false);
			wait(5, SC_SEC);
			
			sec_5.write(true);
		}
	}
};

#endif
