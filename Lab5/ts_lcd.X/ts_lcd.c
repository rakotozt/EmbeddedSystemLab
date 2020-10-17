#include "ts_lcd.h"

#define DW 320
#define DH 240
#define TY_MAX 920 
#define TY_MIN 135 
#define TX_MAX 860
#define TX_MIN 180 
#define TX_ERROR -36; 
#define TY_ERROR -1; 

uint8_t ts_lcd_get_ts(uint16_t *x, uint16_t *y){ 

           
    struct TSPoint pos;
        pos.x = 0;
        pos.y = 0;
        pos.z = 0; 
        getPoint(&pos);
       

        
         *y = ((pos.x-TX_MIN)*(DH-0)/(TX_MAX-TX_MIN))+ 0+TY_ERROR;
         *x = ((TY_MAX-(pos.y-TY_MIN)) * (DW-0) / (TY_MAX-TY_MIN)) + 0+TX_ERROR;
        
        if(*x>DW){
            if(*x>60000){
                *x = 0;
            }else{
                *x = DW;
            }
        }

        if(*y>DH){
            if(*y>60000){
                *y = 0;
            }else{
                *y = DH;
            }
        }
    
}

void ts_lcd_init() { 

    ANSELA = 0; 
    ANSELB = 0; 

    CM1CON = 0; 
    CM2CON = 0;
   
   
    SYSTEMConfigPerformance(PBCLK);
    
    configureADC();
    
    
    tft_init_hw();
    tft_begin();
    tft_setRotation(3); 
    tft_fillScreen(ILI9341_BLACK);  
    
}
