#include "semafero.h"

void semafero::controller(){
    const sc_time t_10sec(10, SC_SEC);
    const sc_time t_5sec(5, SC_SEC);
    for(;;){
        M.write(GREEN);
        S.write(RED);
        wait(t_10sec);
        while(!car){
            wait(car.default_event());
        }
        M.write(YELLOW);
        wait(t_5sec);
        M.write(RED);
        S.write(GREEN);
        wait(t_10sec);
        S.write(YELLOW);
        wait(t_5sec);
    }
}
