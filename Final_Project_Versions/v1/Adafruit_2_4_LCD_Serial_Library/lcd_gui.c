#include "lcd_gui.h"
#include "tft_gfx.h"
#include "adc_intf.h"
#include "types.h"
#include "tft_master.h"
#include <xc.h>
#include <plib.h>
#include <stdio.h>
#include <stdlib.h>

#define DW 320
#define DH 240

uint8_t game[320*4] = {0};
void drawPaddle(Paddle p, int color) {
   
tft_fillRoundRect(p.x, p.y, 60, 10, 0, color);
}

void drawBall(Ball b, int color) {
  tft_fillCircle(b.x ,b.y, 5, color);
}

void draw(Paddle p1, Paddle p2, Ball ball, int color) {
    int i, j;

    separationLine();
    drawPaddle(p1,color);
    drawPaddle(p2,color);
    drawBall(ball,color);
   
 
}

/*
 * Reset display
 */
void clearGame() {
    int i;
    for (i = 0; i < sizeof(game); i++) { game[i] = 0; }
}


void clearDisplay() {

	tft_fillScreen(ILI9341_BLACK);

}

void separationLine() {
    int j; 
    for(j=0;j<DH;j++){
        int x=DW/2;
        int y=j*10;
        int l=5;
        int w=5;
        int color=ILI9341_WHITE;
	tft_fillRoundRect(y,x,l, w,0,color );
    }

}