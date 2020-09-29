 #pragma config FNOSC = FRCPLL, POSCMOD = OFF
 #pragma config FPLLIDIV = DIV_2, FPLLMUL = MUL_20 //40 MHz
 #pragma config FPBDIV = DIV_1, FPLLODIV = DIV_2 // PB 40 MHz
 #pragma config FWDTEN = OFF,  FSOSCEN = OFF, JTAGEN = OFF

#include "uart1.h" 
#include <stdio.h>
#include <stdlib.h>


int main() {
	uint8_t character;
	uart1_init(9600) ;
 	uart1_txwrite_str("Hello World! This is Tafita and Chiko.\n\r");
	
	while(1){ 
		if (U1STAbits.URXDA) {
		  character = uart1_rxread();
          if( character>='a' && character<='z'){
            uart1_txwrite(character-32); //refering to ASCII table  ( changes to MAJ)
          }
            else if (character<='Z' && character>='A')
                uart1_txwrite(character+32); //based on ASCII table (changes min to MAJ)
		}

	}
    return (EXIT_SUCCESS);
}


