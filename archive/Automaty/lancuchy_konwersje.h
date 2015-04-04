#include <LPC21xx.H>

enum CompResult {DIFFERENT, EQUAL};
//enum Result {OK, ERROR};

void UIntToHexStr(unsigned int uiValue, char []);
enum Result eHexStringToUInt(char [], unsigned int *pciValue);
void AppendUIntToString(unsigned int uiValue, char []);

//void UIntToHexStr(unsigned int uiValue, char pcStr[]);
//enum Result eHexStringToUInt(char pcStr[], unsigned int *pciValue);
//void AppendUIntToString(unsigned int uiValue, char pcDestinatonStr[]);

void CopyString (char [], char []);
enum CompResult eCompareString(char [], char []);
void AppendString (char [], char []);
void ReplaceCharactersInString(char [], char, char);
