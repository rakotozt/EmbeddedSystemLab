#include "game_fsm.h"

extern uint8_t btnR;
extern uint8_t btnL;


extern uint8_t pdlL;
extern uint8_t pdlR;
extern uint8_t direction;
extern uint8_t direction2;
extern uint8_t gameover;
extern int speedY;
extern int speedX;
extern uint8_t speed;
extern uint8_t sound;
extern int yposB;
extern int xposB;
extern uint8_t leftWin;
extern uint8_t rightWin;
extern uint8_t pWidth;
extern uint8_t pLength;
extern uint8_t scoreL;
extern uint8_t scoreR;
extern uint8_t maxScore;
extern uint8_t leftContact; 
extern uint8_t rightContact;
extern uint8_t state;
extern uint8_t up;
extern uint8_t initial;

#define DW          320
#define DH          240
#define MAX_X       320
#define MAX_Y       240
#define PADDLE_HEIGHT 60


enum PNG_States { PNG_Initial, PNG_Start_L, PNG_Move, PNG_StartR, PNG_Left, PNG_Right, PNG_Restart, PNG_Gameover } PNG_State;

TickFct_Pong_game() {
   switch(PNG_State) { // Transitions
      case -1:
         PNG_State = PNG_Initial;
         break;
               case PNG_Initial:
                   
                   if(PORTBbits.RB9==0 || PORTBbits.RB7 ){
                       initial=1;
                   PNG_State = PNG_Start_L;}
                   else{
                       initial=0;
         PNG_State = PNG_Initial;}
         break;
         case PNG_Start_L:
         if (PORTBbits.RB9==0) {
          
            PNG_State = PNG_Move;
         }
         else if (PORTBbits.RB9==1) {
          
            PNG_State = PNG_Start_L;
         }
         sound=1; 
         break;
      case PNG_Move:
         if (xposB>=320-(pWidth+(pWidth/2))) {
             xposB=320-(pWidth+(pWidth/2));
            PNG_State = PNG_Right;
         }

         else if (xposB<=pWidth+(pWidth/2)) {
             xposB=(pWidth+(pWidth/2));
             PNG_State = PNG_Left;
         }
         
         else {   
            if (yposB <= 20) {
            yposB = 20;
           speedY =20;
           up=1;
            
       
       }else if (yposB >= MAX_Y-20) {
           yposB = MAX_Y-20;
            speedY = -20;
            up=0;
         
       } 
             
            PNG_State = PNG_Move;
         }
         break;
      case PNG_StartR:
         if (PORTBbits.RB7==0) {
         
            PNG_State = PNG_Move;
         }
         else if (PORTBbits.RB9==1) {
           
            PNG_State = PNG_StartR;
            sound=1; 
         }
         break;
      case PNG_Left:
         if ((yposB > pdlL && yposB < pdlL + pLength)) {  
             PNG_State = PNG_Move;
         }
         else  {
            PNG_State = PNG_Restart;
            rightWin=1;
            leftWin=0;
            
         }
         break;
      case PNG_Right:
         if (((yposB > pdlR && yposB < pdlR + pLength))) {
            PNG_State = PNG_Move;
         }
         else {
             xposB=xposB+speedX;
             yposB=yposB+speedY;
            PNG_State = PNG_Restart;
           
            rightWin=0;
            leftWin=1;
            
         }
         break;
      case PNG_Restart:
         if ((scoreL == maxScore)||(scoreR == maxScore)) {
            
             PNG_State = PNG_Gameover;
         }
         else if ((scoreR<maxScore) && leftWin) {
            PNG_State = PNG_StartR;
            leftWin=0;
         }
         else if ((scoreL<maxScore) && rightWin) {
            PNG_State = PNG_Start_L;
            rightWin = 0;
         }
         break;
      case PNG_Gameover:
         break;
      default:
         PNG_State = PNG_Start_L;
   } // Transitions

   switch(PNG_State) { // State actions
      case PNG_Initial:
          initial=0;
           break;
       case PNG_Start_L:
         xposB = pWidth+(pWidth/2);
         yposB = pdlL + (pLength/2);
         direction = 1;
         state=1;     
         up=1;
         sound=0;
         break;
         
      case PNG_Move:
         
////         //bounce on y - axis
          if(up==1){speedY=20;}
          else if(up==0){speedY=-20;}
 
          
         //movement in x-axis      
         if(direction==0){
             yposB = yposB + speedY;
             xposB = xposB - speedX;
         }
         else{
             yposB = yposB + speedY;
             xposB = xposB + speedX;
         }
         
       
        state=2; 
        sound=0;
         break;
      case PNG_StartR:
         xposB = 320-(pWidth+(pWidth/2));
         yposB = pdlR + pLength/2;
         direction =0;
         state=3;
         
         break;
      case PNG_Left:
                 if (yposB <= pdlR + 20){
             speedX=40;
             }
                 else if((yposB <= pdlR+40)&&(yposB > pdlR+20)){
             speedX=20;
             }
                 else if((yposB <= pdlR+ 60)&&(yposB > pdlR+40)){
             speedX=40;
             }
          
          direction =1;
         state=4;
         sound=1;
         break;
      case PNG_Right:
          
           if (yposB <= pdlR + 20){
             speedX=40;
             }
           else if((yposB <= pdlR+40)&&(yposB > pdlR+20)){
             speedX=20;
             }
           else if((yposB <= pdlR+ 60)&&(yposB > pdlR+40)){
             speedX=40;
             }
          
         direction =0;
         state=5;
         sound=1;
         break;
      case PNG_Restart:
         if (leftWin){
         scoreL ++;}
         else if(rightWin){
         scoreR++;
         }
         state=6;
         sound=0;
         break;
      case PNG_Gameover:
         gameover =1;
         state=7;
         sound=0;
         break;
      default: // ADD default behaviour below
      break;
   } // State actions

}


enum btnR_States { btnR_NO_PUSH, btnR_MAYBE_PUSH, btnR_PUSHED, btnR_MAYBE_NOPUSH } btnR_State;

int TickFct_btnR(int state) {


   switch(state) { // Transitions
      case -1:
         state = btnR_NO_PUSH;
         break;
      case btnR_NO_PUSH:
         if (btnR_read()==1) {
            state = btnR_MAYBE_PUSH;
            //btnR = 1 ;
         }
         break;
      case btnR_MAYBE_PUSH:
         if (btnR_read()==0) {
            state = btnR_NO_PUSH;
         }
         else if (btnR_read()==1) {
            state = btnR_PUSHED;
            btnR = 1 ;
         }
         break;
      case btnR_PUSHED:
         if (btnR_read()== 0) {
            state = btnR_MAYBE_NOPUSH;
         }
         break;
      case btnR_MAYBE_NOPUSH:
         if (btnR_read()== 0) {
            state = btnR_NO_PUSH;
         }
         else if (btnR_read()!= 0) {
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
         if (btnL_read()==1) {
            state = btnL_MAYBE_PUSH;
            //btnR = 1 ;
         }
         break;
      case btnL_MAYBE_PUSH:
         if (btnL_read()==0) {
            state = btnL_NO_PUSH;
         }
         else if (btnL_read()==1) {
            state = btnL_PUSHED;
            btnL = 1 ;
         }
         break;
      case btnL_PUSHED:
         if (btnL_read()== 0) {
            state = btnL_MAYBE_NOPUSH;
         }
         break;
      case btnL_MAYBE_NOPUSH:
         if (btnL_read()== 0) {
            state = btnL_NO_PUSH;
         }
         else if (btnL_read()!= 0) {
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
      default: 
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



