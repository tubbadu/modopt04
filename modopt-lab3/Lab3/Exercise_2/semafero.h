#ifndef SEMAFERO_H
#define SEMAFERO_H

#include <iostream>
#include <string>
using namespace std;
#include <systemc.h>

SC_MODULE(semafero){
    enum color {
        RED,
        YELLOW,
        GREEN
    };

    sc_in<bool> car;
    sc_out<color> M, S;


    SC_CTOR(semafero){
        SC_THREAD(controller);
    }

    void controller();
};
#endif
