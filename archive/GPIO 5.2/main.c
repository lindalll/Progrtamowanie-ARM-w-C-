#include <LPC21xx.H>
#include "led.h"
#include "keyboard.h"
#include "ProgramObowiazkowy.h"

void Delay_ms(int iTimeDelayMs)
{
	int iLoopCounter, iCounterMs;
	
	for (iCounterMs = 0; iCounterMs < iTimeDelayMs; iCounterMs ++)
	{
		for (iLoopCounter = 0; iLoopCounter < 7500; iLoopCounter ++) {}
	}
}

//--------------------------------------------------------------------
int main()
{   
	Led_Init();
	ButtonInit();
	
	while(1)
	{
		switch (eKeyboard_Read())
		{
			case BUTTON_1:
				Led_StepRight();
				break;
			case BUTTON_2:
				Led_StepLeft();
				break;
			case BUTTON_3:
				break;
			case BUTTON_4:
				break;
			case RELASED:
				break;			
		}		
		Delay_ms(100);
	}
}
