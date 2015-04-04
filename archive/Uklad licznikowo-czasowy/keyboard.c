#include <LPC21xx.H>
#include "keyboard.h"

#define Butt1_bm 0x00001000
#define Butt2_bm 0x00002000
#define Butt3_bm 0x00004000
#define Butt4_bm 0x00008000

void ButtonInit(void)
{
	IO0DIR &= ~(Butt1_bm | Butt2_bm | Butt3_bm | Butt4_bm);
}

enum KeyboardState eKeyboard_Read()
{
	if (0 == (IO0PIN & Butt1_bm)) {
		return BUTTON_1;
	}
	if (0 == (IO0PIN & Butt2_bm)) {
		return BUTTON_2;
	}
	if (0 == (IO0PIN & Butt3_bm)) {
		return BUTTON_3;
	}
	if (0 == (IO0PIN & Butt4_bm)) {
		return BUTTON_4;
	}
	else {
		return RELASED;
	}
}
