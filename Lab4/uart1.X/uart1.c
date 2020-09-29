/* 
 * File:  uart1.c
 * Author: Tafita Rakoto & Chiko Dhire 
 *
 * Created on September 28, 2020
 * This module implements uart functions
 * 
 */
#include "uart1.h"
#include <plib.h>

void uart1_init( int32_t baudrate) {

    ANSELA=0; //analog off 
    TRISA=0xff; //digital inputs off
  
    RPA0Rbits.RPA0R=0001; //assign the U1TX to RPA0 Pin2 ==>attached to the white wire
    U1RXRbits.U1RXR=0;//set U1RX to RPA2 Pin 9==>attached to the green wire 

    
    U1MODEbits.ON = 1 ; //enables UART 
    U1MODEbits.BRGH=0; //Standard Speed mode ? 16x baud clock enabled
    U1MODEbits.PDSEL=0; //8-bit data, no parity
    
    U1STAbits.UTXEN = 1;//enables Tx Pin 
	U1STAbits.URXEN = 1 ;//enables Rx pin 
    
    U1MODEbits.UEN = 0; 
    
    U1BRG = (((40000000)/(16*baudrate))-1) ; //set the baud rqte
}
// returns a true value when the UART transmitter is ready to accept a character for transmission
uint8_t uart1_txrdy(){
    //UTXBF: Transmit Buffer Full Status bit (read-only)
//1 = Transmit buffer is full
//0 = Transmit buffer is not full, at least one more character can be written
    	return !U1STAbits.UTXBF; 

 	} 	


void uart1_txwrite(uint8_t c ) { 
	while(!uart1_txrdy()); //stay in infinite loop if there is no transmission 
	WriteUART1((char) c);//write the UART1 
    
} 

void uart1_txwrite_str(char *c) {
//U1STA is  the USB control register 
	for(;*c != '\0'; c++){
		uart1_txwrite(*c);
	}
   }

/*
 
*/
uint8_t uart1_rxrdy() {   /* returns true when the UART receiver has
                             a character ready for reading*/
return 	U1STAbits.URXDA ;

}

uint8_t uart1_rxread() {  //reads a received character from the UART
   return (U1RXREG);
    }
     
