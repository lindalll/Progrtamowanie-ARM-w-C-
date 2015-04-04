#define NULL 0

enum CompResult {DIFFERENT, EQUAL};

void CopyString (char pcSource[], char pcDestination[])
{ 
   char cLoopCounter;
   
   for (cLoopCounter = 0; ;cLoopCounter ++)
   {
      pcDestination[cLoopCounter] = pcSource[cLoopCounter];
      if (pcSource[cLoopCounter] == NULL)
      {
         break;
      }         
   }
}

enum CompResult eCompareString(char pcStr1[], char pcStr2[])
{
   char cLoopCounter;
   
   for (cLoopCounter = 0; pcStr1[cLoopCounter] == pcStr2[cLoopCounter]; cLoopCounter ++)
   {
      if(pcStr1[cLoopCounter] == NULL)
      {
         return EQUAL;         
      }
   }
   return DIFFERENT;
}      

void AppendString (char pcSourceStr[], char pcDestinationStr[])
{
   char cLoopCounter;
     
   for(cLoopCounter = 0; pcDestinationStr[cLoopCounter] != NULL; cLoopCounter++){};
   CopyString(pcSourceStr, pcDestinationStr+cLoopCounter);
}

void ReplaceCharactersInString(char pcString[], char cOldChar, char cNewChar)
{
   char cLoopCounter;
   
   for(cLoopCounter = 0; pcString[cLoopCounter] != NULL; cLoopCounter++)
   {
      if(pcString[cLoopCounter] == cOldChar)
      {
         pcString[cLoopCounter] = cNewChar;
      }
   }
}


//   char Source_main[100] = "cos";
//   char Dest_main[100] = "swfasffsdcsdccjnKL Nixuwtquieyuwpqoidnckjcbniosf";
//   
//   AppendString(Source_main, Dest_main);
//   
//   ReplaceCharactersInString(Dest_main, 's', 'X');
