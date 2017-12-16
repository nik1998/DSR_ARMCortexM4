#include "main.h"
#include "libARM/libARM.h"
#define SWITCH_DELAY 500000



int main(void)
{
  GPIO_InitTypeDef  GPIO_InitStructure;

  /* Enable peripheral clock for GPIOD port */
 // RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
 /* RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);
//button interrupt
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);
  SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOE, EXTI_PinSource0);
  SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOE, EXTI_PinSource1);
  //Init Leds 
 GPIO_PinAFConfig(GPIOA,GPIO_PinSource8|GPIO_PinSource9|GPIO_PinSource10,GPIO_AF_TIM1);
  GPIO_InitStructure.GPIO_Pin= GPIO_Pin_8;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_Init(GPIOA, &GPIO_InitStructure);
  //light
  TIM_TimeBaseInitTypeDef ttt;
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1,ENABLE);
  ttt.TIM_Period=100000/60-1;
  ttt.TIM_Prescaler=1680;

  ttt.TIM_ClockDivision=0;
  ttt.TIM_CounterMode=TIM_CounterMode_Up;
  TIM_TimeBaseInit(TIM1,&ttt);
  TIM_CtrlPWMOutputs(TIM1,ENABLE);
  TIM_Cmd(TIM1,ENABLE);

  TIM_OCInitTypeDef aaa;
  aaa.TIM_OCMode=TIM_OCMode_PWM1;
  aaa.TIM_Pulse=800;
  aaa.TIM_OCPolarity=TIM_OCPolarity_High; 
  TIM_OC1Init(TIM1,&aaa);
  TIM_OC1PreloadConfig(TIM1,TIM_OCPreload_Enable);*/


/* //button
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
   eee.EXTI_Trigger=EXTI_Trigger_Falling;
   EXTI_Init(&eee);

  eee.EXTI_Line=EXTI_Line1;
  EXTI_Init(&eee);
   //vector
  NVIC_InitTypeDef nvec;
  nvec.NVIC_IRQChannel=EXTI0_IRQn;
  nvec.NVIC_IRQChannelPreemptionPriority=0x00;
  nvec.NVIC_IRQChannelSubPriority=0x01;
  nvec.NVIC_IRQChannelCmd=ENABLE;
  NVIC_Init(&nvec);

  nvec.NVIC_IRQChannel=EXTI1_IRQn;
  NVIC_Init(&nvec);*/
  InitLeds(0);
  InitTIM1();
  int h=1;
  while (1)
  {    
    ChangePulse(-100);
    for(int i=0;i<1000000;i++);
  }
}  
 int ind=3;

/*void EXTI0_IRQHandler(void)
{
  if(EXTI_GetITStatus(EXTI_Line0)!=RESET)
  {
      if(ind==1)
      {

         ind=2;
      }
      else
            if(ind==2)
            {
              ind=3;
            }
            else
            if(ind==3)
            {
              
              ind=1;
            }
      
    EXTI_ClearITPendingBit(EXTI_Line0);
  }
}
int pulse=100;
void EXTI1_IRQHandler(void)
{
  if(EXTI_GetITStatus(EXTI_Line1)!=RESET)
  {
    pulse+=100;
    TIM_SetCompare1(TIM1,pulse);
    EXTI_ClearITPendingBit(EXTI_Line1);
  }
}*/

