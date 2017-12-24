#ifndef __LEDS_AND_BUTTON_H_2
#define __LEDS_AND_BUTTON_H__
#define HSE_VALUE 8000000
#include "stm32f4xx.h"
#define HSE_VALUE  8000000
#define PLL_M 8
void ChangePulse(int delta);
void Timm();
void InitLeds(int Pins, int PinSource);
#endif


