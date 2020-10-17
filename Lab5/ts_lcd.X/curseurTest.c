#include <xc.h>
#include <plib.h>
#include "config.h"
#include "adc_intf.h"
#include "TouchScreen.h"
#include "tft_master.h"
#include "tft_gfx.h"


#define DW 320 //x
#define DH 240 //y
#define TY_MAX 920 //y
#define TY_MIN 135 //y
#define TX_MAX 860 //x
#define TX_MIN 180 //x

int main(int argc, char** argv) {
   	uint16_t x;
	uint16_t y;
    char buffer[30];
    
    SYSTEMConfigPerformance(PBCLK);
    
    configureADC();
    
    //initialize screen
    tft_init_hw();
    tft_begin();
    tft_setRotation(3); 
    tft_fillScreen(ILI9341_BLACK);  
    
        uint16_t ts_x = TX_MIN;
    uint16_t ts_y = TY_MIN;
 int i;
    //unit test
    while(1){
        tft_fillScreen(ILI9341_BLACK);//refresh
    	if(ts_lcd_get_ts(&x, &y)){ //if touched
    		//convert touch xy to display xy
            ts_x = x;
            ts_y = y;
    	}

    	tft_setTextSize(2);
        tft_setCursor(0, 0);
        tft_setTextColor(ILI9341_WHITE);
    	sprintf(buffer,"x: %d, y: %d" , ts_x, ts_y);
    	tft_writeString(buffer);

//         tft_setTextSize(2);
//        tft_setCursor(0, 0);
//        tft_setTextColor(ILI9341_WHITE);
//    	sprintf(buffer,"Hello");
//    	tft_writeString(buffer);
        
        
    	//display crosshair
    	tft_drawLine(ts_x-10, ts_y-10, ts_x+10, ts_y+10, ILI9341_WHITE);
        tft_drawLine(ts_x+10, ts_y-10, ts_x-10, ts_y+10, ILI9341_WHITE);
        delay_ms(500);
    }


    return (EXIT_SUCCESS);
}
