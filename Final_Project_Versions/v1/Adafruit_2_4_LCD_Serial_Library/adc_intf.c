#include "adc_intf.h"
#include <plib.h>
#include <xc.h>


/*  Configure achieves the same as the following register manipulation
    AD1CON1CLR = 0x8000;    // disable ADC before configuration
 
    AD1CON1 = 0x00E0;       // internal counter ends sampling and starts conversion (auto-convert), manual sample
    AD1CON2 = 0;            // AD1CON2<15:13> set voltage reference to pins AVSS/AVDD
    AD1CON3 = 0x0f01;       // TAD = 4*TPB, acquisition time = 15*TAD 
 */

// Configuration constants - see PLIB Manual Ch. 20 for details
#define CONFIG1     ADC_MODULE_OFF | ADC_IDLE_CONTINUE | ADC_FORMAT_INTG16 | \
    ADC_CLK_AUTO | ADC_AUTO_SAMPLING_OFF | ADC_SAMP_OFF
#define CONFIG2     ADC_VREF_AVDD_AVSS | ADC_OFFSET_CAL_DISABLE | \
    ADC_SCAN_OFF | ADC_SAMPLES_PER_INT_1 | ADC_ALT_BUF_OFF | \
    ADC_ALT_INPUT_OFF
// Use Set sample time | ADC internal clock | 
// Use PB clock (default)), 15*Tad, conversion 4 
#define CONFIG3      ADC_SAMPLE_TIME_15 | ADC_CONV_CLK_PB | ADC_CONV_CLK_Tcy
// Do not assign channels to scan
#define CONFIGSCAN  0
#define CONFIGPORT 0

void configureADC(){
    CloseADC10();
    OpenADC10(CONFIG1, CONFIG2, CONFIG3, CONFIGPORT, CONFIGSCAN);
    EnableADC10(); // Enable the ADC
}


int analogRead(char analogPIN){
    SetChanADC10(analogPIN << 16);
    AcquireADC10();
    while( AD1CON1bits.SAMP );      // wait until acquisition is done
    while( ! AD1CON1bits.DONE );    // wait until conversion done
    return ReadADC10(0);
}


int readADC(int an) {
    return analogRead(an);
}