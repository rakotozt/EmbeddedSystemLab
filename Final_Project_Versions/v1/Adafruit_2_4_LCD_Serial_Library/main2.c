/*
 * Learing 
 * Author: Tafita & Chiko 
 */
#pragma config FNOSC = FRCPLL, POSCMOD = OFF
#pragma config FPLLIDIV = DIV_2, FPLLMUL = MUL_20
#pragma config FPBDIV = DIV_1, FPLLODIV = DIV_2
#pragma config FWDTEN = OFF, JTAGEN = OFF, FSOSCEN = OFF

#include <xc.h>
#include <inttypes.h>
#include "game_fsm.h"
#include "timer2.h"
#include "port_in.h"
#include "types.h"
 #include "tft_gfx.h"
 #include "adc_intf.h"
 #include "tft_master.h"
//#include "config.h"
#include "dds.h"
#include <plib.h>
#include <stdio.h>
#include <stdlib.h>


#define XM AN0
#define YP AN1
#define DW 320
#define DH 240
#define TY_MAX 920 
#define TY_MIN 135 
#define TX_MAX 860
#define TX_MIN 180 

#define SYSCLK	40000000UL
//#define PBCLK	40000000UL


uint8_t gameover = 0;
uint8_t dir = 0;
uint8_t startgame = 0;
uint16_t outval = 0x0000;
uint8_t btnR = 0;
uint8_t btnL = 0;
uint16_t delay = 300;
uint8_t start = 0;
uint8_t leftWin;
uint16_t rightWin;
const uint16_t button_reaction = 50 ;
const uint16_t pdl_reaction = 50 ;

 uint8_t pdlL=0;
 uint8_t pdlR=0;
 uint8_t direction=0;
 uint8_t direction2=0;

 int speedY=30;
 int speedX=30;
 uint8_t speed=30;
 uint8_t sound=0;
 int yposB;
 int xposB;

uint8_t paddlewidth=20;
uint8_t pWidth=10;
uint8_t pLength=60;
uint8_t scoreL=0;
uint8_t scoreR=0;
uint8_t maxScore=3;
uint8_t state=0;
uint8_t up=0;

uint8_t initial=0;




//define timer scaling value for each note
#define C 255 
#define D 227
#define E 204
#define F 191
#define G 170
#define A 153
#define B 136
#define C2 127

#define notes 14 //total number of notes in song to be played - modify for specific song


int song[notes]={C, C, G, G, A, A, G, F, F, E, E, D, D, C}; //insert notes of song in array
int length[notes]={1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 2}; //relative length of each note
int i;



Paddle p1, p2;
Ball ball;

int main(int argc, char** argv) {

    configureADC();
  
    port_in_init();
    
    //display initialisation 
    tft_init_hw();
    tft_begin();
    tft_fillScreen(ILI9341_BLACK);
    
    
    
    //***
     SYSTEMConfigPerformance(SYSCLK);
     CM1CON = 0; CM2CON = 0; ANSELA = 0; ANSELB = 0; // why disable comparators? not sure
    mPORTASetPinsDigitalOut(BIT_0);  // this was in Tahmid's example; not sure why
    dds_init();
    INTEnableSystemMultiVectoredInt();
    
    
    
    //
	uint16_t pong = delay;
	uint16_t t1_pong , t1_btnR,t1_pdl,t1_btnL;
	uint16_t t2_pong  ,t2_btnR,t2_pdl,t2_btnL;

	int po_state, btnR_state,pdl_state,btnL_state; 

	po_state = btnR_state = -1 ;

	timer2_init () ; 

	t1_pong =t1_btnR=t1_pdl =t1_btnL=timer2_read();
    
	uint16_t refresh = 0;
	uint16_t refresh1 = 0;
    
    pdlL=(readADC(5)/5.7);
    pdlR=(readADC(11)/5.7);
    xposB=pWidth+(pWidth/2); 
    yposB=pdlL+(pLength/2);
    uint16_t k=0;
    
    int w=0;
    
	while(1){        
      

      //  dds_off();
      pong=100;  
      
       // start=rand() % 2;
      
      
      //state machines 
		t2_pong  = t2_btnR =t2_pdl = t2_btnL=timer2_read();

		if(timer2_ms_elapsed(t1_pong, t2_pong) >= pong){
			
   			po_state = TickFct_Pong_game();
                           
   			t1_pong = t2_pong;
		}
        if(timer2_ms_elapsed(t1_pdl, t2_pdl) >= pdl_reaction){
			t1_pdl = t2_pdl;
   			pdl_state = TickFct_pdl(pdl_state);
   			
		}
        
		if(timer2_ms_elapsed(t1_btnR, t2_btnR) >= button_reaction){
			t1_btnR = t2_btnR ;
   			btnR_state = TickFct_btnR(btnR_state); 			
		}
        
        if(timer2_ms_elapsed(t1_btnL, t2_btnL) >= button_reaction){
			t1_btnL = t2_btnL ;
   			btnL_state = TickFct_btnL(btnL_state); 			
		}
        
        if(initial==0){

            displayInitial();


 //twinkle();               
 jingleBell();
            
            
            clearInitial();
            dds_off();
        }
        else{        
          
    //position control    
    ball.y=xposB;     
    ball.x=yposB;  

    p1.y=0;      
    p1.x= pdlL;        
    
    p2.y=310;      
    p2.x= pdlR; 

  
    if(sound==1){
        dds_on(1000);
        delay_ms(100);
        dds_off();
    }
    
 
    displayScore(); 
    draw(p1,p2,ball,ILI9341_WHITE);
    displayGameOver();
    
    delay_ms(100);
    
    draw(p1,p2,ball,ILI9341_BLACK);

    clearScore();

    clearGameOver();
    
        }
		}

    return (EXIT_SUCCESS);
}

