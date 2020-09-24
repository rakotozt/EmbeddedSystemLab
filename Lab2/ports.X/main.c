/* 
 * File:   main.c
 * Author: rakotozt & dhire 
 *
 * Created on September 2, 2020
 */

//clock config 
#pragma config FNOSC = FRCPLL, POSCMOD = OFF
#pragma config FPLLIDIV = DIV_2, FPLLMUL = MUL_20
#pragma config FPBDIV = DIV_1, FPLLODIV = DIV_2
#pragma config FWDTEN = OFF, JTAGEN = OFF, FSOSCEN = OFF

#include <xc.h>
#include <inttypes.h>
#include "porta_in.h"
#include "portb_out.h"


main() {
 uint8_t in;
 uint16_t out;
 porta_in_init();
 portb_out_init();
 uint8_t RA4;

 while (1) {
//assing portA reading to the variable in 
     in = porta_in_read();
 
 //set the variable input RA4 
 RA4 = in & 0x10;
 //if RA4 is low
 //assign the binary number encoded on switches RA3:RA0
 if(RA4==0x00){
     out = 0x1 << (in & 0x0f);     
 //if RA4 is high
 //assing the inverse of the  binary number encoded on switches RA3:RA0
 }else if(RA4 ==0x10) {   
    out = ~(0x1 << (in &0x0f));
 }
 //else put all LED to off 
 else{out = 0x0000;}
 //write the condition statements 
 
 //write the variable out 
 portb_out_write(out);
 }
}