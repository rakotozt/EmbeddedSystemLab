// Master header file for all peripheral library includes
 #include <plib.h>
 #include <stdio.h>
 #include "db_utils.h"
void delayms(unsigned int delay);
 // Configuration Bit settings
 // SYSCLK = 72 MHz (8MHz Crystal/ FPLLIDIV * FPLLMUL / FPLLODIV)
 // PBCLK = 36 MHz
 // Primary Osc w/PLL (XT+,HS+,EC+PLL)
 // WDT OFF
 // Other options are don't care
 //
 #pragma config FPLLMUL = MUL_18, FPLLIDIV = DIV_2, FPLLODIV = DIV_1, FWDTEN = OFF
 #pragma config POSCMOD = HS, FNOSC = PRIPLL, FPBDIV = DIV_2


#define FOSC 80000000 // 8MHz / FPLLIDIV * FPLLMUL / FPLLODIV
#define TOGGLES_PER_SEC 1000
#define CORE_TIMER_PERIOD (FOSC/2/TOGGLES_PER_SEC)
#define GetSystemClock() (FOSC)

 //*****************************************************************************
 /*****************************************************************************
 * DelayMs creates a delay of given miliseconds using the Core Timer
 */
#define MS_PERIOD (FOSC / 2000)
void DelayMs(WORD delay)
{ register unsigned int start;
    start = ReadCoreTimer();
    while( delay-- )
    {
        while((ReadCoreTimer() - start) < MS_PERIOD);
        start += MS_PERIOD;
    }
}

 unsigned int Pot; // conversion result as read from result buffer
 unsigned int offset; // buffer offset to point to the base of the idle buffer
 char str[100];
 int i;

 int main(void)
 {
 char choice;
 // Configure the device for maximum performance.
 // This macro sets flash wait states, PBCLK divider and DRM wait states based on the specified
 // clock frequency. It also turns on the cache mode if avaialble.
 // Based on the current frequency, the PBCLK divider will be set at 1:2. This knoweldge
 // is required to correctly set UART baud rate, timer reload value and other time sensitive
 // setting.
 SYSTEMConfigPerformance(72000000L);

 DBINIT(); //Initialize the IO channel
 DBGETC(&choice);
 db_puts("Analog Read", 13);
 // configure and enable the ADC
 // ensure the ADC is off before setting the configuration
 CloseADC10();

 // define setup parameters for OpenADC10
    // Turn module on | ouput in integer | trigger mode auto | enable autosample
 #define PARAM1 ADC_MODULE_ON | ADC_FORMAT_INTG | ADC_CLK_AUTO | ADC_AUTO_SAMPLING_OFF

 // define setup parameters for OpenADC10
       // ADC ref external | disable offset test | disable scan mode | perform 1 samples | use dual buffers | use alternate mode
 #define PARAM2 ADC_VREF_AVDD_AVSS | ADC_OFFSET_CAL_DISABLE | ADC_SCAN_OFF | ADC_SAMPLES_PER_INT_1 | ADC_ALT_BUF_ON | ADC_ALT_INPUT_ON

 // define setup parameters for OpenADC10
 // use ADC internal clock | set sample time
 #define PARAM3 ADC_CONV_CLK_INTERNAL_RC | ADC_SAMPLE_TIME_15

 // define setup parameters for OpenADC10
 // do not assign channels to scan
 #define PARAM4 SKIP_SCAN_ALL

 // define setup parameters for OpenADC10
    // set AN4 and AN5 as analog inputs
 #define PARAM5 ENABLE_AN0_ANA

 // configure to sample AN0
 // use ground as neg ref for A | use AN4 for input A |
 SetChanADC10( ADC_CH0_NEG_SAMPLEA_NVREF | ADC_CH0_POS_SAMPLEA_AN0 ); // configure to sample AN0

    // configure ADC using parameter define above
    OpenADC10( PARAM1, PARAM2, PARAM3, PARAM4, PARAM5 );

    // -- configure the ADC interrupt, priority level 2 --
    // NOTE: the C32 compiler manual uses ADC_INT_ENABLE for the enable flag
    // this is wrong, use ADC_INT_ON / ADC_INT_OFF
    ConfigIntADC10(ADC_INT_PRI_2 | ADC_INT_SUB_PRI_2 | ADC_INT_ON);

    // clear the interrupt flag
    mAD1ClearIntFlag();

    // Enable the ADC
    EnableADC10();

    // enable multi-vector interrupts
    INTEnableSystemMultiVectoredInt();

    // loop and wait for interrupts

    /***************************************************************/
    while (1);
 }

  /* ADC ISR */
  /* Specify ADC Interrupt Routine, Priority Level = 2 */
  void __ISR(_ADC_VECTOR, ipl2) _ADC_Handler(void)
  {

    // clear the interrupt flag
    mAD1ClearIntFlag();

    // the results of the conversions are available in Pot
    offset = 8 * ((~ReadActiveBufferADC10() & 0x01)); // determine which buffer is idle and create an offset
    AD1CON1SET=_AD1CON1_SAMP_MASK;
    Pot = ReadADC10(0); // read the result of channel 0 conversion from the idle buffer

    // -- display the results --
    sprintf(str, "Potentiometer = %i\n", Pot);
    DBPRINTF(str);
    db_puts(str, 30);
    DelayMs (500);
   }
