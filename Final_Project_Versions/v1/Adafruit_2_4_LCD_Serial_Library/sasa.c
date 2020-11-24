/*********************************************************************
 *
 *                  SPI to  AD7303 dual channel 8-bit DAC
 *
 *********************************************************************
 * Bruce Land Cornell University
 * June 2014
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * //DAC control word (specific to AD7303)
    // bit 7 notINT/EXT set to notINT = 0. Use internal Vref
    // bit 6 = 0
    // bit 5 LDAC load and update both channels when set
    // bit 4 PDB = 0 pwer down channel B
    // bit 3 PDA = 0 pwer down channel A
    // bit 2 notA/B = 0 chooses A
    // bit 1 CR1=0  control bits modify load mode
    // bit 0 CR0=1  set to load A from SR
	// The actual commands:
    // command to: Load A from shift register
    DAC_cntl_1 = 0b00000001 ;
    // command to: Load B from SR and and update both outputs
    DAC_cntl_2 = 0b00100100 ;
 *
 * SCK1 is pin 25
 * SDO1 is PPS group 2, map to RPA1 (pin 3)
 * SDI1 is PPS group 2, map to RPB8 (pin 17)
 * SYNC is PortB.0 (pin 4)
 */

#include <stdlib.h>
#include <plib.h>
#include <xc.h> // need for pps

// Configuration Bit settings
// SYSCLK = 40 MHz (8MHz Crystal/ FPLLIDIV * FPLLMUL / FPLLODIV)
// PBCLK = 40 MHz
// Primary Osc w/PLL (XT+,HS+,EC+PLL)
// WDT OFF
// Other options are don't care
//
#pragma config FNOSC = FRCPLL, POSCMOD = HS, FPLLIDIV = DIV_2, FPLLMUL = MUL_20, FPBDIV = DIV_1, FPLLODIV = DIV_2
#pragma config FWDTEN = OFF
#pragma config FSOSCEN = OFF, JTAGEN = OFF
// core frequency we're running at // peripherals at 40 MHz
#define	SYS_FREQ 40000000

//== Timer 2 interrupt handler ===========================================
// ipl2 means "interrupt priority level 2"
// ASM output is 47 instructions for the ISR
// volatiles for the stuff used in the ISR
volatile unsigned int DAC_value, DAC_value2 ;//ref output
//volatile int CVRCON_setup; // stores the voltage ref config register after it is set up
volatile unsigned int channel0;	// conversion result as read from result buffer
volatile SpiChannel spiChn = SPI_CHANNEL1 ;	// the SPI channel to use
volatile int spiClkDiv = 2 , i;
#define DAC_cntl_1 0x0100 //256 // 0b00000001<<8
#define DAC_cntl_2 0x2400 //9216// 0b00100100<<8 ;

void __ISR(_TIMER_2_VECTOR, ipl2) Timer2Handler(void)
{
    int junk;
    // Fold all of the processing
    // (ISR flag, read ADC, scale ADC, DDS)
    //into the wait-time for the SPI transmit below:

    // clear the interrupt flag
    //mT2ClearIntFlag();

    // read the ADC
    // read the first buffer position
    //channel0 = ReadADC10(0);   // read the result of channel 4 conversion from the idle buffer
    //AcquireADC10(); // not needed if ADC_AUTO_SAMPLING_ON below
    
    // DAC output
    //DAC_value = channel0>>2 ; //10-bit to 8 bit
    //DAC_value2= (DAC_value2+ 1) & 0xff ; // for testing

    // spi write control word | data word
     mPORTBClearBits(BIT_0); // start transaction
     SPI1BUF = DAC_cntl_1 | DAC_value ; // write
     // while the transmit is going on: clear the interrupt flag
     mT2ClearIntFlag();
     // while the transmit is going on: DAC_value = channel0>>2 ;
     DAC_value = channel0>>2 ;
     // check for complete transmit
     while( !SPI1STATbits.SPIRBF);
     junk = SPI1BUF ;   // read the received value (not used by DAC in this example)
     mPORTBSetBits(BIT_0); // end transaction

     mPORTBClearBits(BIT_0); // start transaction
     SPI1BUF = DAC_cntl_2 | DAC_value2 ;
      // while the transmit is going on: do the DDS
     DAC_value2= (DAC_value2+ 1) & 0xff ; // for testing
      // while the transmit is going on: read the ADC
     channel0 = ReadADC10(0);   // read the result of channel 4 conversion from the idle buffer
     while( !SPI1STATbits.SPIRBF);
     junk = SPI1BUF;        // read the received value (not used by DAC in this example)
     mPORTBSetBits(BIT_0); // end transaction
}

