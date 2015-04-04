/*  delay.c  */




void Delay_ms(int iTimeDelayMs)
{
	int iLoopCounter, iCounterMs;
	
	for (iCounterMs = 0; iCounterMs < iTimeDelayMs; iCounterMs ++)
	{
		for (iLoopCounter = 0; iLoopCounter < 7500; iLoopCounter ++) {}
	}
}

