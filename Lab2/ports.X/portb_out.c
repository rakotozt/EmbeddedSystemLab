/* 
 * File:   main.c
 * Author: rakotozt & dhire 
 *
 * Created on September 2, 2020
 */
#include <xc.h>
#include <inttypes.h>
#include "portb_out.h"

void portb_out_init() {
    //set B ports as outputs 
    ANSELB = 0; 
    TRISB = 0; 
}
void portb_out_write(uint16_t val)
{
    //masking technique 
    //the RB6 and RB7 is not available 
    //temp variable creation  
    uint16_t temp1; 
     uint16_t temp2;
     uint16_t temp3;
     
     
     temp1 = (val & 0x001f); //R0:R5
     temp2 = (val<<1)& 0x0f80; //R7:R11
     temp3 = (val<<2)& 0xE000; //R13:R14
     LATB = temp1|temp2|temp3; //superpose them using or 

}