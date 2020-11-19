#include "game_fsm.h"

extern uint8_t btnR;
extern uint8_t btnL;


extern uint8_t pdlL;
extern uint8_t pdlR;
extern uint8_t direction;
extern uint8_t gameover;
extern uint8_t speed;
extern uint8_t sound;
extern uint8_t yposB;
extern uint8_t xposB;
extern uint8_t leftwin;
extern uint8_t rightwin;
extern uint8_t paddlewidth;
extern uint8_t scoreL;
extern uint8_t scoreR;
extern uint8_t maxScore;
extern uint8_t width;


enum PNG_States { PNG_Start_L, PNG_Move, PNG_StartR, PNG_Left, PNG_Right, PNG_Restart, PNG_Gameover } PNG_State;
int TickFct_Pong_game() {
   switch(PNG_State) { // Transitions
      case -1:
         PNG_State = PNG_Start_L;
         break;
         case PNG_Start_L: 
         if (btnR==1) {
            PNG_State = PNG_Move;
           LATBbits.LATB9 = 1;
         }
         else if (btnR==0) {
            PNG_State = PNG_Start_L;
         }
         break;
      case PNG_Move: 
         if (xposB==width) {
            PNG_State = PNG_Right;
         }
         else if (xposB>=paddlewidth && xposB<=320-paddlewidth) {
            PNG_State = PNG_Move;
         }
         else if (xposB==0) {
            PNG_State = PNG_Left;
         }
		 
         break;
      case PNG_StartR: 
         if (pdlR == 1) {
            PNG_State = PNG_Move;
         }
         break;
      case PNG_Left: 
         if (pdlL==xposB) {
            PNG_State = PNG_Move;
         }
         else if (pdlL!=xposB) {
            PNG_State = PNG_Restart;
            rightwin=0;
            leftwin=1;   
         }
         break;
      case PNG_Right: 
         if (pdlR == xposB) {
            PNG_State = PNG_Move;
         }
         else if (pdlR!=xposB) {
            PNG_State = PNG_Restart;
            rightwin=0;
            leftwin=1;
         }
         break;
      case PNG_Restart: 
         if ((scoreL == maxScore)||(scoreR == maxScore)) {
            PNG_State = PNG_Gameover;
         }
         else if ((scoreR<maxScore) && leftwin) {
            PNG_State = PNG_StartR;
            leftwin=0;
         }
         else if ((scoreL<maxScore) && rightwin) {
            PNG_State = PNG_Start_L;
            rightwin = 0;
         }
         break;
      case PNG_Gameover: 
         break;
      default:
         PNG_State = PNG_Start_L;
   } // Transitions

   switch(PNG_State) { // State actions
      case PNG_Start_L:
         xposB = paddlewidth;
         yposB = 120;
         sound = 0;
         direction = 1;
         break;
      case PNG_Move:
         if(direction==0){
         xposB = xposB - speed;
         yposB = yposB;
         }
         else{
         xposB = xposB + speed;
         yposB = yposB;
         }
         break;
      case PNG_StartR:
         xposB = 320-paddlewidth;
         yposB = 120;
         direction = 0;
         break;
      case PNG_Left:
         direction = 0;
         sound = 1;
         break;
      case PNG_Right:
         direction = 1;
         sound = 1;
         break;
      case PNG_Restart:
         if (leftwin){
         scoreL ++;}
         else if(rightwin){
         scoreR++;
         }  
         break;
      case PNG_Gameover:
         gameover =1;
         break;
      default: // ADD default behaviour below
      break;
   } // State actions

}



//enum btnR_States { btnR_NO_PUSH, btnR_MAYBE_PUSH, btnR_PUSHED, btnR_MAYBE_NOPUSH } btnR_State;
//
//int TickFct_btnR(int state) {
//
//
//   switch(state) { // Transitions
//      case -1:
//         state = btnR_NO_PUSH;
//         break;
//      case btnR_NO_PUSH:
//         if ((~port_in_read() & 0x01 ) != 0) {
//            state = btnR_MAYBE_PUSH;
//            //btnR = 1 ;
//         }
//         break;
//      case btnR_MAYBE_PUSH:
//         if ((~port_in_read() & 0x01 ) == 0) {
//            state = btnR_NO_PUSH;
//         }
//         else if ((~port_in_read() & 0x01 ) != 0) {
//            state = btnR_PUSHED;
//            btnR = 1 ;
//         }
//         break;
//      case btnR_PUSHED:
//         if ((~port_in_read() & 0x01 ) == 0) {
//            state = btnR_MAYBE_NOPUSH;
//         }
//         break;
//      case btnR_MAYBE_NOPUSH:
//         if ((~port_in_read() & 0x01 ) == 0) {
//            state = btnR_NO_PUSH;
//         }
//         else if ((~port_in_read() & 0x01 ) != 0) {
//            state = btnR_PUSHED;
//         }
//         break;
//      default:
//         state = -1;
//      } // Transitions
//
//   switch(state) { // State actions
//      case btnR_NO_PUSH:
//         break;
//      case btnR_MAYBE_PUSH:
//         break;
//      case btnR_PUSHED:
//         break;
//      case btnR_MAYBE_NOPUSH:
//         break;
//      default: // ADD default behaviour below
//         break;
//   } // State actions
//   btnR_State = state;
//   return state;
//}


enum btnR_States { btnR_NO_PUSH, btnR_MAYBE_PUSH, btnR_PUSHED, btnR_MAYBE_NOPUSH } btnR_State;

int TickFct_btnR(int state) {


   switch(state) { // Transitions
      case -1:
         state = btnR_NO_PUSH;
         break;
      case btnR_NO_PUSH:
         if (PORTBbits.RB7==1) {
            state = btnR_MAYBE_PUSH;
            //btnR = 1 ;
         }
         break;
      case btnR_MAYBE_PUSH:
         if (PORTBbits.RB7==0) {
            state = btnR_NO_PUSH;
         }
         else if (PORTBbits.RB7==1) {
            state = btnR_PUSHED;
            btnR = 1 ;
         }
         break;
      case btnR_PUSHED:
         if (PORTBbits.RB7== 0) {
            state = btnR_MAYBE_NOPUSH;
         }
         break;
      case btnR_MAYBE_NOPUSH:
         if (PORTBbits.RB7== 0) {
            state = btnR_NO_PUSH;
         }
         else if (PORTBbits.RB7!= 0) {
            state = btnR_PUSHED;
         }
         break;
      default:
         state = -1;
      } // Transitions

   switch(state) { // State actions
      case btnR_NO_PUSH:
         break;
      case btnR_MAYBE_PUSH:
         break;
      case btnR_PUSHED:
         break;
      case btnR_MAYBE_NOPUSH:
         break;
      default: // ADD default behaviour below
         break;
   } // State actions
   btnR_State = state;
   return state;
}

uint8_t r, l;

enum pdl_States { pdl_Read} pdl_State;

int TickFct_pdl(int state) {
switch(state) { // Transitions
      case -1:
         state =pdl_Read;
         break;
      case pdl_Read:
         l=(readADC(5)/5.7);
         r=(readADC(11)/5.7);
         state =pdl_Read;
         break;
      default: // ADD default behaviour below
           state =pdl_Read;
         break;}
         
switch(state) { // State actions
      case pdl_Read:
          pdlR=r; 
          pdlL=l;
         break;
        default:
         break;

}
   pdl_State = state;
   return state;
}
