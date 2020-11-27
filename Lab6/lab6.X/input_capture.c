/* 
 * File:   ic1.c
 * Author: nestorj
 *
 * Created on October 3, 2019, 5:34 PM
 * Simple demonstration of Input Capture using IC1 and a vectored interrupt.
 * Note: the user of this module must call INTEnableSystemMultiVectoredInt();
 * after the module (and any other modules using interrupts) are initialized
 */
#include <xc.h>
#include <plib.h>
#include "input_capture.h"
#include "tft_master.h"  // for PBCLK declaration



 static uint16_t capture1, last_capture1, capture_period, max_period, min_period;

    void ic1_init() {
        OpenTimer2(T2_ON | T2_SOURCE_INT | T2_PS_1_256, 0xffff);
        OpenCapture1( IC_EVERY_RISE_EDGE | IC_INT_1CAPTURE | IC_TIMER2_SRC | IC_ON );
        ConfigIntCapture1(IC_INT_ON | IC_INT_PRIOR_3 | IC_INT_SUB_PRIOR_3 );
        INTClearFlag(INT_IC1);
        PPSInput(3, IC1, RPA2);          // connect PIN 9 to IC1 capture unit
        mPORTBSetPinsDigitalIn(BIT_2 );  // Set port as input (important!)
        capture1 = 2;
        last_capture1 = 1;
        capture_period = 1;
    }
    

    // IC1 Interrupt service routine
    void __ISR(_INPUT_CAPTURE_1_VECTOR, ipl3) C1Handler(void) {
        extern uint16_t interp;
        capture1 = mIC1ReadCapture();
        capture_period = capture1 - last_capture1;
        last_capture1 = capture1;
        interp = 0;
        mIC1ClearIntFlag();    
    }
    
    uint16_t ic1_getperiod() {
        return capture_period;
 
    }
