#include <LPC21xx.H>
#include "led.h"
#include "keyboard.h"
#include "lancuchy_konwersje.h"

#define DELAY_MAIN_LOOP_MS 100
#define AUTOMAT_WAIT_MS 5000
#define DELAY_COUNTER )

enum LedState {LED_STOP, LED_LEFT, LED_RIGHT, LED_WAIT};
enum LedState eLedState = LED_STOP;
unsigned char ucTimeCounter = 0;

//---------------------------Delay-------------------------------------
void Delay_ms(int iTimeDelayMs)
{
	int iLoopCounter, iCounterMs;
	
	for (iCounterMs = 0; iCounterMs < iTimeDelayMs; iCounterMs ++)
	{
		for (iLoopCounter = 0; iLoopCounter < 7500; iLoopCounter ++) {}
	}
}
//---------------------------7----------------------------------------
int main()
{
//   
//   char cTablicaWyniku[10];
//   unsigned int uiDana;
//   uiDana = 6500000;
//   UIntToHexStr(uiDana, cTablicaWyniku); 
   
   //unsigned int uiValue;
  //char xxx[] = "0x2A";
   
   //unsigned int a=0;
   //char tab[10];
   //char tab[]= {"1234123"};
   
   
   
   //eHexStringToUnit ( tab , &a);
   
   
   
//   uiValue = 6500;
   //AppendUIntToString(uiValue, xxx);

	Led_Init();
	Button_Init();

	while(1)
	{
		switch (eLedState)
		{
			case LED_STOP:
            if (BUTTON_3 == eKeyboard_Read())
            {
               eLedState = LED_RIGHT;
            }			
            else if (BUTTON_1 == eKeyboard_Read())
            {
               eLedState = LED_LEFT;
            }
            else
            {
               eLedState = LED_STOP;		
            }               
				break;
			case LED_LEFT:
				if (BUTTON_2 == eKeyboard_Read())
				{
					eLedState = LED_WAIT;
				}
				else
				{
					eLedState = LED_LEFT;
					Led_StepLeft();
				}
				break;
			case LED_RIGHT:
				if (BUTTON_2 == eKeyboard_Read())
				{
					eLedState = LED_WAIT;
				}
				else
				{
					eLedState = LED_RIGHT;
					Led_StepRight();
				}
				break;
			case LED_WAIT:
            if (ucTimeCounter < (AUTOMAT_WAIT_MS/DELAY_MAIN_LOOP_MS))
            {
               eLedState = LED_WAIT;
               ucTimeCounter ++;           
            }
            else
            {
               eLedState = LED_STOP;
               ucTimeCounter = 0;    
            }
            break;
      }
      Delay_ms(DELAY_MAIN_LOOP_MS);
   }
}
////---------------------------6----------------------------------------
//enum LedState {STEP, WAIT};
//enum LedState eLedState = STEP;
//char cLedCounter = 0;

//int main()
//{
//	Led_Init();
//	Button_Init();

//	while(1)
//	{
//		switch (eLedState)
//		{
//			case STEP:
//				if (BUTTON_1 == eKeyboard_Read())
//				{
//					eLedState = WAIT;
//				}
//				else
//				{
//					eLedState = STEP;
//					Led_StepLeft();		
//				}
//				break;
//			case WAIT:
//				if (BUTTON_2 == eKeyboard_Read())
//				{
//					eLedState = STEP;
//				}
//				else
//				{
//					eLedState = WAIT;
//				}
//		}
//		Delay_ms(100);
//	}
//}

////---------------------------5----------------------------------------
//enum LedState {WAIT, STEP, STOP};
//enum LedState eLedState = WAIT;
//char cLedCounter = 0;

//int main()
//{
//	Led_Init();
//	Button_Init();

//	while(1)
//	{
//		switch (eLedState)
//		{
//			case WAIT:
//				if (BUTTON_1 == eKeyboard_Read())
//				{
//					eLedState = STEP;
//				}
//				else
//				{
//					eLedState = WAIT;
//				}
//				break;
//			case STEP:
//				if (3 == cLedCounter)
//				{
//					eLedState = STOP;
//					cLedCounter = 0;
//				}
//				else
//				{
//					Led_StepLeft();
//					cLedCounter ++;
//					eLedState = STEP;
//				}
//				break;
//			case STOP:
//				eLedState = STOP;
//				break;
//		}
//		Delay_ms(100);
//	}
//}
//---------------------------4----------------------------------------
//enum LedState {STATE0, STOP};
//enum LedState eLedState = STATE0;
//char cLedCounter = 0;

//int main()
//{
//	Led_Init();
//	Button_Init();

//	while(1)
//	{
//		switch (eLedState)
//		{
//			case STATE0:
//				if (3 == cLedCounter)
//				{
//					eLedState = STOP;
//					cLedCounter = 0;
//				}
//				else
//				{
//					Led_StepLeft();
//					cLedCounter ++;
//					eLedState = STATE0;
//				}

//				break;
//			case STOP:
//				eLedState = STOP;
//				break;
//		}
//		Delay_ms(100);
//	}
//}


//---------------------------3----------------------------------------
//enum LedState {LED_LEFT, LED_RIGHT};
//enum LedState eLedState = LED_LEFT;
//char cLedCounter = 0;

//int main()
//{
//	Led_Init();
//	Button_Init();

//	while(1)
//	{
//		switch (eLedState)
//		{
//			case LED_LEFT:
//				if (3 == cLedCounter)
//				{
//					eLedState = LED_RIGHT;
//					cLedCounter = 0;
//				}
//				else
//				{
//					eLedState = LED_LEFT;
//					cLedCounter ++;
//					Led_StepLeft();					
//				}
//				break;
//			case LED_RIGHT:
//				if (3 == cLedCounter)
//				{
//					eLedState = LED_LEFT;
//					cLedCounter = 0;
//				}
//				else
//				{
//					eLedState = LED_RIGHT;
//					cLedCounter ++;
//					Led_StepRight();					
//				}
//				break;
//		}
//		Delay_ms(100);
//	}
//}

////---------------------------2----------------------------------------
//enum LedState {STATE0, STATE1, STATE2, STATE3, STATE4, STATE5};
//enum LedState eLedState = STATE0;

//int main()
//{
//	Led_Init();
//	ButtonInit();

//	while(1)
//	{
//		switch (eLedState)
//		{
//			case STATE0:
//				eLedState = STATE1;
//				Led_StepLeft();
//				break;
//			case STATE1:
//				eLedState = STATE2;
//				Led_StepRight();
//				break;
//			case STATE2:
//				eLedState = STATE3;
//				Led_StepRight();
//				break;
//			case STATE3:
//				eLedState = STATE4;
//				Led_StepRight();
//				break;
//			case STATE4:
//				eLedState = STATE5;
//				Led_StepLeft();
//				break;
//			case STATE5:
//				eLedState = STATE0;
//				Led_StepLeft();
//				break;
//		}
//		Delay_ms(100);
//	}
//}
//---------------------------1----------------------------------------
//enum LedState {LED_LEFT, LED_RIGHT};
//enum LedState eLedState = LED_LEFT;
//int main()
//{
//	Led_Init();
//	ButtonInit();

//	while(1)
//	{
//		switch (eLedState)
//		{
//			case LED_LEFT:
//				eLedState = LED_RIGHT;
//				Led_StepRight();
//				break;
//			case LED_RIGHT:
//				eLedState = LED_LEFT;
//				Led_StepLeft();
//				break;
//		}
//		Delay_ms(100);
//	}
//}
