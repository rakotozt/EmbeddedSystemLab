#ifndef PORTA_IN_H
#define	PORTA_IN_H


#include<xc.h>
#include <inttypes.h>
 #include <plib.h>
extern void  port_in_init();
extern uint8_t btnL_read();
extern uint8_t btnR_read();

#endif