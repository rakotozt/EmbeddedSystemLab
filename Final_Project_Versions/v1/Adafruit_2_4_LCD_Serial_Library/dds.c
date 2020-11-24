/*
 * File: dds.c
 * Author: John Nestor (Derived from example code by Syed Tahmid Mahbub)
 * See: http://tahmidmc.blogspot.com/2014/10/pic32-spi-using-mcp4822-12-bit-serial.html
 * 
 * Direct Digital Synthesis to produce a sine and triangle wave via the DAC4822
 * Note: this module uses Timer1 with 1_1 prescale and multivectored
 * interrupts.  During initialization the main function must call
 * INTEnableSystemMultiVectoredInt();
 *  
 */

#include <math.h>
#include <stdint.h>
#include "dds.h"
#include "dac4822.h"

#define TABLE_SIZE 64
int16_t sineTable[TABLE_SIZE];
int16_t triangleTable[TABLE_SIZE];

#define SYSCLK	40000000UL
#define PBCLK	40000000UL


static uint32_t dac_freq;  // frequency at which DAC outputs from table
static uint32_t timer_reset;
volatile uint8_t counter = 0;

void initTimer1(uint32_t timer_reset){
    OpenTimer1(T1_ON | T1_PS_1_1, timer_reset);
    // Configure T1 for DAC update frequency
    ConfigIntTimer1(T1_INT_ON | T1_INT_PRIOR_2);
    
}

void __ISR(_TIMER_1_VECTOR, ipl2) T1Int(void){
    write_dac4822(0, sineTable[counter]); // write to channel A, gain = 1
    write_dac4822(1, triangleTable[counter]); // write to channel B, gain = 1
    counter++;
    if (counter == TABLE_SIZE) counter = 0;
	mPORTAToggleBits(BIT_0);
    mT1ClearIntFlag();
}

// turn on DDS at the specified frequency using timer1 to interrupt
// each time a new output is needed
void dds_on(uint32_t freq_hz) {
    dac_freq = freq_hz * TABLE_SIZE;
    timer_reset = PBCLK/dac_freq - 1;
    initTimer1(timer_reset);
    // maybe do some checking here?
    // turn on the interrupt!
    
}

// turn off DDS by disabling timer interrupt
void dds_off() {
    CloseTimer1();
}

void generateTables(void){
    uint8_t i;
    for (i = 0; i<TABLE_SIZE; i++){
        sineTable[i] = (short) (2047.0 * sin(6.2832*((float)i)/(float)TABLE_SIZE));
        sineTable[i] = sineTable[i] + 2047;

        if (i < TABLE_SIZE/2){
            triangleTable[i] = (i * (4096/(TABLE_SIZE/2))); // increasing part
        }
        else{
            triangleTable[i] = triangleTable[(TABLE_SIZE/2 - 1)-(i-TABLE_SIZE/2)]; // mirror to get decreasing part
        }
    }
}

void dds_init()
{
    generateTables();
    init_dac4822();
    // don't forget: main() must call INTEnableSystemMultiVectoredInt(); )
}
