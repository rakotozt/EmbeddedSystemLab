
#pragma config FNOSC = FRCPLL, POSCMOD = OFF
#pragma config FPLLIDIV = DIV_2, FPLLMUL = MUL_20
#pragma config FPBDIV = DIV_1, FPLLODIV = DIV_2
#pragma config FWDTEN = OFF, JTAGEN = OFF, FSOSCEN = OFF

#include <xc.h>
#include <inttypes.h>
#include "game_fsm.h"
#include "timer1.h"
#include "portb_out.h"
#include "porta_in.h"




uint8_t gameover = 0;
uint8_t dir = 0;

uint8_t startgame = 0;
uint16_t outval = 0x0000;
uint8_t btnR = 0;
uint8_t btnL = 0;
uint16_t delay = 300;
uint8_t start = 0;
uint8_t leftwin=0;
uint16_t rightwin=0;
	const uint16_t button_reaction = 50 ;

int main(int argc, char** argv) {
    
    
    portb_out_init() ;
    porta_in_init();
    
    
 
	uint16_t pong = delay;
	uint16_t t1_pong , t1_btnR, t1_btnL;
	uint16_t t2_pong  ,t2_btnR, t2_btnL;

	int po_state, btnR_state, btnL_state; 

	po_state = btnR_state = btnL_state= -1 ;

	timer1_init () ; 


	t1_pong =t1_btnR = t1_btnL = timer1_read();
	uint16_t refresh = 0;
	uint16_t refresh1 = 0;
    
	while(1){        
        //make sure that the speed is not to high
        if(delay>=100){pong=delay;}
        else{pong=100;}
		delay = pong;
		outval = outval & 0x00FF;
        start=rand() % 2;
		t2_pong  = t2_btnR = t2_btnL = timer1_read();

		if(timer1_ms_elapsed(t1_pong, t2_pong) >= pong){
			refresh = !refresh;
			t1_pong = t2_pong;
   			po_state = TickFct_PO(po_state);
   			
		}
		if(timer1_ms_elapsed(t1_btnR, t2_btnR) >= button_reaction){
			t1_btnR = timer1_read();
   			btnR_state = TickFct_btnR(btnR_state);
   			
		}

		if(timer1_ms_elapsed(t1_btnL, t2_btnL) >= button_reaction){
			t1_btnL = timer1_read();
   			btnL_state = TickFct_btnL(btnL_state);
   			

   			if(refresh1 == 0x0){refresh1 = 1;}
			else if(refresh1 == 1){refresh1 = 0x0;}
		}
       
        portb_out_write(outval);

        
    }

    return (EXIT_SUCCESS);
}

