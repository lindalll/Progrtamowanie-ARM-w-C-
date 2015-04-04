#include <LPC21xx.H>

#define LED0_bm 0x1
#define LED1_bm 0x2
#define LED2_bm 0x4
#define LED3_bm 0x8
#define Button1_bm 0x01
#define Button2_bm 0x02
#define Button3_bm 0x04
#define Button4_bm 0x08

unsigned int uiLedCounter;

void Led_Init()
{
	IO1DIR |= (LED0_bm | LED1_bm | LED2_bm | LED3_bm);
	IO1SET |= (LED0_bm << 16);
}

void LedOn(unsigned int ucLedIndeks)
{
	IO1CLR = 0x001f0000;
	IO1SET = LED0_bm << (ucLedIndeks + 16);
}

void Delay_ms(int iTimeDelayMs)
{
	int iLoopCounter, iCounterMs;
	
	for (iCounterMs = 0; iCounterMs < iTimeDelayMs; iCounterMs ++)
	{
		for (iLoopCounter = 0; iLoopCounter < 7500; iLoopCounter ++) {}
	}
}

void StepLeft(void)
{
	uiLedCounter = (uiLedCounter + 1) % 4;
	LedOn(uiLedCounter);
}

void StepRight()
{
	uiLedCounter = (uiLedCounter - 1) % 4;
	LedOn(uiLedCounter);
}

enum Direction {LEFT, RIGHT};

void Led_Step(enum Direction eDirection)
{
	if (eDirection == LEFT)
	{
		StepLeft();
	}
	else
	{
		StepRight();
	}
}

//------------------------------1.24---------------------------------------
enum eKeyboard_Read {RELASED, BUTTON_1, BUTTON_2, BUTTON_3, BUTTON_4};
enum eKeyboard_Read KeyboardState;

