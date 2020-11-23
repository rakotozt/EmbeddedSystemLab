#define _SUPPRESS_PLIB_WARNING
#ifndef READING_INTERPRETER_H
#define	READING_INTERPRETER_H

#include <plib.h>

#include "ts_lcd.h"
#include "lcd_gui.h"

#include "ts_lcd.h"
#include "lcd_gui.h"


#define XM AN0
#define YP AN1
#include <xc.h> 
#include <inttypes.h>

enum in{IDLE = -1, ZERO=0, ONE=1, TWO=2, THREE=3, FOUR=4, FIVE=5, SIX=6, SEVEN=7, EIGHT=8, NINE=9, PLUS=10, MINUS=11, MULT=12, 
	DIV=13, EQU=14, CLR=15};

enum in reading_interpreter(uint16_t x, uint16_t y); 

#endif	

