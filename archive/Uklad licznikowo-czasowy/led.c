#include <LPC21xx.H>
#include "led.h"

unsigned int uiLedCounter;
enum Direction {LEFT, RIGHT};

void Led_Init()
{
	IO1DIR |= (LED0_bm | LED1_bm | LED2_bm | LED3_bm);
	IO1SET |= LED0_bm;
}

void LedOn(unsigned int ucLedIndeks)
{
	IO1CLR = (LED0_bm | LED1_bm | LED2_bm | LED3_bm);
	switch (ucLedIndeks)
	{
		case 0:
			IO1SET |= LED0_bm;
			break;
		case 1:
			IO1SET |= LED1_bm;
			break;
		case 2:
			IO1SET |= LED2_bm;
			break;
		case 3:
			IO1SET |= LED3_bm;
	}
}

void Led_Step(enum Direction eDirection)
{
	if (eDirection == LEFT)
	{
		uiLedCounter = (uiLedCounter + 1) % 4;
		LedOn(uiLedCounter);
	}
	else
	{
		uiLedCounter = (uiLedCounter - 1) % 4;
		LedOn(uiLedCounter);
	}
}

void Led_StepLeft(void)
{
	Led_Step(LEFT);
}

void Led_StepRight(void)
{
	Led_Step(RIGHT);
}
