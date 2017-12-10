#include "main.h"

#define SWITCH_DELAY 500000
#define LED1_PIN GPIO_Pin_12
#define LED2_PIN GPIO_Pin_13
#define LED3_PIN GPIO_Pin_14
#define LED4_PIN GPIO_Pin_15


int main(void)
{
  GPIO_InitTypeDef  GPIO_InitStructure;

  /* Enable peripheral clock for GPIOD port */
 // RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);
//button interrupt
   RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);
   SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOE,EXTI_PinSource0);

  //Init Leds 
 // GPIO_PinAFConfig(GPIOA,GPIO_PinSource8,GPIO_AF_TIM1);
  GPIO_InitStructure.GPIO_Pin= GPIO_Pin_8|GPIO_Pin_9|GPIO_Pin_10;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_Init(GPIOA, &GPIO_InitStructure);

 //button
 GPIO_InitTypeDef GPIO_In;
GPIO_In.GPIO_Pin= GPIO_Pin_1|GPIO_Pin_0;
  GPIO_In.GPIO_Mode = GPIO_Mode_IN;
  GPIO_In.GPIO_OType = GPIO_OType_PP;
  GPIO_In.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_In.GPIO_PuPd = GPIO_PuPd_UP;
  GPIO_Init(GPIOE, &GPIO_In);
 //interrupt
   EXTI_InitTypeDef eee;
   eee.EXTI_Line=EXTI_Line0;
   eee.EXTI_LineCmd=ENABLE;
   eee.EXTI_Mode=EXTI_Mode_Interrupt;
   eee.EXTI_Trigger=EXTI_Trigger_Rising;
   EXTI_Init(&eee);

   //vector
  NVIC_InitTypeDef nvec;
  nvec.NVIC_IRQChannel=EXTI0_IRQn;
  nvec.NVIC_IRQChannelPreemptionPriority=0x00;
  nvec.NVIC_IRQChannelSubPriority=0x01;
  nvec.NVIC_IRQChannelCmd=ENABLE;
  NVIC_Init(&nvec);

  //int index
 // int ok=1;
  //int c=1665;
  while (1)
  {    
  }
}

 int index=3;
void EXIT0_IRQHandler(void)
{
  if(EXTI_GetITStatus(EXTI_Line0)!=RESET)
  {
     GPIO_SetBits(GPIOA,GPIO_Pin_10|GPIO_Pin_9|GPIO_Pin_8);
      if(index==1)
      {
         GPIO_ResetBits(GPIOA,GPIO_Pin_9);
         index=2;
      }
      else
            if(index==2)
            {
              GPIO_ResetBits(GPIOA,GPIO_Pin_10);
              index=3;
            }
            else
            if(index==3)
            {
              GPIO_ResetBits(GPIOA,GPIO_Pin_8);
              index=1;
            }

    EXTI_ClearITPendingBit(EXTI_Line0);
  }
}
