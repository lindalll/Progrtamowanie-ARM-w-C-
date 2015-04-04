#include <LPC21xx.H>
#include "servo.h"
#include "led.h"
#include "timer_interrupts.h"

enum ServoState {CALLIB, IDDLE, INPROGRES};
enum ServoState eServoState;

struct Servo
{
	 enum ServoState eState;
	 unsigned int uiCurrentPosition;
	 unsigned int uiDesiredPosition;
};

struct Servo sServo;

///**********************************************/
void DetectorInit(void)
{
	 IO0DIR &= ~(DETECTOR_bm);
}
///**********************************************/
enum DetectorStan eReadDetector()
{
   if (0 == (IO0PIN & DETECTOR_bm))
	 {
      return INACTIVE;
	 }
	 else
	 {
	    return ACTIVE;
   }
}
///**********************************************/
void Servo_Init(unsigned int uiServoFrequency)
{
   eServoState = CALLIB;
	 Led_Init();
	 Timer1Interrupts_Init(uiServoFrequency, &Automat);
}
///**********************************************/
void Servo_Callib(void)
{
   eServoState = CALLIB;
}
///**********************************************/
void Automat(void){
   switch (eServoState)
	 {
	    case CALLIB:
			   if (ACTIVE == eReadDetector())
				 {
				    eServoState = IDDLE;
					  sServo.uiCurrentPosition = 0;
					  sServo.uiDesiredPosition = 0;
				 }
				 else
				 {
				    eServoState = CALLIB;
				    Led_StepLeft();
				 }
				 break;
				
			case IDDLE:
			   if (sServo.uiCurrentPosition == sServo.uiDesiredPosition)
				 {
		        eServoState = IDDLE;
				 }
				 else
				 {
				    eServoState = INPROGRES;
				 }
				 break;
			
			case INPROGRES:
				 if ((sServo.uiCurrentPosition < sServo.uiDesiredPosition))
				 {
				    Led_StepLeft();
					  sServo.uiCurrentPosition = sServo.uiCurrentPosition + 1;
				 }
				 else if ((sServo.uiCurrentPosition > sServo.uiDesiredPosition))
				 {
				    Led_StepRight();
					  sServo.uiCurrentPosition = sServo.uiCurrentPosition - 1;
				 }
				
				if (sServo.uiCurrentPosition == sServo.uiDesiredPosition)
				{
					 eServoState = IDDLE;
				}
				else
				{
					 eServoState = INPROGRES;
				}
		}
	}
///**********************************************/
void Servo_GoTo(unsigned int uiPosition)
	{
		sServo.uiDesiredPosition = uiPosition;
	}
///**********************************************/
