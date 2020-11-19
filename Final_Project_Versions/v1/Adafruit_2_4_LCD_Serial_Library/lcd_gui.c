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
   
tft_fillRoundRect(p.x, p.y, 60, 20, 0, color);
}

void drawBall(Ball b, int color) {
  tft_fillCircle(b.x ,b.y, 10, color);
}

void draw(Paddle p1, Paddle p2, Ball ball, int color) {
    int i, j;

    
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