/*
 * File:   C_main.c
 * Author: crdhi & rakotozt
 *
 * Created on September 8, 2020, 10:04 AM
 */

#include <xc.h>
#include <inttypes.h>
//#include "porta_in.h"
//#include "portb_out.h"

extern uint8_t btnR;
extern uint8_t btnL;
unsigned int timecount;
extern uint8_t leftwin;
extern uint8_t rightwin;
extern uint8_t gameover;
extern uint8_t flashcount;
extern uint8_t outval;
extern uint8_t randomstate;
extern uint16_t delay;
extern uint8_t dir;

enum PO_States{ PO_RANDOM, PO_START_R, PO_SHIFT, PO_START_L, PO_LEFT_POS, PO_RIGHT_POS, PO_GAMEOVER, PO_FLASH_ON, PO_FLASH_OFF, PO_OVER}PO_State;

void tickFct_PO()

{
    switch (PO_State) {//transition
        case PO_RANDOM:
            if (randomstate){
               PO_State = PO_START_R ;
            }
            else{
                PO_State = PO_START_L;
            }

        case PO_START_R:
            if (!btnR){
            PO_State = PO_START_R;
            }
            else if(btnR){
            PO_State = PO_SHIFT;
            }
            break;
        case PO_START_L:
            if (!btnL){
            PO_State = PO_START_L;
            }
            else if(btnL){
            PO_State = PO_SHIFT;
            }
            break;
        case PO_SHIFT:
            if ((outval>0x01)&&(outval<0x80)){
            PO_State = PO_SHIFT;
            }
            else if(outval==0x80){
            PO_State = PO_LEFT_POS;
            }
            else if(outval==0x01){
            PO_State = PO_RIGHT_POS;
            }
            else if(btnR||btnL){
            PO_State = PO_GAMEOVER;
            }
            break;
        case PO_LEFT_POS:
           // if ((timecount>=2)&&!btnL){ //////to be changed-probably
           if (!btnL){
            PO_State = PO_GAMEOVER;
            }
            //else if((timecount<=2)&&btnL){
            else if(btnL){
            leftwin=0;
            rightwin=1;
            PO_State = PO_SHIFT;
            }
            break;
            case PO_RIGHT_POS:
            //if ((timecount>=2)&&!btnR){ //////to be changed-probably
            if(!btnR){
            PO_State = PO_GAMEOVER;
            }
            //else if((timecount<=2)&&btnR){
            if(btnR){
            leftwin=1;
            rightwin=0;
            PO_State = PO_SHIFT;
            }
            break;

        case PO_GAMEOVER:
            PO_State = PO_FLASH_ON;
            break;
        case PO_FLASH_ON:
            PO_State = PO_FLASH_OFF;
            break;
        case PO_FLASH_OFF:
            if(flashcount>=3){
            PO_State = PO_OVER;
			      }

			     else{
			     PO_State = PO_FLASH_ON;
			      }
         break;
         case PO_OVER:
			    PO_State = PO_RANDOM;
        default:
         PO_State = PO_RANDOM;
            break;
    }







    switch (PO_State) {
        case PO_RANDOM:
             randomstate = rand()%2;
            break;

		   case PO_START_R:
		       outval =0x01;
		       timecount = 0;
           rightwin=0;
           leftwin=0;
           dir=0;
		      break;
		   case PO_START_L:
		       outval =0x80;
		       timecount = 0;
           rightwin=0;
           leftwin=0;
           dir=1;
	         break;
		 case PO_SHIFT:
           timecount = 0;
         if(dir==0){outval<<1;}
         else{outval>>1;}
		       break;
		case PO_LEFT_POS:
		      timecount++;
		      break;
		case PO_RIGHT_POS:
		     timecount++;
		     break;
		case PO_GAMEOVER:
			    gameover=1;
			break;
    case PO_FLASH_ON:
            if(!leftwin & rightwin){
            outval = 0x01;
            }
            else if (leftwin & !rightwin){
                outval = 0x80;
            }
          else{outval=0xff;}
            break;
        case PO_FLASH_OFF:
            outval = 0x00;
            flashcount++;
            break;
        case PO_OVER:
            outval=0x00;
            leftwin=0;
            rightwin=0;
            gameover=0;
            delay=0;
            break;
        default:
               outval = 0x00;
    }
}
