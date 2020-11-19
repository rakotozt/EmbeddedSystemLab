
#pragma config FNOSC = FRCPLL, POSCMOD = OFF
#pragma config FPLLIDIV = DIV_2, FPLLMUL = MUL_20
#pragma config FPBDIV = DIV_1, FPLLODIV = DIV_2
#pragma config FWDTEN = OFF, JTAGEN = OFF, FSOSCEN = OFF

#include <xc.h>
#include <inttypes.h>
#include "game_fsm.h"
#include "timer1.h"
#include "port_in.h"
#include "types.h"
 #include "tft_gfx.h"
 #include "adc_intf.h"
 #include "tft_master.h"

 #define XM AN0
 #define YP AN1
#define DW 320
#define DH 240
#define TY_MAX 920 
#define TY_MIN 135 
#define TX_MAX 860
#define TX_MIN 180 


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
const uint16_t pdl_reaction = 50 ;



 uint8_t pdlL=0;
 uint8_t pdlR=0;
 uint8_t direction=0;

 uint8_t speed=20;
 uint8_t sound=0;
 uint8_t yposB=50;
 uint8_t xposB=50;

uint8_t paddlewidth=20;
 uint8_t scoreL=0;
 uint8_t scoreR=0;
 uint8_t maxScore=7;
 uint8_t width=30;

Paddle p1, p2;
Ball ball;

int main(int argc, char** argv) {
    
    configureADC();
  
    port_in_init();
    
     // Initialize TFT
    tft_init_hw();
    tft_begin();
    tft_fillScreen(ILI9341_BLACK);
    
	uint16_t pong = delay;
	uint16_t t1_pong , t1_btnR,t1_pdl;
	uint16_t t2_pong  ,t2_btnR,t2_pdl;

	int po_state, btnR_state,pdl_state; 

	po_state = btnR_state = -1 ;

	timer1_init () ; 


	t1_pong =t1_btnR=t1_pdl  = timer1_read();
	uint16_t refresh = 0;
	uint16_t refresh1 = 0;
    
	while(1){        
        //make sure that the speed is not to high
     //   pdlL=(readADC(11)/5.7);
     //   pdlR=(readADC(5)/5.7);
         
        
        if(delay>=100){pong=delay;}
        else{pong=100;}
		delay = pong;
		outval = outval & 0x00FF;
        start=rand() % 2;
		t2_pong  = t2_btnR =t2_pdl = timer1_read();

		if(timer1_ms_elapsed(t1_pong, t2_pong) >= pong){
			refresh = !refresh;
			t1_pong = t2_pong;
   			po_state = TickFct_Pong_game();
   			
		}
        if(timer1_ms_elapsed(t1_pdl, t2_pdl) >= pdl_reaction){
			//refresh = !refresh;
			t1_pdl = t2_pdl;
   			pdl_state = TickFct_pdl(pdl_state);
   			
		}
        
		if(timer1_ms_elapsed(t1_btnR, t2_btnR) >= button_reaction){
			t1_btnR = timer1_read();
   			btnR_state = TickFct_btnR(btnR_state);
   			
		}
   			if(refresh1 == 0x0){refresh1 = 1;}
			else if(refresh1 == 1){refresh1 = 0x0;}
        
           ball.y=xposB;      
  ball.x=yposB;  

p1.y=0;      
p1.x= pdlL;        
    
p2.y=300;      
p2.x= pdlR; 

draw(p1,p2,ball,ILI9341_WHITE);
delay_ms(500);
draw(p1,p2,ball,ILI9341_BLACK);
//clearDisplay();
//delay_ms(10);
  

		}
       


    return (EXIT_SUCCESS);
}



