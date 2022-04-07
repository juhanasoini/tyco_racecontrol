#include "Lane.h"
void PrintRow(String text, byte LCDRowNum = 0, byte LCDRowPosition = 0)
{
  if(debug)
  {
    SerialPrint(text);
  }
  else
  {
    LCDPrintRow(text, LCDRowNum, LCDRowPosition); 
  }
}

void PrintElapsedTime(long elapsedTime)
{
  if(elapsedTime % 250 != 0)
    return;

  String text = formatTime( elapsedTime );
  PrintRow(text, 0, 6);  
}

void PrintLap( byte lane, byte lapNum, long lapTime )
{
  if(!IsTimeTrial())
  {
    String text = "";
    text.concat(lane);
    text.concat(": Lap ");
    text.concat(lapNum);
    text.concat(" ");
    text.concat(formatTime( lapTime ));
    PrintRow(text, lane, 0);    
  }
}
void PrintLaps(byte laneNr, bool incr = false)
{
  LapData lap;
  Lane lane = Lane1;
  if(laneNr == 2)
    lane = Lane2;

  byte lapCount = lane.GetLapCount();
  byte maxKey = lapCount -3;
  if(lapCount > 9)
    maxKey = 7;
  else if(lapCount < 4)
    maxKey = 0;

  if(incr == true && PrintLoopCounter < maxKey)
    PrintLoopCounter++;
  
  if(PrintLoopCounter > maxKey)
    PrintLoopCounter = 0;
  else if(PrintLoopCounter < 0 || lapCount < 4)
    PrintLoopCounter = maxKey;

  byte iStart = PrintLoopCounter;
  byte row = 1;
  for(int i=0;i<3;i++)
  {
    lap = lane.GetLap(iStart);
    if(lap.LapTime > 0)
    {
      String text = "";
      text.concat("Lap ");
      text.concat(lap.LapNr);
      text.concat(" ");
      if(lap.LapNr < 10)
        text.concat(" ");
      text.concat(formatTime( lap.LapTime ));
      PrintRow(text, row, 0);
      row++;
      iStart++;
    }
  }
}
void PrintTyco()
{
  if(debug == false)
  {
    Lcd.clear();
  }

  byte backSlash[8] = {
    0b00000,
    0b10000,
    0b01000,
    0b00100,
    0b00010,
    0b00001,
    0b00000,
    0b00000
  };
  
  PrintRow(F( "___ _   _ ____ ____ " ), 0, 0);

  Lcd.createChar(0, backSlash);
  Lcd.setCursor( 0, 1 );
  Lcd.print( F( " |   " ) );
  Lcd.setCursor( 5, 1 );
  Lcd.write((byte)0); 
  Lcd.setCursor( 6, 1 );
  Lcd.print( F( "_/  |    |  |" ) );
  
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
  if(PrintLoopCounter >= TycoSettings.GetLapCount())
    PrintLoopCounter = 0;
}
