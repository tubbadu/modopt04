#ifndef TLC_H
#define TLC_H

enum color{ RED , YELLOW , GREEN };
SC_MODULE(TLC)
{ 
	public :
	sc_in<bool> car ;
	sc_out<color> M , S ;
	sc_in<bool> sec_5;
	sc_out<bool> start;
	
	SC_CTOR(TLC)  // Constructor
	: car("car"), M("Main"), S("Secondary"), sec_5("sec_5"), start("start") {
		
		SC_THREAD( TLC_run ) ;
	} 
	void TLC_run ( ) 
	{ 
		M.write(GREEN); // initialization
		S.write(RED);
		start.write(false);
		
		while (1) 
		{ 	
			wait5sec();
			wait5sec();
			if (!car) // wait until car arrives at Secondary
			    wait(car.posedge_event()) ;
			wait5sec();  
			M.write(YELLOW);
			wait5sec();
			M.write(RED);
			S.write(GREEN);
			wait5sec();
			S.write(YELLOW);
			wait5sec();
			S.write(RED);
			M.write(GREEN);
		} 
	}

	void wait5sec(){
		start.write(true); // TODO make sure it is low
		wait(sec_5.posedge_event());
		start.write(false);
		wait(SC_ZERO_TIME); // because otherwise it refuses to work :( 
	}
};

#endif
