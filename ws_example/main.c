#include "main.h"
#include "libARM/libARM.h"

#define SWITCH_DELAY 500000



int main(void)
{
    InitLeds(0x0);
   InitTIM1andPWM();
   int  c=1665;
   int  h=1;
  while (1)
  {    
       c=c-100*h;
       if(c-100<0)
       {
         h=-1;
       }
       if(c+100>1600)
       {
         h=1;
       }
       ChangePulse(100*h);
      // TIM_SetCompare1(TIM1,c);
       for(int i=0;i<500000;i++);
       {
       }
  }
}

 

