
//=============================================================
//Recent
// 40 MHz
#pragma config FNOSC = FRCPLL, POSCMOD = OFF
#pragma config FPLLIDIV = DIV_2, FPLLMUL = MUL_20 //40 MHz
#pragma config FPBDIV = DIV_1, FPLLODIV = DIV_2 // PB 40 MHz
#pragma config FWDTEN = OFF,  FSOSCEN = OFF, JTAGEN = OFF

//==============================================================

#include <stdlib.h>
#include "uart1.h" 
#include <string.h>
#include <plib.h>
#include <xc.h>
#include <inttypes.h>
#include <stdio.h> 
#include "tft_master.h"
#include "config.h"
#include "pt_cornell_1_2.h"
#include "output_Compare.h"
#include "ts_lcd.h"
#include "tft_gfx.h"
#include "adc_intf.h"
#include "tft_master.h"
#include "ts_lcd.h"
#include "input_capture.h"
#include "pid_control.h"

#define DW 320
#define DH 240
#define MAX_VAL  5000 

int32_t Kp, Ki, Kd, errorPrev, actuator, deriv, Integ;



// === UART Thread =================================================
static struct pt pt_uart ; 
static uint16_t fan ;
static char display_str [64];
static uint16_t targ_rate;
static uint16_t rpm; 
uint16_t interp; 

uint16_t pointtime=0;
static PT_THREAD (protothread_uart( struct pt *pt)) { 
    static char in_str [64]; 
    static char str_val[64]; 
    static uint8_t char_in;
    static uint8_t *c;
    static uint16_t targetTmp; 
    

    PT_BEGIN(pt);
    while(1){ 
      targetTmp = 0;
        PT_YIELD_TIME_msec(100); 
        if (uart1_rxrdy()) {
            char_in = uart1_rxread(); 
            if ((char_in == 13)){
              strncpy(display_str , in_str,64); 
              uart1_txwrite_str(in_str) ;
             
              // Set Target Rate
              if (in_str[0] == 's' ){
                PORTClearBits(IOPORT_B, BIT_8); 
                PT_YIELD_TIME_msec(5);
                for(c = &in_str[2];*c != '\0'; c++){
                  targetTmp = targetTmp*10 + (uint16_t)(*c-48); 
                }
                targ_rate = targetTmp;
              }
              // Set Proportional Gain
              else if (in_str[0] == 'p'){
                for(c = &in_str[2];*c != '\0'; c++){
                  targetTmp = targetTmp*10 + (uint16_t)(*c-48); 
                }
                Kp = targetTmp;
              } 
              // Set Integral Gain
              else if (in_str[0] == 'i')
              {
                for(c = &in_str[2];*c != '\0'; c++){
                  targetTmp = targetTmp*10 + (uint16_t)(*c-48); 
                }
                Ki = targetTmp;
              }
              // Set Derivative Gain
              else if (in_str[0] == 'd') {
                for(c = &in_str[2];*c != '\0'; c++){
                  targetTmp = targetTmp*10 + (uint16_t)(*c-48); 
                }
                Kd = targetTmp;  
              }
              sprintf(str_val," New Input: %d \n\r", targetTmp);
              uart1_txwrite_str(str_val);

              sprintf(in_str,""); 
              PORTSetBits(IOPORT_B, BIT_8); 
            }   
            else{
                sprintf( in_str,"%s%c", in_str, char_in) ; 
            } 
   
        }  

    }
    
    PT_END(pt); 
          
}// uart thread 


//display thread-------------------------------
static struct pt pt_lcd ; 
int pointCount=0;
int temp=0;
int temp1 = 0;
int time=0;
static PT_THREAD (protothread_lcd(struct pt *pt)) { 
    PT_BEGIN(pt);
    static char buffer[64];
  
    while(1){
     sprintf(buffer, "In: %s Targ Rate: %d Cur RPM: %d Kp:%d Ki:%d Kd:%d",
     display_str, targ_rate, rpm, Kp, Ki, Kd);
      display(buffer);

      if(rpm>20){
        pointCount=pointCount+10;
        graphDisplay(temp,rpm,temp1, targ_rate, pointCount, time, pointtime);
        time=time + 5;
        pointtime +=40;
        if(pointtime>=320){
            pointtime=0;
            tft_fillRoundRect(0,200, 320, 40, 0, ILI9341_BLACK);
        }
      }
        temp1=temp;
        temp=rpm;
        
      PT_YIELD_TIME_msec(100); // Wait for 100ms 
      clearDisplay(buffer);

      
      if(pointCount>DW){
          tft_fillScreen(ILI9341_BLACK);
          pointCount=0;
          
      }
      
    }
    PT_END(pt); 
          
}
//display thread -------------------------------

//RPM thread-------------------------------
static struct pt pt_rpm ; 

static PT_THREAD (protothread_rpm(struct pt *pt)) { 
    PT_BEGIN(pt);
    interp = 1000;
    while(1){
      interp += 10;
      if(interp >= 200){
        rpm = 0;
      }else{
        rpm = 9375000/ic1_getperiod();
      }
      PT_YIELD_TIME_msec(10);
    }
    PT_END(pt); 
}
//RPM thread ------------------------------

//PID thread-------------------------------
static struct pt pt_pid ; 

static PT_THREAD (protothread_pid(struct pt *pt)) { 
   
    PT_BEGIN(pt);

    oc1_setduty_plib(pid(targ_rate - rpm, fan));
    PT_YIELD_TIME_msec(10);
    PT_END(pt); 
}
//PID thread-------------------------------

// round-robin scheduler for threads--------------------------------------------
int main(int argc, char** argv) {
  mPORTBSetPinsDigitalOut(BIT_8); 
    PORTSetBits(IOPORT_B, BIT_8); 

    targ_rate = 0;
   fan = 0; 
   rpm= 1500; 
   ic1_init();
   
   ts_lcd_init();
   tft_fillScreen(ILI9341_BLACK);//refresh

    oc1_init_plib(0x0000);
    
    SYSTEMConfigPerformance(PBCLK);
    uart1_init(9600);
    uart1_txwrite_str("The code is starting\n\r");

    pid_init();
    
    // Configure Threads
    PT_setup() ;  
    
    //SetUp System Interupts 
    INTEnableSystemMultiVectoredInt();

    // Initialize The Threads 
    PT_INIT(&pt_uart);
    PT_INIT(&pt_lcd) ; 
    PT_INIT(&pt_rpm) ; 
    PT_INIT(&pt_pid) ; 


  while (1){
    PT_SCHEDULE(protothread_uart(&pt_uart));
    PT_SCHEDULE(protothread_lcd(&pt_lcd));
    PT_SCHEDULE(protothread_rpm(&pt_rpm));
    PT_SCHEDULE(protothread_pid(&pt_pid));

  }
    
    return (EXIT_SUCCESS);
}