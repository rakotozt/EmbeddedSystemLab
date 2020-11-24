#include "port_in.h"
#include <xc.h>
#include <plib.h>
void port_in_init(){
    TRISBbits.TRISB7 = 1; //RB7 is input
    CNPUB = 0b10000000;
     TRISBbits.TRISB9 = 1; //RB9 is input
}


uint8_t btnL_read(){
    return !PORTBbits.RB9;// return reading RB9
}

uint8_t btnR_read(){ 
    return !PORTBbits.RB7;// return reading RB7
}