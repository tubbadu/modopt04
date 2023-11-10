#include "testbench.h"

void testbench::tvb_yellow_M(){
    const sc_time t_10sec(10, SC_SEC);
    const sc_time t_5sec(5, SC_SEC);      sc_time time_on;
    for(;;){
        while(M != semafero::YELLOW){
            wait(M.default_event());
        }
        // M just diventato yellow
        time_on = sc_time_stamp();
        wait(t_5sec, M.default_event());
        if(M.read() != semafero::RED || (sc_time_stamp() - time_on != t_5sec)){ // TODO add tolerance
            cerr << "ERROR: Main yellow light bad" << endl;
        } else {
            cout << "LOG: Main yellow light good" << endl;
        }
    }
}

void testbench::tvb_yellow_S(){
    const sc_time t_10sec(10, SC_SEC);
    const sc_time t_5sec(5, SC_SEC);      sc_time time_on;
    for(;;){
        while(S != semafero::YELLOW){
            wait(S.default_event());
        }
        // S just diventato yellow
        time_on = sc_time_stamp();
        wait(t_5sec, S.default_event());
        if(S.read() != semafero::RED || (sc_time_stamp() - time_on != t_5sec)){ // TODO add tolerance
            cerr << "ERROR: Secondary yellow light bad" << endl;
        } else {
            cout << "LOG: Secondary yellow light good" << endl;
        }
    }
}

void testbench::tvb_green_M(){
    const sc_time t_10sec(10, SC_SEC);
    const sc_time t_5sec(5, SC_SEC);      sc_time time_on;
    for(;;){
        while(M != semafero::GREEN){
            wait(M.default_event());
        }
        // M just diventato verde
        time_on = sc_time_stamp();
        wait(t_10sec, M.default_event());
        if(M.read() != semafero::YELLOW || (sc_time_stamp() - time_on < t_10sec)){ // TODO add tolerance
            cerr << "ERROR: Main green light bad" << endl;
        } else {
            cout << "LOG: Main green light good" << endl;
        }
    }
}
void testbench::tvb_green_S(){
    const sc_time t_10sec(10, SC_SEC);
    const sc_time t_5sec(5, SC_SEC);      sc_time time_on;
    for(;;){
        while(S != semafero::GREEN){
            wait(S.default_event());
        }
        // S just diventato verde
        time_on = sc_time_stamp();
        wait(t_10sec, S.default_event());
        if(S.read() != semafero::YELLOW || (sc_time_stamp() - time_on != t_10sec)){ // TODO add tolerance
            cerr << "ERROR: S green light bad" << endl;
        } else {
            cout << "LOG: S green light good" << endl;
        }
    }
}


void testbench::tvb_combinations(){
    if(M.read() == semafero::GREEN){
        if(S.read() != semafero::RED){
            cerr << "ERROR: M green and S not red: lights bad" << endl;
        }
    } else if(M.read() == semafero::YELLOW){
        if(S.read() != semafero::RED){
            cerr << "ERROR: M yellow and S not red: lights bad" << endl;
        }
    } else if(M.read() == semafero::RED){
        if(S.read() == semafero::RED){
            cerr << "ERROR: M red and S red: lights bad" << endl;
        }
    } else {
        cerr << "ERROR: unknown light code for M:" << M.read() << endl;
    }
}

void testbench::tvb_car(){
    cout << "LOG: long time testing v1" << endl;
    carno
    wait(50, SC_SEC);
    cout << "LOG: long time testing v2" << endl;
    caryes
    wait(50, SC_SEC);
    cout << "LOG: random testing" << endl;
    for(int i=0; i<30; i++){
        carno
        wait(rand()*40 + 10, SC_SEC);
        caryes
        wait(rand()*40 + 10, SC_SEC);
    }
    cout << "LOG: bad driver testing" << endl;
    while(S != semafero::RED){
        wait(S.default_event());
    }
    wait(1, SC_SEC);
    carno
    wait(20, SC_SEC);
}
