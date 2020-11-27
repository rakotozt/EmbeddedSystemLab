/* 
 * File:   ic1.h
 * Author: nestorj
 *
 * Created on October 3, 2019, 5:34 PM
 * Simple demonstration of Input Capture using IC1 and a vectored interrupt.
 * Note: the user of this module must call INTEnableSystemMultiVectoredInt();
 * after the module (and any other modules doing interrutps) are initialized
 */

#ifndef INPUT_CAPTURE_H
#define	INPUT_CAPTURE_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <inttypes.h>

    
    // Configure IC1 using Timer3
    // (user must still call INTEnableSystemMultiVectoredInt afterward)
    extern void ic1_init();


    // return the period measured by IC1
    extern uint16_t ic1_getperiod();
    
    // return the estimated RPM of the input capture
    uint16_t ic1_getrpm();

#ifdef	__cplusplus
}
#endif

#endif	/* IC1_H */

