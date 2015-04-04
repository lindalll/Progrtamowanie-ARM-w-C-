#include <LPC21xx.H>
#include "led.h"
#include "keyboard.h"
#include "ProgramObowiazkowy.h"
#include "delay.h"

//--------------------------------------------------------------------
int main()
{   
	Led_Init();
	Button_Init();
	
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
