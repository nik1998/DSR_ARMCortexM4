#include "main.h"
#include "libARM/libARM.h"
#define SWITCH_DELAY 500000



int main(void)
{
 InitLeds(GPIO_Pin_8,GPIO_PinSource8);
  TimTim();
  int h=-1;
  int c=0;
  while (1)
  {   
    c++;
    if(c==14)
    {
      c=0;
      h=-h;
    }
    ChangePulse(h*100);
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

