/**
 * @Author: John Nestor <nestorj>
 * @Date:   2020-11-03T15:06:21-05:00
 * @Email:  nestorj@lafayette.edu
 * @Last modified by:   nestorj
 * @Last modified time: 2020-11-03T15:06:21-05:00
 */



/*
 * File:   ztimer.h
 * Author: nestorj
 *
 * Created on September 5, 2019, 2:06 PM
 * Updated October 3, 2019 to use vectored interrupt.
 * This module implements a timer matching the functionality of the interrupt-
 * driven timer described in Section 4.5 of the Zybook "Programming Embedded
 * Systems".  A key difference is that the timer flag is encapsulated in the
 * module calling ReadTimerFlag returns its value and clears the flag.  This
 * means that we don't have to use a global variable to pass the flag.
 *
 * In its current implementation this module can work with intervals
 * up to 858,993ms (858 seconds)
 */

#ifndef ZTIMER_H
#define	ZTIMER_H
#include <inttypes.h>

// initialize timer to set a flag every given period (in ms)
extern void zTimerSet(uint32_t period);

// enable the timer and turn on the interrupt
extern void zTimerOn();

// read and return the timer flag value
// SIDE EFFECT: clear the flag
extern uint8_t zTimerReadFlag();

// return elapsed time in milliseconds since last call to zTimerOn
extern uint32_t zTimerReadms();

#endif	/* ZTIMER_H */
