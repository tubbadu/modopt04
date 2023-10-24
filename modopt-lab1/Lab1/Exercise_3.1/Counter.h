#include "systemc.h"

SC_MODULE (Counter){
    sc_int<16> min, max;

    SC_CTOR(Counter){
        min = 1;
        max = 20;

        SC_THREAD(printNumbers);
    }

    void printNumbers();
};