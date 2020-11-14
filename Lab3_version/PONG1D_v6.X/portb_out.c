#include "portb_out.h"
void portb_out_init(){
    ANSELB = 0;
    TRISB = 0;
    
}
void portb_out_write(uint16_t val){

	uint16_t out = 0 ;  
 	uint16_t part0_5 = val & 0x003F ;
    
    uint16_t part7_11 = (val<<1) & 0x0F80 ;
    
    uint16_t part13_15 = (val << 2) & 0xE000;

    out = part0_5|part7_11|part13_15;
    
    LATB = out ;
}
