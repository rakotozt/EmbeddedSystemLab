#include "port_in.h"
#include <xc.h>
#include <plib.h>
void port_in_init(){
  // TRISBbits.TRISB9 = 0; //RB9 is output
    TRISBbits.TRISB7 = 1; //RB7 is input
    //CNPUBbits.CNPUB7 = 1;
    CNPUB = 0b10000000;
    LATBbits.LATB9 = 0;
}


//uint8_t port_in_read(){
//    uint8_t input = PORTB;
//    return input;
//}
//
