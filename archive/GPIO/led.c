#include <LPC21xx.H>
#include "led.h"

#define LED0_bm 0x00010000
#define LED1_bm 0x00020000
#define LED2_bm 0x00040000
#define LED3_bm 0x00080000

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
