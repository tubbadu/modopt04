/*
 * main.cpp
 *
 *  Created on: Aug 27, 2010
 *      Author: songzhenyu
 */

#include <iostream>
#include <stdlib.h>

#include <systemc.h>
#include "semafero.h"
#include "testbench.h"



int sc_main(int argc, char* argv[]) {
	semafero semmy("semmy");
	testbench timmy("timmy");

	sc_signal<bool> channel_car;
	sc_signal<semafero::color> channel_M, channel_S;

	semmy.car(channel_car);
	semmy.M(channel_M);
	semmy.S(channel_S);


	timmy.car(channel_car);
	timmy.M(channel_M);
	timmy.S(channel_S);



	sc_start();
	return 0;
}
