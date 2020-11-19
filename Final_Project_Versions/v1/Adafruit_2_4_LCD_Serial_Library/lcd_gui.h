
#ifndef LCD_GUI_H
#define	LCD_GUI_H
#define _SUPPRESS_PLIB_WARNING
#include <inttypes.h>
#include "types.h"


void drawPaddle(Paddle p, int color) ;
void drawBall(Ball b,int color) ;
void draw(Paddle p1, Paddle p2, Ball ball,int color);
void clearGame();


#endif	
