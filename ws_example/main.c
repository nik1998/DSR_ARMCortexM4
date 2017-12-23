#include "main.h"

#define SWITCH_DELAY 500000
#define LED1_PIN GPIO_Pin_12
#define LED2_PIN GPIO_Pin_13
#define LED3_PIN GPIO_Pin_14
#define LED4_PIN GPIO_Pin_15

char co=0;
int main(void)
{
  GPIO_InitTypeDef  GPIO_InitStructure;

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
  //Timer
  TIM_TimeBaseInitTypeDef ttt;
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);
  ttt.TIM_Period=1000000-1;
  ttt.TIM_Prescaler=84-1;
  ttt.TIM_ClockDivision=0;
  ttt.TIM_CounterMode=TIM_CounterMode_Up;
  TIM_TimeBaseInit(TIM2,&ttt);
  TIM_ITConfig(TIM2, TIM_IT_Update,ENABLE);
  TIM_Cmd(TIM2,ENABLE);
  //Timer vector
  NVIC_InitTypeDef nv;
  nv.NVIC_IRQChannel=TIM2_IRQn;
  nv.NVIC_IRQChannelPreemptionPriority=0x00;
  nv.NVIC_IRQChannelSubPriority=0x01;
  nv.NVIC_IRQChannelCmd=ENABLE;
  NVIC_Init(&nv);

 //button
 GPIO_InitTypeDef GPIO_In;
GPIO_In.GPIO_Pin= GPIO_Pin_0;
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
  co=0;
  GPIO_SetBits(GPIOA,GPIO_Pin_10|GPIO_Pin_9|GPIO_Pin_8);
  while (1)
  {    
  }
}
int ok=1;
 int ind=3;
void TIM2_IRQHandler(void)
{
  if(ok==0)
  {
    co++;
  }
  if(co==2)
  {
    co=0;
    ok=1;
  }
  if(TIM_GetITStatus(TIM2,TIM_IT_Update)!=RESET)
  {
    TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
  }
}
void EXTI0_IRQHandler(void)
{
  if(ok==1)
  if(EXTI_GetITStatus(EXTI_Line0)!=RESET)
  {
    ok=0;
     GPIO_SetBits(GPIOA,GPIO_Pin_10|GPIO_Pin_9|GPIO_Pin_8);
      if(ind==1)
    
      {
         GPIO_ResetBits(GPIOA,GPIO_Pin_9);
         ind=2;
      }
      else
            if(ind==2)
            {
              GPIO_ResetBits(GPIOA,GPIO_Pin_10);
              ind=3;
            }
            else
            if(ind==3)
            {
              GPIO_ResetBits(GPIOA,GPIO_Pin_8);
              ind=1;
            }

    EXTI_ClearITPendingBit(EXTI_Line0);
  }
}
