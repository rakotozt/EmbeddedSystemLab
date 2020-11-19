  
#ifndef GAME_FSM_H
#define	GAME_FSM_H
#include <xc.h> 
#include <inttypes.h>


extern int TickFct_Pong_game() ;
// BTN2 Debouncer 
extern  int TickFct_BtnR(int state) ; 

extern int TickFct_pdl(int state);

#endif