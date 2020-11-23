#include "lcd_gui.h"

#include "tft_gfx.h"
#include "adc_intf.h"
#include "TouchScreen.h"
#include "tft_master.h"
#include <xc.h>
#include <plib.h>
#include <stdio.h>
#include <stdlib.h>

char debug[64] ;
int red=0xF800;
int blue=0x001F;
int yellow=0xAFE5; 
int grey=0x7BEF; 
void initialButton(uint16_t width , uint16_t height){

 int w ;
 int h;
 int count;

 for (w=0; w < 4 ; w++){
 	for (h = 0; h < 4 ; h++){
 		btn[w][h].x = w*width;
 		btn[w][h].y = h*height+40;
 		btn[w][h].width = width;
 		btn[w][h].height = height;
		btn[w][h].color = ILI9341_RED;//Cyan
	}
 }
 btn[0][0].value = '7';
 btn[1][0].value = '8';
 btn[2][0].value = '9';
 btn[3][0].value = '+';

 btn[0][1].value = '4';
 btn[1][1].value = '5';
 btn[2][1].value = '6';
 btn[3][1].value = '-';

 btn[0][2].value = '1';
 btn[1][2].value = '2';
 btn[2][2].value = '3';
 btn[3][2].value = 'x';

 btn[0][3].value = '0';
 btn[1][3].value = 'C';
 btn[2][3].value = '=';
 btn[3][3].value = '/';
}

void drawButton(struct Button btn,int color){
    
    short xc=(short) btn.x; 
    short yc=(short) btn.y; 
    short w=(short) btn.width*0.9;
    short h=(short) btn.height*0.9;
    tft_fillRoundRect(xc,yc,w,h,1,color);
	tft_drawChar((btn.x+btn.width/2)-10,(btn.y+btn.height/2)-15, btn.value, ILI9341_WHITE,color , 3);
}


void display(char* str) {
	tft_setTextSize(3);
	tft_setCursor(0, 0);
	tft_setTextColor(ILI9341_WHITE);
	tft_writeString(str); 


	int row;
	int column;
	
	for (row = 0 ; row < 4; row++){
		for (column = 0; column < 4; column++) {
            if(row==1 && column==3 ){drawButton(btn[row][column],blue);}
            else if(row==3){drawButton(btn[row][column],yellow);}
            else
			{drawButton(btn[row][column],grey) ;}
		}
	}
}


void clearDisplay(char* str) {
	tft_setTextSize(3);
	tft_setCursor(0, 0);
	tft_setTextColor(ILI9341_BLACK);
	tft_writeString(str); 
}

