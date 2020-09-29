 #pragma config FNOSC = FRCPLL, POSCMOD = OFF
 #pragma config FPLLIDIV = DIV_2, FPLLMUL = MUL_20 //40 MHz
 #pragma config FPBDIV = DIV_1, FPLLODIV = DIV_2 // PB 40 MHz
 #pragma config FWDTEN = OFF,  FSOSCEN = OFF, JTAGEN = OFF

#include "uart1.h" 
#include <stdio.h>
#include <stdlib.h>

// we changed the baudrate value to 1200, 4800, 124400 and 921600
int main() {

	uart1_init(9600) ;
 	uart1_txwrite_str("qwertyuiopasdfghjklzxcvbnm123456789!@#$%^&*()_+\n\r");
	
    return (EXIT_SUCCESS);
}


