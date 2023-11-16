#include <systemc.h>
#include <string.h>
#include <stdio.h>
#include "interfaces.h"
#include "tlm_tlc.h"
#include "os_drivers.h"

int sc_main (int argc, char * argv[])
{ 
	Abstract_TLC TLC("Controller") ;
	OS_drivers os_drivers("OS_drivers");
	
	TLC.car(os_drivers);
	TLC.light(os_drivers);
	TLC.timer(os_drivers);

	sc_start();
	return 0 ;
}
