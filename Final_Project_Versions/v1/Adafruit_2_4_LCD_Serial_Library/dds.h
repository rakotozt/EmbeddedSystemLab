/* 
 * File:   dds.h
 * Author: nestorj
 * See: http://tahmidmc.blogspot.com/2014/10/pic32-spi-using-mcp4822-12-bit-serial.html
 * 
 * Direct Digital Synthesis to produce a sine and triangle wave via the DAC4822
 * Note: this module uses Timer1 with 1_1 prescale and multivectored
 * interrupts.  During initialization the main function must call
 * INTEnableSystemMultiVectoredInt(); 
 * 
 */

#ifndef DDS_H
#define	DDS_H

#include <stdint.h>

void dds_init();

void dds_on(uint32_t freq_hz);

void dds_off();



#endif	/* DDS_H */

