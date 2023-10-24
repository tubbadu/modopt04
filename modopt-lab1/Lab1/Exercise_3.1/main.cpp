#include "systemc.h"
#include "Counter.h"

using namespace sc_core;

int sc_main(int argc, char* argv[]) {
    sc_set_time_resolution(1,SC_FS);

    Counter pippo("pippo");

    sc_start();

    return 0;
}