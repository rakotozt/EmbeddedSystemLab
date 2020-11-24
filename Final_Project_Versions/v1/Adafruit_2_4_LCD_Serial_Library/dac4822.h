/* 
 * File:   dac4822.h
 * Author: nestorj ((Derived from example code by Syed Tahmid Mahbub)
 * See: http://tahmidmc.blogspot.com/2014/10/pic32-spi-using-mcp4822-12-bit-serial.html
 * Created on October 27, 2020, 2:31 PM
 */

#ifndef DAC4822_H
#define	DAC4822_H

#include <xc.h>
#include <plib.h>
#include <stdint.h>

// SS = PORTA4 - slave select using pin A4
#define SS      LATBbits.LATB10   // changed to LATB10
#define dirSS   TRISBbits.TRISB10

// Set up the SPI interface and initialize the DAC
void init_dac4822(void);

// Write a data value to specified channel (0=A, 1=B))
//void write_dac4822(uint16_t channel, uint16_t data);

// write data to dac channel (0=A, 1=B) with gain=1
static inline void write_dac4822(uint16_t channel, uint16_t data){
    data = data | ((channel & 0x1) << 15) | 0x3000 | data;
    SS = 0;	// select slave device: MCP4822 DAC
    while (TxBufFullSPI1());	// ensure buffer is free before writing
    WriteSPI2(data);			// send the data through SPI
    while (SPI2STATbits.SPIBUSY); // blocking wait for end of transaction
    SS = 1;	// deselect slave device, transmission complete
}

#endif	/* DAC4822_H */

