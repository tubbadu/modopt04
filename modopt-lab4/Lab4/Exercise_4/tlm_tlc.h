#ifndef TLM_TLC_H
#define TLM_TLC_H

// Here you must model the TLM TLC

SC_MODULE(Abstract_TLC) {
public:
	sc_port<car_if> car;
	sc_port<timer_if> timer;
	sc_port<light_if> light;
	
	SC_CTOR(Abstract_TLC) {
		SC_THREAD(controller);
	}
	void controller() {
		//light->reset(); 
		//car->reset(); 
		//timer->reset();
		
		while (1) {
			light->set_sec(RED);
			light->set_main(GREEN);
			timer->wait_for_sec(10);
			car->wait_for_car();
			light->set_main(YELLOW);
			timer->wait_for_sec(5);
			light->set_main(RED);
			light->set_sec(GREEN);
			timer->wait_for_sec(10);
			light->set_sec(YELLOW);
			timer->wait_for_sec(5);
		}
	}
};

#endif
