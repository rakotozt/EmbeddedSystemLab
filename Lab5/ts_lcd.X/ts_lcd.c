/* 
 * File:  uart1.c
 * Author: Tafita Rakoto & Chiko Dhire 
 *
 * Created on September 28, 2020
 * This module implements uart functions
 * 
 */
#include "uart1.h"
#include <plib.h

uint8_t ts_lcd_get_ts(uint16_t *x, uint16_t *y);

void ts_lcd_init();