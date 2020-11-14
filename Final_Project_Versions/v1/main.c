/*============================================================================
 * main.c
 *      Example code to show how to use the TFT display.  Writes some text
 * as well as some random lines and circles.
 *===========================================================================*/

#define _SUPPRESS_PLIB_WARNING 1

// Configure clocks
#pragma config FNOSC = FRCPLL, POSCMOD = OFF
#pragma config FPLLIDIV = DIV_2, FPLLMUL = MUL_20 //40 MHz
#pragma config FPBDIV = DIV_1, FPLLODIV = DIV_2 // PB 40 MHz
#pragma config FWDTEN = OFF,  FSOSCEN = OFF, JTAGEN = OFF

#include "tft_master.h"
#include "tft_gfx.h"
#include "adc_intf.h"
#include "types.h"
#include <stdlib.h>
#include <inttypes.h>

// Convenient defines for width and height of display
#define DW          320
#define DH          240
#define MAX_X       320
#define MAX_Y       240

#define MAX_RAD     50
#define PADDLE_HEIGHT 20

Paddle p1, p2;
Ball ball;

void main()
{   
//     p1.x=0;
//     p1.y=(readADC(11)/5.7);
//     
//     p2.x=300;
//     p2.y=(readADC(11)/5.7);
//     
//    ball.x = 61;
//    ball.y = 15;
//    ball.speedX = 2;
//    ball.speedY = 1;   
//     
         ball.x = DW/2;
    ball.y = DH/2;
    ball.speedX = 20;
    ball.speedY = 10;      
    static int8_t buffer[64];
    uint32_t i, idx;
    
    // Turn off analog function of Ports A and B
    ANSELA = 0; 
    ANSELB = 0; 
    
    // Turn off comparator functions
    CM1CON = 0; 
    CM2CON = 0;
    configureADC();
    
    // Initialize TFT
    tft_init_hw();
    tft_begin();

     tft_setRotation(3);  // Landscape mode.  Use 1 for portrait.

    idx = 0;
    while (1)
    {
     p1.x=0;
     p1.y=(readADC(11)/5.7);
     
     p2.x=300;
     p2.y=(readADC(5)/5.7);
     
   
     advance() ;    
        // Clear the screen
        tft_fillScreen(ILI9341_BLACK);

        // Draw some text
        tft_setCursor(0, 0);  // Upper Left Hand Corner
        tft_setTextColor(ILI9341_WHITE);  tft_setTextSize(2);

     //   tft_writeString("Hello World from the other side");
        for (i=1; i<10; i++)
        {
             
            tft_setCursor(0, i*20);
            //sprintf(buffer, "The index is %d", readADC(5));
            tft_writeString(buffer);     
          
           // tft_fillRoundRect(p1.x, p1.y, 20, 60, 0, ILI9341_BLUE);
            drawPaddle(p1);
            drawPaddle(p2);
            drawBall(ball);
            
            //tft_fillRoundRect(320-20, (readADC(5)/5.7), 20, 60, 0, ILI9341_BLUE);
            //tft_fillRoundRect(0, (readADC(11)/5.7), 20, 60, 0, ILI9341_RED);
        }

        // Wait a bit.  In real code, use a timer!
        for (i=0; i<1000000; i++) { }        
    }    
    
}

/*
 * One frame of the game
 */
void advance() {
    ball.x = (ball.x + ball.speedX);
    ball.y = (ball.y + ball.speedY);

    // vertical collision detection
    if (ball.y <= 0) {
        ball.y = 0;
        ball.speedY *= (-1);
    }else if (ball.y >= MAX_Y - 1) {
        ball.y = MAX_Y - 1;
        ball.speedY *= (-1);
    }

    // horizontal collision detection
    if (ball.x <= 0) {
        // score for p1?
        if (ball.y < p1.y || ball.y > p1.y + PADDLE_HEIGHT - 1) { p2.score += 1; }

        ball.x = 0;
        ball.speedX *= (-1);
    }else if (ball.x >= MAX_X - 1) {
        // score for p1?
        if (ball.y < p2.y || ball.y > p2.y + PADDLE_HEIGHT - 1) { p1.score += 1; }

        ball.x = MAX_X - 1;
        ball.speedX *= (-1);
    }
}


void drawPaddle(Paddle p) {
   
tft_fillRoundRect(p.x, p.y, 20, 60, 0, ILI9341_BLUE);
}

/*
 * Draw ball
 */
void drawBall(Ball b) {
  tft_fillCircle(b.x ,b.y, 10, ILI9341_GREEN);
}



