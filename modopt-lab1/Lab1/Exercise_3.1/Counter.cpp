#include "Counter.h"

void Counter::printNumbers(){

    const sc_time t_20ns(20, SC_NS);
    sc_time t_DELAY(t_20ns);
    for(int i = max; i >= min; i--){
        wait(t_DELAY);
        std::cout << i << std::endl;
        std::cout << "INFO: Time is " << sc_time_stamp() << "!" << std::endl;
    }
}