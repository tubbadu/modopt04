#include <iostream>
#include <string>
#include <systemc.h>
#include "semafero.h"

#define caryes car.write(true); cout << "LOG: car yes" << endl;
#define carno car.write(false); cout << "LOG: car no more yes" << endl;

using namespace std;

SC_MODULE(testbench){
    sc_in<semafero::color> M, S;
    sc_out<bool> car;


    SC_CTOR(testbench){
        SC_THREAD(tvb_car);
        SC_THREAD(tvb_yellow_M);
        SC_THREAD(tvb_yellow_S);
        SC_THREAD(tvb_green_M);
        SC_THREAD(tvb_green_S);
        SC_METHOD(tvb_combinations);
            sensitive << M << S;
    }

    void tvb_green_M();
    void tvb_green_S();
    void tvb_yellow_M();
    void tvb_yellow_S();
    void tvb_combinations();
    void tvb_car();
};