// ========================================================================
int	main(void)
{
	
        

	// Configure the device for maximum performance but do not change the PBDIV
	// Given the options, this function will change the flash wait states, RAM
	// wait state and enable prefetch cache but will not change the PBDIV.
	// The PBDIV value is already set via the pragma FPBDIV option above..
	SYSTEMConfig(SYS_FREQ, SYS_CFG_WAIT_STATES | SYS_CFG_PCACHE);

        // the ADC ///////////////////////////////////////
        // configure and enable the ADC
	CloseADC10();	// ensure the ADC is off before setting the configuration

	// define  setup parameters for OpenADC10
	// Turn module on | ouput in integer | trigger mode auto | enable autosample
        // ADC_CLK_AUTO -- Internal counter ends sampling and starts conversion (Auto convert)
        // ADC_AUTO_SAMPLING_ON -- Sampling begins immediately after last conversion completes; SAMP bit is automatically set
        // ADC_AUTO_SAMPLING_OFF -- Sampling begins with AcquireADC10();
        #define PARAM1  ADC_FORMAT_INTG16 | ADC_CLK_AUTO | ADC_AUTO_SAMPLING_ON

	// define setup parameters for OpenADC10
	// ADC ref external  | disable offset test | disable scan mode | do 1 sample | use single buf | alternate mode off
	#define PARAM2  ADC_VREF_AVDD_AVSS | ADC_OFFSET_CAL_DISABLE | ADC_SCAN_OFF | ADC_SAMPLES_PER_INT_1 | ADC_ALT_BUF_OFF | ADC_ALT_INPUT_OFF
        //
	// Define setup parameters for OpenADC10
        // use peripherial bus clock | set sample time | set ADC clock divider
        // ADC_CONV_CLK_Tcy2 means divide CLK_PB by 2 (max speed)
        // ADC_SAMPLE_TIME_5 seems to work with a source resistance < 1kohm
        // At PB clock 30 MHz, divide by two for ADC_CONV_CLK gives 66 nSec
        #define PARAM3 ADC_CONV_CLK_PB | ADC_SAMPLE_TIME_5 | ADC_CONV_CLK_Tcy2 //ADC_SAMPLE_TIME_15| ADC_CONV_CLK_Tcy2

	// define setup parameters for OpenADC10
	// set AN0 and  as analog inputs
	#define PARAM4	ENABLE_AN0_ANA

	// define setup parameters for OpenADC10
	// do not assign channels to scan
	#define PARAM5	SKIP_SCAN_ALL

	// use ground as neg ref for A | use AN0 for input A
	// configure to sample AN4
	SetChanADC10( ADC_CH0_NEG_SAMPLEA_NVREF | ADC_CH0_POS_SAMPLEA_AN0 ); // configure to sample AN0
	OpenADC10( PARAM1, PARAM2, PARAM3, PARAM4, PARAM5 ); // configure ADC using the parameters defined above

	EnableADC10(); // Enable the ADC

        // timer interrupt //////////////////////////
        // Set up timer2 on,  interrupts, internal clock, prescalar 1, toggle rate
        // at 30 MHz PB clock 60 counts is two microsec
        // 400 is 100 ksamples/sec
        // 2000 is 20 ksamp/sec
        OpenTimer2(T2_ON | T2_SOURCE_INT | T2_PS_1_1, 400);

        // set up the timer interrupt with a priority of 2
        ConfigIntTimer2(T2_INT_ON | T2_INT_PRIOR_2);
        mT2ClearIntFlag(); // and clear the interrupt flag

        // SCK1 is pin 25 RB14
        // SDO1 is PPS group 2, map to RPA1 (pin 3)
        // SDI1 is PPS group 2, map to RPB8 (pin 17)
        // sync is driven by B.0
        // specify PPS group, signal, logical pin name
        PPSInput (2, SDI1, RPB8);
        PPSOutput(2, RPA1, SDO1);
        // control sync for DAC
        mPORTBSetPinsDigitalOut(BIT_0 | BIT_1 | BIT_14);
        mPORTBSetBits(BIT_0);
        // divide fpb by 4, configure the I/O ports. Not using SS in this example
        // 16 bit transfer CKP=1 CKE=1
        // possibles SPI_OPEN_CKP_HIGH;   SPI_OPEN_SMP_END;  SPI_OPEN_CKE_REV
        // For any given peripherial, you will need to match these
        SpiChnOpen(spiChn, SPI_OPEN_ON | SPI_OPEN_MODE16 | SPI_OPEN_MSTEN | SPI_OPEN_CKE_REV | SPI_OPEN_CKP_HIGH , spiClkDiv);

        //SPI1CON = 0x8560 ; // SPI on, 16-bit, master, CKE=1, CKP=1
        // The SPI baudrate BR is given by: BR=Fpb/(2*(SPI1BRG+1))
       // SPI1BRG = 0; // Fpb/2

        // setup system wide interrupts  ///
        INTEnableSystemMultiVectoredInt();

	while(1)
	{
           // toggle a bit for ISR perfromance measure
            //mPORTBToggleBits(BIT_1);
 	}

}



