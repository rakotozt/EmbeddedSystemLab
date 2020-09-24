/* 
 * File:   porta_out.h
 * Author: rakotozt & dhire 
 *
 * Created on September 2, 2020
 */
#ifndef PORTB_OUT_H
#define PORTB_OUT_H
#include <inttypes.h>    

extern void portb_out_init();
extern void portb_out_write(uint16_t val);
#endif