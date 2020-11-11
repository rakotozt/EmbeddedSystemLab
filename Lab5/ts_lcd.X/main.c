
 // Configure clocks
 #pragma config FNOSC = FRCPLL, POSCMOD = OFF
 #pragma config FPLLIDIV = DIV_2, FPLLMUL = MUL_20 //40 MHz
 #pragma config FPBDIV = DIV_1, FPLLODIV = DIV_2 // PB 40 MHz
 #pragma config FWDTEN = OFF,  FSOSCEN = OFF, JTAGEN = OFF

 #include "tft_gfx.h"
 #include "adc_intf.h"
 #include "TouchScreen.h"
 #include "tft_master.h"

 #include <xc.h>
 #include <plib.h>

#include "reading_interpreter.h"
 #include "ts_lcd.h"
 #include "lcd_gui.h"
#include "Pong FSM.h"

 #include <stdio.h>
 #include <stdlib.h>

 #define XM AN0
 #define YP AN1
#define DW 320
#define DH 240
#define TY_MAX 920 
#define TY_MIN 135 
#define TX_MAX 860
#define TX_MIN 180 

/*
 * 
 */
int main(int argc, char** argv) {
    uint16_t x;
    uint16_t y;
    ts_lcd_init();
    initialButton(80, 50);

    uint16_t ts_x = 0;
    uint16_t ts_y = 0;
    enum in input;

     while(1){
         
        if(ts_lcd_get_ts(&x, &y)){ 
            ts_x = x;
            ts_y = y;
            input = reading_interpreter(ts_x, ts_y);
        }

        if(input == CLR){
            CLC_State = CLC_Idle;
            arg1 = 0;
            arg2=0;
            result = 0;
        }
        
        TickFct_Calculator(input);
        display(out);
        delay_ms(100);
        clearDisplay(out);
      
     }


     return (EXIT_SUCCESS);
 }
