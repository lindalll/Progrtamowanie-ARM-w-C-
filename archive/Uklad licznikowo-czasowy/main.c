#include <LPC21xx.H>
#include "led.h"
#include "keyboard.h"

#define COUNTER_ENABLE_bm (1 << 0)
#define COUNTER_RESET_bm (1 << 1)
#define RESET_ON_MR0_bm (1 << 1)
#define INTERRUP_ON_MR0_bm (1 << 0)

//--------------------------------------------------------------------
void Delay_ms(int iTimeDelayMs)
{
	 int iLoopCounter, iCounterMs;
	
	 for (iCounterMs = 0; iCounterMs < iTimeDelayMs; iCounterMs ++)
	 {
      for (iLoopCounter = 0; iLoopCounter < 7500; iLoopCounter ++) {}
	 }
}
//--------------------------------------------------------------------
void WaitOnTimer0Match0(void)
{
   T0TCR |= COUNTER_RESET_bm;
   T0TCR &= ~(COUNTER_RESET_bm);
   while (0 == (T0IR & INTERRUP_ON_MR0_bm)) {}
   T0IR |= INTERRUP_ON_MR0_bm;
}
//--------------------------------------------------------------------
void IntTimer0Match0(unsigned int DelayTimer)
{
   T0TCR |= COUNTER_ENABLE_bm;
   T0TCR |= COUNTER_RESET_bm;
   T0TCR &= ~(COUNTER_RESET_bm);
   T0MR0 = (DelayTimer * 15);
   T0MCR = INTERRUP_ON_MR0_bm;
}
//--------------------------------------------------------------------
void InitTimer0(void)
{
   T0TCR |= COUNTER_ENABLE_bm;
}
//--------------------------------------------------------------------
void WaitOnTimer0(unsigned int uiTime)  
{
   T0TCR |= COUNTER_RESET_bm;
   T0TCR &= ~(COUNTER_RESET_bm);
   while (T0TC != (uiTime * 15)) {};
}
//--------------------------------------------------------------------
int main()
{
   InitTimer0();
   Led_Init();  
   
	WaitOnTimer0(1000000);
   Led_StepLeft();
   WaitOnTimer0(1000000);
   Led_StepLeft();
   
   IntTimer0Match0(1000000);
   WaitOnTimer0Match0();
   Led_StepRight();
   WaitOnTimer0Match0();
   Led_StepRight();
   WaitOnTimer0Match0();
   
   IntTimer0Match0(100000);
   
	while(1)
	{
      Led_StepLeft();
      WaitOnTimer0Match0();
	}
}
