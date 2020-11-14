#ifndef GAME_FSM_H
#define	GAME_FSM_H
#include <xc.h> 
#include <inttypes.h>


// BTN1 Debouncer 
extern  int TickFct_BtnL(int state); 

// BTN2 Debouncer 
extern  int TickFct_BtnR(int state) ; 

// Bounce State 
extern  int TickFct_PO(int state);

#endif