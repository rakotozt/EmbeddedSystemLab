/*
 * File: dac4822.c - driver for MCP4822 DAC over SPI from PIC32
 * Author: John Nestor (Derived from example code by Syed Tahmid Mahbub)
 * Reference: http://tahmidmc.blogspot.com/2014/10/pic32-spi-using-mcp4822-12-bit-serial.html
 */

#include <xc.h>
#include <plib.h>
#include <stdint.h>
#include "dac4822.h"



// Set up the SPI interface and initialize the DAC
void init_dac4822(void){
/* Steps:
 *	1. Setup SS as digital output.
 *	2. Map SDO to physical pin.
 *	3. Configure SPI control and clock with either of a or b:
 *		a. OpenSPIx(config1, config2) and SpiChnSetBrg(spi_channel, spi_brg)
 *		b. SpiChnOpen(spi_channel, config, spi_divider)
 */

	dirSS = 0;					// make SS an output
    SS = 1;						// set SS = 1 to deselect slave
	PPSOutput(2, RPB5, SDO2);	// map SDO2 to RB5

///////
#define config1 SPI_MODE16_ON | SPI_CKE_ON | MASTER_ENABLE_ON
	/*	FRAME_ENABLE_OFF
	 *	ENABLE_SDO_PIN		-> SPI Output pin enabled
	 *	SPI_MODE16_ON		-> 16-bit SPI mode
	 *	SPI_SMP_OFF			-> Sample at middle of data output time
	 *	SPI_CKE_ON			-> Output data changes on transition from active clock
	 *							to idle clock state
	 *	SLAVE_ENABLE_OFF	-> Manual SW control of SS
	 *	MASTER_ENABLE_ON	-> Master mode enable
	 */
#define config2 SPI_ENABLE
	/*	SPI_ENABLE	-> Enable SPI module
	 */
//	OpenSPI2(config1, config2);
	// see pg 193 in plib reference

#define spi_channel	2
	// Use channel 2 since channel 1 is used by TFT display

#define spi_brg	0
	// Divider = 2 * (spi_brg + 1)
	// Divide by 2 to get SPI clock of FPBDIV/2 -> max SPI clock

//	SpiChnSetBrg(spi_channel, spi_brg);
	// see pg 203 in plib reference

//////

//////
    

#define spi_divider 2
/* Unlike OpenSPIx(), config for SpiChnOpen describes the non-default
 * settings. eg for OpenSPI2(), use SPI_SMP_OFF (default) to sample
 * at the middle of the data output, use SPI_SMP_ON to sample at end. For
 * SpiChnOpen, using SPICON_SMP as a parameter will use the non-default
 * SPI_SMP_ON setting.
 */
#define config SPI_OPEN_MSTEN | SPI_OPEN_MODE16 | SPI_OPEN_DISSDI | SPI_OPEN_CKE_REV
	/*	SPI_OPEN_MSTEN		-> Master mode enable
	 *	SPI_OPEN_MODE16		-> 16-bit SPI mode
	 *	SPI_OPEN_DISSDI		-> Disable SDI pin since PIC32 to DAC is a
	 *							master-to-slave	only communication
	 *	SPI_OPEN_CKE_REV	-> Output data changes on transition from active
	 *							clock to idle clock state
	 */
    SpiChnOpen(spi_channel, config, spi_divider);
//////
}




