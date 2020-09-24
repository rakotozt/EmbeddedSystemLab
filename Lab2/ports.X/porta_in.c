/* 
 * File:   portb_out.c
 * Author: rakotozt & dhire 
 *
 * Created on September 2, 2020
 */
#include <xc.h>
#include <inttypes.h>
#include "porta_in.h"
void porta_in_init() {
    //set a RA0: RA3 as input 
    ANSELA = 0; 
    TRISA = 0x1f; 
    CNPUA = 0x1f; 
    
}
uint8_t porta_in_read() {
    //return PORTA reading 
    return PORTA; 
    
}