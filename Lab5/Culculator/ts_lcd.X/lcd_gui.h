
#ifndef LCD_GUI_H
#define	LCD_GUI_H
#define _SUPPRESS_PLIB_WARNING
#include <inttypes.h>


struct Button {
	uint16_t x,y, width, height ;
	char value;
	uint32_t color ;
};
struct Button btn[4][4];


void intialButton(uint16_t width , uint16_t height);

void drawButton(struct Button btn,int color);

void clearDisplay(char* str);

void clearButton(struct Button btn);

#endif	
