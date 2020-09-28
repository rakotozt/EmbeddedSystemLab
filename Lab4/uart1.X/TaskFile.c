 #pragma config FNOSC = FRCPLL, POSCMOD = OFF
 #pragma config FPLLIDIV = DIV_2, FPLLMUL = MUL_20 //40 MHz
 #pragma config FPBDIV = DIV_1, FPLLODIV = DIV_2 // PB 40 MHz
 #pragma config FWDTEN = OFF,  FSOSCEN = OFF, JTAGEN = OFF

#include <stdlib.h>
#include "uart1.h" 
#include <string.h>
#include "ztimer.h"

#include <xc.h>
#include <inttypes.h>
#include <stdio.h> // for sprintf


// Module includes here
// Number of iterations for testing. You may need to play with this
// number. If it is too short, you may not get a very accurate measure
// of performance. Too long and you will have to wait forever.
#define NUM_ITERATIONS 1000000
// This is the number of times you repeat the operation within the
// loop. You want to repeat enough times that the loop overhead is
// small for the simplest operations.
#define NUM_REPS 10
uint8_t buffer[64];

void test_uint8_mult()
{
	uint32_t i;
	double i1 , i2, i3;
	i1 = 15;
	i2 = 26;
	for (i=0; i<NUM_ITERATIONS; i++)
	{
		// Make sure NUM_REPS is the same as the number
		// of repeated lines here.
		i3 = i1*i2;
		i3 = i1*i2;
		i3 = i1*i2;
		i3 = i1*i2;
		i3 = i1*i2;
		i3 = i1*i2;
		i3 = i1*i2;
		i3 = i1*i2;
		i3 = i1*i2;
		i3 = i1*i2;
	}
}


void main()
{
	uint32_t t1, t2;
	// !!! Add code: Initialize modules and turn on interrupts
	uart1_init(9600) ;
	zTimerOn(); 
	zTimerSet(200);
	uart1_txwrite_str("Performance Summary: Time per operation statistics\r\n");

	// Test multiplying bytes
	t1 = zTimerReadms();
	test_uint8_mult();
	t2 = zTimerReadms();

	// Print timing result. Doubles OK here. Not time critical code.
	sprintf(buffer, "UINT8 MINUS: %.06f us per operation\r\n",(double)(t2-t1)/(double)NUM_ITERATIONS /(double)NUM_REPS*1000.0);
	uart1_txwrite_str(buffer);
uart1_txwrite_str("Hello World\r\n");
uart1_txwrite_str("Cool\r\n");
	// Add code to test other sizes and operators
	// ...
	while (1); // When done, wait forever.
}