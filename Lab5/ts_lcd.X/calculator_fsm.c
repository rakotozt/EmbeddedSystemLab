#include "calculator_fsm.h"

void TickFct_Calculator(enum in in ) {
    static enum in op;
   switch(CLC_State) { // Transitions
      case -1:
         CLC_State = CLC_Idle;
         break;
         case CLC_Idle: 
         if (1) {
             op=EQU;
            CLC_State = CLC_pResult;
         }
         break;
      case CLC_pResult: 
         if (in>=ZERO && in<=NINE && op==EQU) {
            CLC_State = CLC_arg1;
             
         }
         else if (in>=ZERO && in<=NINE && op!=EQU)
         {CLC_State = CLC_arg2;}
         break;
      case CLC_arg1: 
         if (in >=PLUS && in <= EQU) {
            CLC_State = CLC_operand;
            op=in;
         }
         else if (in>=ZERO && in<=NINE ) {
             arg1=arg1*10+in;
             if(!overFlowCheck(arg1)){
             CLC_State = CLC_arg1;}
             else{CLC_State =CLC_ERR;}
             
         }
         break;
      case CLC_operand: 
         if (in>=ZERO && in<=NINE) {
              arg2=arg2*10+in;
             if(!overFlowCheck(arg2)){
             CLC_State = CLC_arg2;}
         }
         else if (in >=PLUS && in <= EQU) {
            CLC_State = CLC_operand;
            op=in;
         }
         break;
      case CLC_arg2: 
         if (in>=ZERO && in<=NINE) {
             arg2=arg2*10+in; 
             if(!overFlowCheck(arg2)){
             CLC_State = CLC_arg2;}
             else{CLC_State =CLC_ERR;}
             
         }
         else if (in >=PLUS && in <= EQU && op==DIV && arg2==0) {
            CLC_State = CLC_divERR;
         }
         else if (in >=PLUS && in <= EQU && op!=DIV && arg2!=0) {
          result=operation(arg1,arg2,op);
          if(!overFlowCheck(result)){
          op=in;
            CLC_State = CLC_operation ;}
          else{CLC_State = CLC_ERR ;}
         }
         break;
      case CLC_operation : 
         if (1) {
            CLC_State = CLC_pResult;
         }
         break;
      case CLC_divERR: 
         break;
               case CLC_ERR: 
         break;
      default:
         CLC_State = CLC_Idle;
   } // Transitions

   switch(CLC_State) { // State actions
      case CLC_Idle:
         arg1=0; 
         arg2=0; 
         result=0;
         op=EQU;
         
         break;
      case CLC_pResult:
         sprintf(out, "%d", result);
         
         break;
      case CLC_arg1:
         sprintf(out, "%d", arg1);
         break;
      case CLC_operand:
         break;
      case CLC_arg2:
             sprintf(out, "%d", arg2);
         break;
      case CLC_operation :
        if(op==EQU)
           {arg1=0; 
             arg2=0;}
        else{
               arg1=result; 
              arg2=0;
                }

         break;
      case CLC_divERR:
             sprintf(out, "%s","DIV0");
         break;
            case CLC_ERR:
            sprintf(out, "%s","ERROR");
         break;
      default: // ADD default behaviour below
      break;
   } // State actions

}



int32_t operation(int32_t argument1, int32_t argument2, enum in mathOperator){ 


   switch (mathOperator){
      case PLUS: 
         return argument1+argument2 ;
         break ;

      case MINUS:
         return argument1-argument2; 
         break; 

      case MULT: 
         return argument1*argument2 ; 
         break; 

      case DIV: 
         return argument1/argument2;
         break;
      default:
         return 00000000;
         break;
   }
 }



uint8_t overFlowCheck(int32_t num){
   if(num<111111111){return 0;}
   else{return 1;}
}