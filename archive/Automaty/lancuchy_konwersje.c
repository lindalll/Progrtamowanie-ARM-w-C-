//#include "lancuchy_konwersje.h"
#include <LPC21xx.H>

#define NULL 0
#define BUFFER_bm 0x000F

enum Result {OK, ERROR};

///*------------------------------------------------------------------------------------------------------------------*/
//void UIntToHexStr(unsigned int uiValue, char pcStr[])
//{
//   unsigned char ucTetradaCounter;
//   unsigned int uiTetradaBuffer;
//   
//   pcStr[0] = '0';
//   pcStr[1] = 'x';
//   
//   for (ucTetradaCounter = 2; ucTetradaCounter < 10; ucTetradaCounter ++)
//   {
//      uiTetradaBuffer = (uiValue >> ((ucTetradaCounter - 2) * 4));
//      uiTetradaBuffer = uiTetradaBuffer & BUFFER_bm;
//      
//      if (uiTetradaBuffer < 10)
//      {
//         pcStr[(11 - ucTetradaCounter)] = (uiTetradaBuffer + '0');
//      }
//      else
//      {
//         pcStr[(11 - ucTetradaCounter)] = (uiTetradaBuffer + ('A' - 10));
//      }
//   }
//   pcStr[10] = NULL;
//}
///*------------------------------------------------------------------------------------------------------------------*/
//enum Result eHexStringToUInt(char pcStr[], unsigned int *pciValue)
//{
//   unsigned char ucTetradaCounter;
//   unsigned int uiTetradaBuffer;
//   
//   if (('0' != pcStr[0]) | ('x' != pcStr[1]) | (NULL == pcStr[2]))
//   {
//      return ERROR;
//   }
//   *pciValue = 0;
//   
//   for (ucTetradaCounter = 2; pcStr[ucTetradaCounter] != NULL; ucTetradaCounter ++)
//   {
//      if (ucTetradaCounter == 6)
//      {
//         return ERROR;
//      }
//      
//      *pciValue <<= 4;

//      uiTetradaBuffer = pcStr[ucTetradaCounter];
//      
//      if (uiTetradaBuffer <= '9')
//      {
//         *pciValue |= uiTetradaBuffer - '0';
//      }
//      else
//      {
//         *pciValue |= uiTetradaBuffer - ('A' - 10);
//      }
//   }
//   return OK;
//}
///*------------------------------------------------------------------------------------------------------------------*/
//void AppendUIntToString(unsigned int uiValue, char pcDestinationStr[])  
//{
//   unsigned char ucCharacterCounter;
//     
//   for(ucCharacterCounter = 0; pcDestinationStr[ucCharacterCounter] != NULL; ucCharacterCounter++) {};
//      
//   UIntToHexStr(uiValue, pcDestinationStr + ucCharacterCounter);
//}
///*------------------------------------------------------------------------------------------------------------------*/




////-- Instrukcje sprawdzajace-----------------------------
////
////   char cTablicaWyniku[10];
////   unsigned int uiDana;
////   uiDana = 650000000;
////   UIntToHexStr(uiDana, cTablicaWyniku);  

///*------------------------------------------------------------------------------------------------------------------*/
//void CopyString (char pcSource[], char pcDestination[])
//{ 
//   unsigned char ucCharacterCounter;
//   
//   for (ucCharacterCounter = 0;pcSource[ucCharacterCounter] != NULL ;ucCharacterCounter ++)
//   {
//      pcDestination[ucCharacterCounter] = pcSource[ucCharacterCounter];       
//   }
//}

//enum CompResult eCompareString(char pcStr1[], char pcStr2[])
//{
//   unsigned char ucCharacterCounter;
//   
//   for (ucCharacterCounter = 0; pcStr1[ucCharacterCounter] == pcStr2[ucCharacterCounter]; ucCharacterCounter ++)
//   {
//      if(pcStr1[ucCharacterCounter] == NULL)
//      {
//         return EQUAL;         
//      }
//   }
//   return DIFFERENT;
//}

//void AppendString (char pcSourceStr[], char pcDestinationStr[])
//{
//   unsigned char ucCharacterCounter;
//     
//   for(ucCharacterCounter = 0; pcDestinationStr[ucCharacterCounter] != NULL; ucCharacterCounter++){};
//   CopyString(pcSourceStr, pcDestinationStr + ucCharacterCounter);
//}

//void ReplaceCharactersInString(char pcString[], char cOldChar, char cNewChar)
//{
//   unsigned char ucCharacterCounter;
//   
//   for(ucCharacterCounter = 0; pcString[ucCharacterCounter] != NULL; ucCharacterCounter++)
//   {
//      if(pcString[ucCharacterCounter] == cOldChar)
//      {
//         pcString[ucCharacterCounter] = cNewChar;
//      }
//   }
//}
