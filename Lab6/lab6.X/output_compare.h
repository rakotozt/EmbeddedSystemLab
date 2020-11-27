/* 
 * File:   oc1_plib.h
 * Author: nestorj
 * Functions are identical to the SFR version except for the "_plib" suffix
 * Module to configure & control OC1 using timer 3 with PLIB
 * 
 * Created on September 26, 2019, 2:48 PM
 */

#ifndef OUTPUT_COMPAREH
#define	OUTPUT_COMPAREH
// Configure clocks
#include <stdio.h>
#include <plib.h>
#include <inttypes.h>
#include <xc.h>

void oc1_init_plib ();

void oc_scope_set (int dc);

void oc1_setduty_plib (int dc);

#endif	/* UART1_H */
