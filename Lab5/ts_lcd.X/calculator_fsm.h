#define _SUPPRESS_PLIB_WARNING
#ifndef CALCULATOR_FSM_H
#define	CALCULATOR_FSM_H
#include "reading_interpreter.h" 
#include <string.h>
enum in in;

/*Define user variables and functions for this state machine here.*/
//for storing number in display
//uint8_t str[64];

char out[64];
int32_t arg1, arg2;
int32_t result; // Used in Perform Operation

//enum SM1_States { SM1_IDLE = 0, SM1_SHOWRESULT = 1, SM1_VALUEIN = 2, SM1_DIVCHECK = 3, SM1_DIV0ERROR = 4, 
//	SM1_OPERANDS = 5, SM1_OF_ERROR = 6 } SM1_State;
enum CLC_States { CLC_Idle, CLC_pResult, CLC_arg1, CLC_operand, CLC_arg2, CLC_operation , CLC_divERR,CLC_ERR } CLC_State;

enum in op; 

void TickFct_Calculator(enum in in);   
//void TickFct_State_machine_1(enum in in); 

int32_t operation( int32_t argument1, int32_t argument2, enum in mathOperator);


uint8_t overFlowCheck(int32_t num);

#endif