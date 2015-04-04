#include <LPC21xx.H>

//__irq void Timer0IRQHandler();
void Timer0Interrupts_Init(unsigned int uiPeriod, void (*ptrInterruptFunction)());
void Timer1Interrupts_Init(unsigned int uiPeriod, void (*ptrInterruptFunction)());
