/* 
 * File:   oc1.c
 * Author: nestorj
 *
 * Module to configure & control OC1 using timer 3 - SFR Version
 * Created on September 26, 2019, 2:48 PM
 */

#include "output_compare.h"
#include <xc.h>
#include <plib.h>
    
void  oc1_init_plib (){

    //OC for Motor
    OpenOC2(OC_ON | OC_TIMER_MODE16| OC_TIMER3_SRC | OC_PWM_FAULT_PIN_DISABLE, 0xffff, 0xffff);  //set default duty to be 100%
    PPSOutput(2, RPB5, OC2);
}


void  oc1_setduty_plib (int dc){//set duty cycle
	SetDCOC2PWM(dc);
}
