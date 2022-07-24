#ifndef _VVC_MAIN_H
#define _VVC_MAIN_H

#include <stdint.h>
#include <string.h>
#include "stm32f0xx.h"

// Global defines.
#define LEDEN   ( RCC_AHBENR_GPIOCEN )
#define PoLED   ( GPIOC )
#define PiLED   ( 8 )

uint32_t core_clock_hz;
volatile uint32_t systick;

#endif
