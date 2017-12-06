#include "main.h"

#define SWITCH_DELAY 500000
#define P8 GPIO_Pin_8
#define P9 GPIO_Pin_9
#define P10 GPIO_Pin_10
int main(void)
{
  GPIO_InitTypeDef  GPIO_InitStructure;

  /* Enable peripheral clock for GPIOD port */
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
  
  /* Init leds */
  GPIO_InitStructure.GPIO_Pin = P8|P9|P10;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_Init(GPIOA, &GPIO_InitStructure);

  //Timer
  TIM_TimeBaseInitTypeDef tim;
  tim.TIM_Period=100000-1;
  tim.TIM_Prescaler=84-1;
  tim.TIM_ClockDivision=0;
  tim.TIM_CounterMode=TIM_CounterMode_Up;
  TIM_TimeBaseInit(TIM2,&tim);
  TIM_Cmd(TIM2,ENABLE);

    GPIOA->BSRRL = P9|P10;
  int ok=0;
  while (1)
  {
          if(TIM_GetCounter(TIM2)==0)
          {
             if(ok==0)
	       GPIOA->BSRRH = P8;
	       // for (i=0; i < SWITCH_DELAY; i++)
	     if(ok==1)
	       GPIOA->BSRRL =P8;
             ok=(ok+1)%2;
          }
	 // for (i=0; i < SWITCH_DELAY; i++)
  }
}
