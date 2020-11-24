#ifndef TIMER2_H
#define	TIMER2_H

#include <inttypes.h>

extern void timer2_init();

extern uint16_t timer2_read();

extern uint16_t timer2_ms_elapsed(uint16_t t1, uint16_t t2);

extern uint8_t timer2_rand_bit();

#endif	/* TIMER2_H */