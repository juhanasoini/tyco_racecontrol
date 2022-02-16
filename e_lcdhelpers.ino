#include "Lane.h"


void WipeRow( byte RowNum)
{
  for( byte x = 0; x < 20; x++ )
  {
    Lcd.setCursor( x, RowNum );
    Lcd.print(" ");
  }
}
void LCDPrintRow(String text, byte LCDRowNum = 1, byte LCDRowPosition = 0)
{
  WipeRow(LCDRowNum);
  Lcd.setCursor( LCDRowPosition, LCDRowNum );
  Lcd.print( text );
}

byte CenterText( String text )
{
  byte textLength = text.length();
  int pos = textLength / 2;
  return 10-pos;
}

void ScrollRow(String text, bool continuous = true)
{
  if(millis() < NextScrollLoop)
    return;
  int textLength = text.length();
  textLength += 1;
  if(continuous == false)
    textLength += 19;

  Lcd.setCursor( ScrollLoopCounter, 3 );
  Lcd.print( text );
  
  NextScrollLoop = millis() + 1000;
  ScrollLoopCounter--;
  if(abs(ScrollLoopCounter) == textLength)
    ScrollLoopCounter = textLength;
}
