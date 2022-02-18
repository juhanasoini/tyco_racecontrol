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
  //BT.println( "laptime%" + (String)lapTime + "%" + (String)lane + "%" + (String)lapCount );
}
void PrintLaps(byte laneNr, bool override = false)
{
  LapData lap;
  Lane lane = Lane1;
  if(laneNr == 2)
    lane = Lane2;

  byte iStart = lane.GetLapCount()-1;
  Serial.println(PrintLoopCounter);
  if(override)
  {
    iStart = PrintLoopCounter;
  }
  if(iStart < 2)
  {
    iStart = 2;
    PrintLoopCounter = 2;
  }
  if(iStart>9)
  {
    iStart = 9;
    PrintLoopCounter = 9;    
  }

    Serial.println(iStart);
  byte iStop = iStart-2;
  byte lapCount = lane.GetLapCount();
  byte row = 3;
  for(int i=iStart;i>=iStop;i--)
  {
    lap = lane.GetLap(i);
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
      row--;      
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
  
  String row1 = "___ _   _ ____ ____ ";
  String row2 = " |   \\_/  |    |  |";
  String row3 = " |    |   |___ |__| ";
  
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
  if(PrintLoopCounter >= MaxLapCount)
    PrintLoopCounter = 0;
}
