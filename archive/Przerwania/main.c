#include <LPC21xx.H>
#include "led.h"
#include "keyboard.h"
#include "timer_interrupts.h"
#include "servo.h"

#define DELAY_MAIN_LOOP_MS 100
#define AUTOMAT_WAIT_MS 5000

//enum LedState {STEP, WAIT, CALLIB};
//enum LedState eLedState = CALLIB;
enum ServoState {CALLIB, GOLEFT, IDDLE, GORIGHT};
enum ServoState eServoState;

struct Servo
{
	 enum ServoState eState;
	 unsigned int uiCurrentPosition;
	 unsigned int uiDesiredPosition;
};

struct Servo sServo;
char cLedCounter = 0;

///**********************************************/
void Automat(void){
		switch (eServoState)
		{
			case CALLIB:
				if (ACTIVE == eReadDetector())
				{
					 eServoState = IDDLE;
				}
				else
				{
					eServoState = CALLIB;
					Led_StepLeft();
				}
				break;
			case GOLEFT:
				if (BUTTON_2 == eKeyboard_Read())
				{ 
	         eServoState = IDDLE;
				}
				else
				{
					 eServoState = GOLEFT;
				   Led_StepLeft();
				}
				break;
			case IDDLE:
				if (BUTTON_1 == eKeyboard_Read())
				{
				   eServoState = GOLEFT;
				}
				else if (BUTTON_3 == eKeyboard_Read())
				{
			     eServoState = GORIGHT;
				}
				else
				{
					 eServoState = IDDLE;
				}
				break;
			case GORIGHT:
				if (BUTTON_2 == eKeyboard_Read())
				{
           eServoState = IDDLE;
				}
				else
				{
					 eServoState = GORIGHT;
					 Led_StepRight();
				}
		}
	}
///**********************************************/
int main (){
	unsigned int iMainLoopCtr;
	Led_Init();
	Button_Init();
	DetectorInit();
	Timer1Interrupts_Init(2000, &Automat);
	
	while(1){
	 	iMainLoopCtr++;
	}
}
