Pong FSMlib.h>

#include <stdio.h>
#include <stdlib.h>
/*Define user variables and functions for this state machine here.*/
unsigned char PNG_Clk;
void TimerISR() {
   PNG_Clk = 1;
}

//declare all the variables
uint8_t paddlewidth;
uint8_t rightWin; 
uint8_t leftWin;
enum PNG_States { PNG_Start_L, PNG_Move, PNG_StartR, PNG_Left, PNG_Right, PNG_Restart, PNG_Gameover } PNG_State;

TickFct_Pong_game() {
   switch(PNG_State) { // Transitions
      case -1:
         PNG_State = PNG_Start_L;
         break;
         case PNG_Start_L: 
         if (pdlL==1) {
            PNG_State = PNG_Move;
         }
         else if (pdlL==0) {
            PNG_State = PNG_Start_L;
         }
         break;
      case PNG_Move: 
         if (xposB==width) {
            PNG_State = PNG_Right;
         }
         else if (xposB>=padlewidth && xposB<=320-paddlewidth;) {
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
         else if (pdlL!==xposB) {
            PNG_State = PNG_Restart;
            rightWin=0;
            leftWin=1;   
         }
         break;
      case PNG_Right: 
         if (xpdlL == xposB) {
            PNG_State = PNG_Move;
         }
         else if (pdlR!==xposB) {
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
         ypos = 120;
         sound = 0;
         direction = 1;
         break;
      case PNG_Move:
         if(direction==0){
         xposB = xPosB - speed;
         yposB = yposB;
         }
         else{
         xposB = xPosB + speed;
         yposB = yposB;
         }
         break;
      case PNG_StartR:
         xposB = 320-paddlewidth;
         ypos = 120;
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
         if (leftWin){
         scoreL ++;}
         else if(rightWin){
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

int main() {
   const unsigned int periodPong_game = 1000; // 1000 ms default
   TimerSet(periodPong_game);
   TimerOn();
   PNG_State = -1; // Initial state
   B = 0; // Init outputs

   while(1) {
      TickFct_Pong_game();
      while(!PNG_Clk);
      PNG_Clk = 0;
   } // while (1)
} // Main



