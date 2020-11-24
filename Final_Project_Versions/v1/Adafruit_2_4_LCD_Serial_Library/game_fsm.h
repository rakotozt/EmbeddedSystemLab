  
#ifndef GAME_FSM_H
#define	GAME_FSM_H
#include <xc.h> 
#include <inttypes.h>

char out[64];

extern int TickFct_Pong_game() ;

extern  int TickFct_BtnR(int state) ; 

extern int TickFct_pdl(int state);

extern int TickFct_btnL(int state) ;

#endif