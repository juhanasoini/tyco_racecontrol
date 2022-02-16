#include "Lane.h"
void PrintRow(String text, byte LCDRowNum = 0, byte LCDRowPosition = 0)
{
  if(debug)
  {
    Serial.println(text);
  }
  else
  {
    LCDPrintRow(text, LCDRowNum, LCDRowPosition); 
  }
}

void PrintElapsedTime(long elapsedTime)
{
  if(elapsedTime % 1000 != 0)
    return;

  String text = formatTime( elapsedTime );
  PrintRow(text, 0, 6);  
}

void PrintLap( byte lane, byte lapNum, long lapTime )
{
  String text = "";
  text.concat(lane);
  text.concat(": Lap ");
  text.concat(lapNum);
  text.concat(" ");
  text.concat(formatTime( lapTime ));
  PrintRow(text, lane, 0);
}
void PrintTyco()
{
  if(debug == false)
  {
    Lcd.clear();
  }
  
  String row1 = "___ _   _ ____ ____ ";
  String row2 = " |   \\_/  |    |  |";
  String row3 = " |    |   |___ |__| ";
  
  PrintRow(F( "___ _   _ ____ ____ " ), 0, 0);
  PrintRow(F( " |   \\_/  |    |  |" ), 1, 0); 
  PrintRow(F( " |    |   |___ |__| " ), 2, 0);
  
  delay(3000);
}

void LoopLaps()
{
  if(millis() < NextPrintLoop)
    return;

  LapData lapData = {0,0};;
  lapData = Lane1.GetLap(PrintLoopCounter);
  if(lapData.LapNr != 0)
    PrintLap( 1, lapData.LapNr, lapData.LapTime);
  lapData = Lane2.GetLap(PrintLoopCounter);
  if(lapData.LapNr != 0)
    PrintLap( 2, lapData.LapNr, lapData.LapTime);

  NextPrintLoop = millis() + 2000;
  PrintLoopCounter++;
  if(PrintLoopCounter >= MaxLapCount)
    PrintLoopCounter = 0;
}
