#include "systemc.h"
#include "Counter.h"

int sc_main(int argc, char* argv[]) {
    Counter pippo("pippo");

    sc_start();

    return 0;
}