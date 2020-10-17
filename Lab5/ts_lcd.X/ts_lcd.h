/* 
 * File:   ts_lcd.h
 * Author: crdhi
 *
 * Created on September 29, 2020, 9:44 AM
 */

#ifndef TS_LCD_H    /* Guard against multiple inclusion */
#define TS_LCD_H


#include <plib.h>
#include "adc_intf.h"
#include "TouchScreen.h"
#include "tft_master.h"
#include "tft_gfx.h"

#define XM AN0
#define YP AN1
#include <xc.h> 
#include <inttypes.h>


uint8_t ts_lcd_get_ts(uint16_t *x, uint16_t *y) ; 

void ts_lcd_init(); 


#endif
