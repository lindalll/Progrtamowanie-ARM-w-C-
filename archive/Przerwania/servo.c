#include <LPC21xx.H>
#include "servo.h"

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
