#include "main.h"

#define SWITCH_DELAY 500000



int main(void)
{
  GPIO_InitTypeDef  GPIO_InitStructure;
    
 // RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);

GPIO_InitStructure.GPIO_Pin= GPIO_Pin_8 |GPIO_Pin_9|GPIO_Pin_10;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_Init(GPIOA, &GPIO_InitStructure);
 
  //Timer
  TIM_TimeBaseInitTypeDef ttt;
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);
  ttt.TIM_Period=1000000-1;
  ttt.TIM_Prescaler=84-1;
  ttt.TIM_ClockDivision=0;
  ttt.TIM_CounterMode=TIM_CounterMode_Up;
  TIM_TimeBaseInit(TIM2,&ttt);

  TIM_Cmd(TIM2,ENABLE);


 
  int inde=3;
  int cc=0;
  GPIO_SetBits(GPIOA,GPIO_Pin_8|GPIO_Pin_9|GPIO_Pin_10);
  while (1)
  {    

	 

         
          if(TIM_GetCounter(TIM2)==0)
          {
            cc++;
            if(cc%2==1)
            {
            if(inde==1)           
            {
              GPIO_SetBits(GPIOA,GPIO_Pin_8);
              GPIO_ResetBits(GPIOA,GPIO_Pin_9);
              inde=2;
            }
            else
            if(inde==2)
            {
              GPIO_SetBits(GPIOA,GPIO_Pin_9);
              GPIO_ResetBits(GPIOA,GPIO_Pin_10);
              inde=3;
            }
            else
            if(inde==3)
            {
              GPIO_SetBits(GPIOA,GPIO_Pin_10);
              GPIO_ResetBits(GPIOA,GPIO_Pin_8);
              inde=1;
            }
            }
	      //GPIOD->BSRRH = LED1_PIN|LED2_PIN|LED3_PIN|LED4_PIN;
        }
  }
}