void  audio(){

    SYSTEMConfigPerformance(SYSCLK);
     CM1CON = 0; CM2CON = 0; ANSELA = 0; ANSELB = 0; // why disable comparators? not sure
    mPORTASetPinsDigitalOut(BIT_0);  // this was in Tahmid's example; not sure why
    dds_init();
    INTEnableSystemMultiVectoredInt();
    dds_on(440);
}


void displayInitial(){
    
    tft_setRotation(1);
    tft_setCursor((DH/3)-10,(DH/2));  // Upper Left Hand Corner
    tft_setTextColor(ILI9341_WHITE);  
    tft_setTextSize(3);
    tft_writeString("PONG GAME");
    tft_setCursor((DH/3)-10,(DH/4));
     tft_setTextSize(2);
   tft_writeString("Tafita & Chiko");
    tft_setRotation(0);

}

void clearInitial(){
    
    tft_setRotation(1);
    tft_setCursor((DH/3)-10,(DH/2));  // Upper Left Hand Corner
    tft_setTextColor(ILI9341_BLACK);  
    tft_setTextSize(3);
    tft_writeString("PONG GAME");
    tft_setCursor((DH/3)-10,(DH/4));
     tft_setTextSize(2);
   tft_writeString("Tafita & Chiko");
    tft_setRotation(0);
   
}





void displayGameOver(){
    if(gameover==1){
    tft_setRotation(1);
    tft_setCursor((DH/3)-10,(DH/2));  // Upper Left Hand Corner
    tft_setTextColor(ILI9341_WHITE);  
    tft_setTextSize(4);
    tft_writeString("Game Over"); 
    tft_setRotation(0);
    twinkle();
}


}

void clearGameOver(){
    if(gameover==1){

    tft_setRotation(1);
    tft_setCursor((DH/3)-10,(DH/2));  // Upper Left Hand Corner
    tft_setTextColor(ILI9341_BLACK);  
    tft_setTextSize(4);
    tft_writeString("Game Over"); 
    tft_setRotation(0);
    
    }
}


void printImportantPoints(){
    //coordinate 240,320
    tft_fillCircle( 240,320,10, ILI9341_RED);
    //coordinate 0,0
    tft_fillCircle( 0,0,10, ILI9341_GREEN);
}


void clearScore(){
    tft_setRotation(1);
    tft_setCursor((DH/2),20);  // Upper Left Hand Corner
    tft_setTextColor(ILI9341_BLACK);  
    tft_setTextSize(4);
    sprintf(out,"%d   %d",scoreL,scoreR );
    tft_writeString(out); 
    tft_setRotation(0);
}

void displayScore(){
    tft_setRotation(1);
    tft_setCursor(DH/2,20);  // Upper Left Hand Corner
    tft_setTextColor(ILI9341_WHITE);  
    tft_setTextSize(4);
    sprintf(out,"%d   %d",scoreL,scoreR );
    tft_writeString(out); 
    tft_setRotation(0);
}

void twinkle(){

      for (i=0; i<notes; i++) {     //play x notes inside song array
      
      dds_on(song[i]); 
                               //set PWM frequency according to entries in song array
      delay_ms(200*length[i]); //each note is played for 400ms*relative length
                                          //in order to create a short silence between notes
      delay_ms(50);   //the silence is played for 50 ms   
}
}


void jingleBell(){
#define size 25
int song[size] = {E, E, E, E, E, E, E, G, C, D, E, F, F, F, F, F, E, E, E, E, D, D, E, D, G};
int length[size] = {1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 4, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2};
int k;      
for (k=0; k<size; k++) {     //play x notes inside song array
      
      dds_on(song[k]); 
                               //set PWM frequency according to entries in song array
      delay_ms(200*length[k]); //each note is played for 400ms*relative length
                                          //in order to create a short silence between notes
      delay_ms(50);   //the silence is played for 50 ms   
}
}