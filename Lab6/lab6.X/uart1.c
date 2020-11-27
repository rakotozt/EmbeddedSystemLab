

#include "uart1.h" 
//#include <plib.h>
//#include <inttypes.h>
//#include <xc.h>




void uart1_init( int32_t baudrate) {
    
	ANSELA = 0 ; // Analog Turned off 
	TRISA = 0xff ;  // Digital Turned On 

	//U1MODE = 0 ; // Disabling UART and other things 
	//U1STA = 0; // Transmitter 
	// U1RX Input Pin 


	// New Pin Values 
	U1RXR = 0X2 ; // U1RX connected to RPA4 (pin 12)
	RPB4R = 0X1 ; // U1TX connected to RPB4 (pin 11)

	// OpenUART1(UART_EN | UART_NO_PAR_8BIT, UART_RX_ENABLE | UART_TX_ENABLE, baudrate);
	U1MODEbits.ON = 1 ; 
	
	U1MODEbits.UEN = 0; 
	U1MODEbits.BRGH = 0 ; 
	U1MODEbits.PDSEL = 0 ; 

	U1STAbits.UTXEN = 1;
	U1STAbits.URXEN = 1 ;
	// Disabled Interupts so that it doesnt interfere with the timers interupt
    //U1STAbits.UTXISEL = 0;
    //U1STAbits.URXISEL = 0;
    
    U1BRG = (((40000000)/(16*baudrate))-1) ; 
    
	//ConfigIntUART1(UART_RX_INT_DIS | UART_TX_INT_DIS |UART_ERR_INT_DIS| UART_INT_PR0 | UART_INT_SUB_PR0 );


}

// If 0 is returned it is not ready, vice versa for 1 
uint8_t uart1_txrdy(){ 
  	//if ((uint8_t)BusyUART1()){ 
	if (U1STAbits.UTXBF) {
 		return 0 ; 
 	} 
 	else {
 		return 1 ;
 	} 		
  }

void uart1_txwrite(uint8_t c ) { 
	// Wait for transmit signal to write to buffer
	while(!uart1_txrdy());
	WriteUART1((char)c);
} 

void uart1_txwrite_str(char *c) {
	for(;*c != '\0'; c++){
		uart1_txwrite(*c);
	}
} 

// void uart1_txwrite_str(char *c) {
// 	putsUART1(c);
// } 

// If 1 is returned reciever has data to be read
uint8_t uart1_rxrdy() {
	//return !DataRdyUART1();
	if (U1STAbits.URXDA){ 
 		return 1 ; 
 	} 
 	else {
 		return 0 ;
 	} 		

}

uint8_t uart1_rxread() {
	//return (uint8_t)ReadUART1();
	return (U1RXREG);
 }  