enum eKeyboard_Read ReadButton()
{
	if (0 == (IO0PIN & Button1_bm)) {
		return BUTTON_1;
	}
	if (0 == (IO0PIN & Button2_bm)) {
		return BUTTON_2;
	}
	if (0 == (IO0PIN & Button3_bm)) {
		return BUTTON_3;
	}
	if (0 == (IO0PIN & Button4_bm)) {
		return BUTTON_4;
	}
	else {
		return RELASED;
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

int main()
{
	enum eKeyboard_Read ReadButton();	
	void Led_Step(enum Direction eDirection);
	void LedOn(unsigned int ucLedIndeks);
	void StepLeft(void);
	void StepRight(void);
	void Led_StepLeft(void);
	void Led_StepRight(void);
	
	while(1)
	{
		switch (ReadButton())
		{
			case BUTTON_1:
				Led_StepRight();
				break;
			case BUTTON_2:
				Led_StepLeft();
				break;
		}		
		Delay_ms(100);
	}
}

////------------------------------1.23---------------------------------------
//enum eKeyboard_Read {RELASED, BUTTON_1, BUTTON_2, BUTTON_3, BUTTON_4};
//enum eKeyboard_Read KeyboardState;

//enum eKeyboard_Read ReadButton(){
//	if (0 == (IO0PIN & Button1_bm)) {
//		return BUTTON_1;
//	}
//	if (0 == (IO0PIN & Button2_bm)) {
//		return BUTTON_2;
//	}
//	if (0 == (IO0PIN & Button3_bm)) {
//		return BUTTON_3;
//	}
//	if (0 == (IO0PIN & Button4_bm)) {
//		return BUTTON_4;
//	}
//	else {
//		return RELASED;
//	}
//}

//int main()
//{
//	enum eKeyboard_Read ReadButton();	
//	void Led_Step(enum Direction eDirection);
//	void LedOn(unsigned int ucLedIndeks);
//	void StepLeft(void);
//	void StepRight(void);

//	while(1)
//	{
//		switch (ReadButton())
//		{
//			case BUTTON_1:
//				Led_Step(RIGHT);
//				break;
//			case BUTTON_2:
//				Led_Step(LEFT);
//				break;
//		}		
//		Delay_ms(100);
//	}
//}

////------------------------------1.21 i 1.22--------------------------------
//int main()
//{
//	void Led_Step(enum Direction eDirection);
//	void LedOn(unsigned int ucLedIndeks);
//	void StepLeft(void);
//	void StepRight(void);

//	char cLoopCounter;
//	
//	while(1)
//	{
//		for (cLoopCounter = 0; cLoopCounter < 9; cLoopCounter ++ )
//		{
//			Led_Step(LEFT);
//			Delay_ms(100);
//		}
//		
//		for (cLoopCounter = 0; cLoopCounter < 9; cLoopCounter ++ )
//		{
//			Led_Step(RIGHT);
//			Delay_ms(100);
//		}
//	}
//}

////------------------------------1.20---------------------------------------
//int main()
//{
//	void LedOn(unsigned int ucLedIndeks);
//	void StepLeft(void);
//	void StepRight();
//	
//	Led_Init();
//	
//	while(1)
//	{
//		Delay_ms(250);
//		IO1CLR = (LED0_bm << 16);
//		
//		StepRight();
//		Delay_ms(250);
//		IO1CLR = (LED3_bm << 16);
//		
//		StepRight();
//		Delay_ms(250);
//		IO1CLR = (LED2_bm << 16);
//		
//		StepRight();
//		Delay_ms(250);
//		IO1CLR = (LED1_bm << 16);
//		
//		StepRight();
//	}
//}

////------------------------------1.19---------------------------------------
//int main()
//{
//	void LedOn(unsigned int ucLedIndeks);
//	void StepLeft(void);
//	
//	Led_Init();
//	
//	while(1)
//	{
//		Delay_ms(250);
//		IO1CLR = (LED0_bm << 16);
//		
//		StepLeft();
//		Delay_ms(250);
//		IO1CLR = (LED1_bm << 16);
//		
//		StepLeft();
//		Delay_ms(250);
//		IO1CLR = (LED2_bm << 16);
//		
//		StepLeft();
//		Delay_ms(250);
//		IO1CLR = (LED3_bm << 16);
//		
//		StepLeft();
//	}
//}

////------------------------------1.18-------------------------------------

//enum eKeyboard_Read {RELASED, BUTTON_1, BUTTON_2, BUTTON_3, BUTTON_4};
//enum eKeyboard_Read KeyboardState;

//enum eKeyboard_Read ReadButton(){
//	if (0 == (IO0PIN & Button1_bm)) {
//		return BUTTON_1;
//	}
//	if (0 == (IO0PIN & Button2_bm)) {
//		return BUTTON_2;
//	}
//	if (0 == (IO0PIN & Button3_bm)) {
//		return BUTTON_3;
//	}
//	if (0 == (IO0PIN & Button4_bm)) {
//		return BUTTON_4;
//	}
//	else {
//		return RELASED;
//	}
//}

//int main() {
//	
//enum eKeyboard_Read ReadButton();
//void LedOn(unsigned char ucLedIndeks);	
//	
//IO1DIR = 0x000f0000;
//	
//	while(1) {
//		switch (ReadButton()) {
//			case RELASED:
//				LedOn(4);
//				break;
//			case BUTTON_1:
//				LedOn(0);
//				break;
//			case BUTTON_2:
//				LedOn(1);
//				break;
//			case BUTTON_3:
//				LedOn(2);
//				break;
//			case BUTTON_4:
//				LedOn(3);
//				break;
//		}
//	}
//}
	
//------------------------------1.16 i 1.17---------------------------------
//void ButtonInit(void){
//	IO0DIR = 0x00000000;
//	IO1DIR |= (LED0_bm | LED1_bm | LED2_bm | LED3_bm ) << 16;
//}
//	
//enum ButtonState {RELASED, PRESSED}; 
//enum ButtonState eButton;
//	
//enum ButtonState ReadButton(){
//		if (!(IO0PIN & 0x10)){
//			return PRESSED;
//		}
//		else {
//			return RELASED;
//		}
//	}
//	
//	int main() {
//		
//		void ButtonInit(void);
//		enum ButtonState ReadButton();
//		void LedOn(unsigned char  ucLedIndeks);
//		
//		ButtonInit();
//		
//		while (1) {
//			LedOn(ReadButton());
//		}
//	}
			
//------------------------------1.15--------------------------
//	char ReadButton(){
//		if (!(IO0PIN & 0x10)){
//			return 1;
//		}
//		else {
//			return 0;
//		}
//	}

//	int main() {
//		
//		char ReadButton();
//		void LedOn(unsigned char  ucLedIndeks);
//		
//		IO0DIR = 0x00000000;
//		IO1DIR |= (LED0_bm | LED1_bm | LED2_bm | LED3_bm ) << 16;
//		
//		while (1){
//			LedOn(ReadButton());
//		}
//		}
//
//
////-------------------------1.14-----------------------------
//void Led_Init()
//{
//	IO1DIR |= (LED0_bm | LED1_bm | LED2_bm | LED3_bm);
//}

//int main()
//{
//	void Delay_ms(int iTimeDelayMs);
//	void Led_Init(void);
//	void LedOn(unsigned char ucLedIndeks);
//	
//	Led_Init();
//		
//	while (1) 
//	{
//		Delay_ms(250);
//		LedOn(1);
//		
//		Delay_ms(250);
//		LedOn(2);
//		
//		Delay_ms(250);
//		LedOn(3);
//		
//		Delay_ms(250);
//		LedOn(2);
//		
//		Delay_ms(250);
//		LedOn(1);
//		
//		Delay_ms(250);
//		LedOn(0);
//		
//	}
//}
//-------------------------1.13-----------------------------
//void LedOn(unsigned char ucLedIndeks)
//{
//	IO1CLR = 0x000f0000;
//	IO1SET = LED0_bm << (ucLedIndeks + 16);
//}

//void Led_Init()
//{
//	IO1DIR = LED0_bm | LED1_bm | LED2_bm | LED3_bm;
//	IO1SET = LED0_bm;	
//}

//int main()
//{
//	void Delay_ms(int iTimeDelayMs);
//	void Led_Init(void);
//	void LedOn(unsigned char ucLedIndeks);
//	
//	Led_Init();
//		
//	while (1) 
//	{
//		Delay_ms(250);
//		LedOn(1);
//		
//		Delay_ms(250);
//		LedOn(2);
//		
//		Delay_ms(250);
//		LedOn(3);
//		
//		Delay_ms(250);
//		LedOn(2);
//		
//		Delay_ms(250);
//		LedOn(1);
//		
//		Delay_ms(250);
//		LedOn(0);
//		
//	}
//}

////-------------------------1.12-----------------------------
//void Led_Init()
//{
//	IO1DIR = LED0_bm | LED1_bm | LED2_bm | LED3_bm;
//	IO1SET = LED0_bm;	
//}

//int main()
//{
//	void Delay_ms(int iTimeDelayMs);
//	void Led_Init(void);
//	
//	Led_Init();
//		
//	while (1) 
//	{
//		Delay_ms(250);
//		IO1CLR = LED0_bm;
//		
//		IO1SET = LED1_bm;
//		Delay_ms(250);
//		IO1CLR = LED1_bm;
//		
//		IO1SET = LED2_bm;
//		Delay_ms(250);
//		IO1CLR = LED2_bm;
//		
//		IO1SET = LED3_bm;
//		Delay_ms(250);
//		IO1CLR = LED3_bm;
//		
//		IO1SET = LED2_bm;
//		Delay_ms(250);
//		IO1CLR = LED2_bm;
//		
//		IO1SET = LED1_bm;
//		Delay_ms(250);
//		IO1CLR = LED1_bm;
//		IO1SET = LED0_bm;
//	}
//}

////-------------------------1.11-----------------------------
//int main()
//{
//	void Delay_ms(int iTimeDelayMs);
//	
//	IO1DIR = LED0_bm | LED1_bm | LED2_bm | LED3_bm;	
//		
//	while (1) 
//	{
//		IO1SET = LED0_bm;
//		Delay_ms(250);
//		IO1CLR = LED0_bm;
//		
//		IO1SET = LED1_bm;
//		Delay_ms(250);
//		IO1CLR = LED1_bm;
//		
//		IO1SET = LED2_bm;
//		Delay_ms(250);
//		IO1CLR = LED2_bm;
//		
//		IO1SET = LED3_bm;
//		Delay_ms(250);
//		IO1CLR = LED3_bm;
//		
//		IO1SET = LED2_bm;
//		Delay_ms(250);
//		IO1CLR = LED2_bm;
//		
//		IO1SET = LED1_bm;
//		Delay_ms(250);
//		IO1CLR = LED1_bm;
//	}

//}

////-------------------------1.10-----------------------------
//int main()
//{
//	
//	IO1DIR = LED0_bm | LED1_bm | LED2_bm | LED3_bm;	
//	
//	IO1SET = LED0_bm;
//	IO1SET = LED1_bm;
//	IO1SET = LED2_bm;
//	IO1SET = LED3_bm;	
//	
//	while (1) {}

//}

////-------------------------1.9-----------------------------
//#define LED0_bm 0x00010000
//#define LED3_bm 0x00080000
//
//int main()
//{
//	void Delay_ms(int iTimeDelayMs);
//	
//	IO1DIR = LED3_bm;	
//	
//	while (1) 
//	{
//		IO1SET = LED3_bm;
//		Delay_ms(50);
//		
//		IO1CLR = LED3_bm;		
//		Delay_ms(50);
//	}
//}

////-------------------------1.8-----------------------------
//#define LED0_bm 0x00010000
//
//int main()
//{
//	void Delay_ms(int iTimeDelayMs);
//	
//	IO1DIR = LED0_bm;	
//	
//	while (1) 
//	{
//		IO1SET = LED0_bm;
//		Delay_ms(50);
//		
//		IO1CLR = LED0_bm;		
//		Delay_ms(50);
//	}
//}

////-------------------------1.7-----------------------------
//
//int main()
//{
//	void Delay_ms(int iTimeDelayMs);
//	
//	IO1DIR = 0x00010000;	
//	
//	while (1) 
//	{
//		IO1SET = 0x00010000;
//		Delay_ms(50);
//		
//		IO1CLR = 0x00010000;		
//		Delay_ms(50);
//	}
//}

////-------------------------1.6-----------------------------
//
//int main()
//{
//	void Delay_ms(int iTimeDelayMs);
//	
//	IO1DIR = 0x00010000;	
//	
//	while (1) 
//	{
//		IO1SET = 0x00010000;
//		Delay_ms(1000);
//		
//		IO1CLR = 0x00010000;		
//		Delay_ms(1000);
//	}
//}

////-------------------------1.5-----------------------------
//
//int main()
//{
//	void Delay_ms(int iTimeDelayMs);
//	
//	IO1DIR = 0x00010000;	
//	
//	while (1) 
//	{
//		Delay_ms(17);
//		IO1SET = 0x00010000;
//		
//		Delay_ms(17);
//		IO1CLR = 0x00010000;		
//	}
//}

////-------------------------1.4-----------------------------
//void Delay_ms(void)
//{
//	int iLoopCounter;
//	
//	for (iLoopCounter = 0; iLoopCounter < 7500000; iLoopCounter ++) {}
//}

//int main()
//{
//	void Delay_ms(void);
//	
//	IO1DIR = 0x00010000;	
//	
//	while (1) 
//	{
//		Delay_ms();
//		IO1SET = 0x00010000;
//		
//		Delay_ms();
//		IO1CLR = 0x00010000;		
//	}
//}

////-------------------------1.3-----------------------------
//void Delay_ms(void)
//{
//	int iLoopCounter;
//	
//	for (iLoopCounter = 0; iLoopCounter < 1000; iLoopCounter ++) {}
//}

//int main()
//{
//	void Delay_ms(void);
//	
//	IO1DIR = 0x00010000;	
//	
//	while (1) 
//	{
//		Delay_ms();
//		IO1SET = 0x00010000;
//		
//		Delay_ms();
//		IO1CLR = 0x00010000;		
//	}
//}

////-------------------------1.2-----------------------------
//int main()
//{
//	while (1) 
//	{
//		IO1DIR = 0x00010000;
//		IO1SET = 0x00010000;
//		IO1CLR = 0x00010000;
//	}		
//}

//-------------------------1.1-----------------------------
//int main()
//{
//	IO1DIR = 0x00010000;
//	IO1SET = 0x00010000;
//	IO1CLR = 0x00010000;
//}
//---------------------------------------------------------