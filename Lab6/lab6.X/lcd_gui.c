#include "lcd_gui.h"

#include "tft_gfx.h"
#include "adc_intf.h"
#include "tft_master.h"
#include "ts_lcd.h"
#include <xc.h>
#include <plib.h>
#include <stdio.h>
#include <stdlib.h>

#define DW 320
#define DH 240
#define TY_MAX 920 
#define TY_MIN 135 
#define TX_MAX 860
#define TX_MIN 180 
#define TX_ERROR -36
#define TY_ERROR -1

#define MAX_VAL  3000 


void display(char* str) {
    //memset(buffer,0,sizeof(buffer)); // clears char array
	//buffer = "";//clear buffer
	tft_setTextSize(1.5);
	tft_setCursor(0, 20);
	tft_setTextColor(ILI9341_WHITE);
	//write command
	//sprintf(buffer, "Command: %s\nTarget rate: \n%d\nCurrent RPM: \n%d", display_str, t_rate, rpm);
	tft_writeString(str);
}

//clear the display
void clearDisplay(char* str) {
	tft_setTextSize(1.5);
	tft_setCursor(0, 20);
	tft_setTextColor(ILI9341_BLACK);
	tft_writeString(str); // Use this to write a string
}  
void rpmvalues(){
tft_fillRoundRect(0,0, 320, 240, 0, ILI9341_BLACK);
}

void graphDisplay(uint16_t temp,uint16_t rpm,uint16_t temp1, uint16_t targetTmp,int point, int time, uint16_t pointtime){
 
    tft_drawLine((short) point-10,(short)(DH-((DH*temp)/MAX_VAL)),(short)(point),(short) (DH-((DH*rpm)/MAX_VAL)),ILI9341_RED);
    tft_drawLine((short) point-10,(short)(DH-((DH*targetTmp)/MAX_VAL)),(short)(point),(short) (DH-((DH*targetTmp)/MAX_VAL)) ,ILI9341_GREEN);
    
    int numbers=0; 
    for (numbers=0; numbers<4;numbers++){
        int yValue=(DH-((DH*(numbers*1000))/MAX_VAL));
    tft_setTextSize(1);
    tft_setCursor(0,yValue);
    char val[50];
    sprintf(val, "%d",numbers*1000);
    tft_writeString(val);
        
        
        
    }

    tft_setTextSize(1);
    tft_setCursor(pointtime, DH - 10);
    char val[50];
    sprintf(val, "%d", time);
    tft_writeString(val);
    
    
}
