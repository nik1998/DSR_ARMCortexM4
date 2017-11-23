#include "main.h"

#define SWITCH_DELAY 500000


int main(void)
{
  GPIO_InitTypeDef  GPIO_InitStructure;

  /* Enable peripheral clock for GPIOD port */
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);

  /* Init leds */
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_Init(GPIOD, &GPIO_InitStructure);

  while (1)
  {
	  int i;

	  /* Switch LED on */
	  GPIOD->BSRRL = GPIO_Pin_12;
	  for (i=0; i < SWITCH_DELAY; i++)
	  {
	    /* empty cycle */
	  }

	  /* Switch LED off */
	  GPIOD->BSRRH =GPIO_Pin_12;
	  for (i=0; i < SWITCH_DELAY; i++)
	  {
	    /* empty cycle */
	  }
  }
}
