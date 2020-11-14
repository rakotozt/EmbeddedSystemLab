/* 
 * File:   adc_intf.h
 * Author: Matthew Watkins
 *
 * Created on September 2, 2015, 9:56 AM
 * Revised by John Nestor on September 3, 2020
 */

#ifndef ADC_INTF_H
#define	ADC_INTF_H

#include <plib.h>
#include <xc.h>

    
void configureADC();

int readADC(int an);

int analogRead(char analogPIN);

#endif	/* ADC_INTF_H */