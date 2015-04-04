#include <LPC21xx.H>
#include "keyboard.h"
#include "servo.h"

char cLedCounter = 0;

///**********************************************/
int main (){
	unsigned int iMainLoopCtr;
	
	Servo_Init(2000);
	DetectorInit();	
	Button_Init();
	
	while(1){
   if (eKeyboard_Read() == BUTTON_1)
   {
	    Servo_GoTo(0);        
   }
   if (eKeyboard_Read() == BUTTON_2)
   {
	    Servo_GoTo(50); 
   }
   if (eKeyboard_Read() == BUTTON_3)
   {
	    Servo_GoTo(100); 
   }
   if (eKeyboard_Read() == BUTTON_4)
   {
	    Servo_GoTo(150); 
   }

   iMainLoopCtr++;
	}
}
