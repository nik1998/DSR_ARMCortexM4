#ifndef __LEDS_AND_BUTTON_H
#define __LEDS_AND_BUTTON_H
#define HSE_VALUE 8000000
#include "stm32f4xx.h"

void ChangePulse(int delta);
void InitTim1andPWM();
void InitLeds(int Pins);
#endif


