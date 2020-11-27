/*
 * File:   config.h
 * Author: Syed Tahmid Mahbub
 * Modifed by: Bruce Land 
 * Created on October 10, 2014
 * Mod: 24Sept2015
 */

#ifndef CONFIG_H
#define	CONFIG_H
#define _SUPPRESS_PLIB_WARNING 1
#include <plib.h>
// serial stuff
#include <stdio.h>

// Protothreads configure

// IF use_vref_debug IS defined, pin 25 is Vref output
//#define use_vref_debug

// IF use_uart_serial IS defined, pin 21 and pin 22 are used by the uart
//#define use_uart_serial
#define BAUDRATE 115200 // must match PC terminal emulator setting

/////////////////////////////////
// set up clock parameters
// system cpu clock
#define sys_clock 40000000

// sys_clock/FPBDIV
#define pb_clock sys_clock // divide by one in this case

#endif	/* CONFIG_H */

