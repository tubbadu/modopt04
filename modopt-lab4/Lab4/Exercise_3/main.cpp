#include <systemc.h>
#include "interfaces.h"
#include "tlm_tlc.h"
#include "os_drivers.h"

int sc_main (int argc, char * argv[])
{ 
	Abstract_TLC TLC("Controller") ;
	OS_DRIVERS os_drivers("OS drivers");
	
	TLC.car(os_drivers);
	TLC.light(os_drivers);
	TLC.timer(os_drivers);

	sc_start();
	return 0 ;
}
