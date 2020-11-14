#include "game_fsm.h"
#include "porta_in.h"



extern uint8_t dir;
extern uint16_t outval;
extern uint8_t startgame;
extern uint8_t gameover;
extern uint8_t btnR;
extern uint8_t btnL;
extern uint8_t start;
extern uint16_t delay;
extern uint8_t leftwin;
extern uint16_t rightwin;


enum btnR_States { btnR_NO_PUSH, btnR_MAYBE_PUSH, btnR_PUSHED, btnR_MAYBE_NOPUSH } btnR_State;

int TickFct_btnR(int state) {


   switch(state) { // Transitions
      case -1:
         state = btnR_NO_PUSH;
         break;
      case btnR_NO_PUSH:
         if ((~porta_in_read() & 0x01 ) != 0) {
            state = btnR_MAYBE_PUSH;
            //btnR = 1 ;
         }
         break;
      case btnR_MAYBE_PUSH:
         if ((~porta_in_read() & 0x01 ) == 0) {
            state = btnR_NO_PUSH;
         }
         else if ((~porta_in_read() & 0x01 ) != 0) {
            state = btnR_PUSHED;
            btnR = 1 ;
         }
         break;
      case btnR_PUSHED:
         if ((~porta_in_read() & 0x01 ) == 0) {
            state = btnR_MAYBE_NOPUSH;
         }
         break;
      case btnR_MAYBE_NOPUSH:
         if ((~porta_in_read() & 0x01 ) == 0) {
            state = btnR_NO_PUSH;
         }
         else if ((~porta_in_read() & 0x01 ) != 0) {
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



enum btnL_States { btnL_NO_PUSH, btnL_MAYBE_PUSH, btnL_PUSHED, btnL_MAYBE_NOPUSH } btnL_State;
 int TickFct_btnL(int state) {

   switch(state) { // Transitions
      case -1:
         state = btnL_NO_PUSH;
         break;
      case btnL_NO_PUSH:
         if ((~porta_in_read() & 0x02 ) != 0) {
            state = btnL_MAYBE_PUSH;
            //btnL = 1 ;
         }
         break;
      case btnL_MAYBE_PUSH:
         if ((~porta_in_read() & 0x02) == 0) {
            state = btnL_NO_PUSH;
         }
         else if ((~porta_in_read() & 0x02 ) != 0) {
            state = btnL_PUSHED;
            btnL = 1 ;
         }
         break;
      case btnL_PUSHED:
         if ((~porta_in_read() & 0x02 ) == 0) {
            state = btnL_MAYBE_NOPUSH;
         }
         break;
      case btnL_MAYBE_NOPUSH:
         if ((~porta_in_read() & 0x02 ) == 0) {
            state = btnL_NO_PUSH;
         }
         else if ((~porta_in_read() & 0x02 ) != 0) {
            state = btnL_PUSHED;
         }
         break;
      default:
         state = -1;
      } // Transitions

   switch(state) { // State actions
      case btnL_NO_PUSH:
         break;
      case btnL_MAYBE_PUSH:
         break;
      case btnL_PUSHED:
         break;
      case btnL_MAYBE_NOPUSH:
         break;
      default: // ADD default behaviour below
         break;
   } // State actions
   btnL_State = state;
   return state;
}

enum PO_States { PO_Shift, PO_Start_R, PO_Start_L, PO_LEFT_POS, PO_RIGHT_POS, PO_Over,PO_Flash_ON, PO_Flash_OFF, PO_Speed_UP } PO_State;
int TickFct_PO(int state) {

static uint8_t count = 0;
   switch(state) { // Transitions
      case -1:
         state = PO_Start_R;
         break;
      case PO_Shift:
         if (outval == 0x0040 && !dir) {
            outval = outval<<1;
            state = PO_LEFT_POS;
         }
         else if (outval == 0x0002 && dir) {
            outval = outval>>1;
            state = PO_RIGHT_POS;
         }else{
            state = PO_Shift;
         }
         if (btnR || btnL) {
             
             if(btnR){leftwin=1;
             rightwin=0;
             btnR = btnL = 0;
              gameover =1;
            state = PO_Over;
             }
             else{  
                 leftwin=0;
                 rightwin=1;
             btnR = btnL = 0;
              gameover =1;
            state = PO_Over;}
            
           
         }
         break;
      case PO_Start_R:
         if (!btnR) {
             leftwin=1;
             rightwin=0;
            state = PO_Start_R;
         }
         else if (btnR) {
            btnR = 0;
            state = PO_Shift;
         }
         break;
      case PO_Start_L:
         if (!btnL) {
             leftwin=0;
             rightwin=1;
            state = PO_Start_L;
         }
         else if (btnL) {
            btnL = 0; 
            state = PO_Shift;
         }
         break;
      case PO_LEFT_POS:
         if (btnL) {
            state = PO_Shift;
            dir = !dir;
            btnL=0;
         }
         else if (!btnL) {
           
            state = PO_Over;
         }
         break;
      case PO_RIGHT_POS:
         if (btnR) {
            state = PO_Shift;
            dir = !dir;
            btnR=0;
         }
         else if (!btnR) {
           
            state = PO_Over;
         }
         break;
      case PO_Over:
          gameover=1;
          state = PO_Flash_ON;
         break;
           case PO_Flash_ON:
         if (1) {
            state = PO_Flash_OFF;
         }
         break;
      case PO_Flash_OFF:
         if (count < 3 ) {
            state = PO_Flash_ON;
            count ++ ; 
         }
         else if (count >= 3) {
            count= 0 ; 
            state = PO_Speed_UP;
         }
         break;
      case PO_Speed_UP:
         if (!startgame) {
            state = PO_Over;
         }
         else if (startgame && start == 0) {
            state = PO_Start_L;
            startgame = 0;
         }
         else if (startgame && start != 0) {
            state = PO_Start_R;
            startgame = 0;
         }
         break;
default:
         state = -1;
      } // Transitions

   switch(state) { // State actions
      case PO_Shift:
         if(dir==0){
            outval = outval<<1;
            }else{
            outval = outval>>1;
            }
         break;
      case PO_Start_R:
         dir = 0;
         outval = 0x0001;
         break;
      case PO_Start_L:
      dir = 1;
         outval=0x0080;
         break;
      case PO_LEFT_POS:
         break;
      case PO_RIGHT_POS:
         break;
      case PO_Over:
         
         break;
            case PO_Flash_ON:
         if(leftwin & !rightwin) {
         outval = 0x0080;
         }
         else if(!leftwin & rightwin){
         outval = 0x0001; 
         }
         break;
      case PO_Flash_OFF:
         outval = 0x0000; 
         break;
      case PO_Speed_UP:
         delay= delay - 50; 
         startgame = 1 ; 
         leftwin=0; 
         rightwin=0;
         break;
         
         
      default: 
         break;
   } 
   PO_State = state;
   return state;
}

