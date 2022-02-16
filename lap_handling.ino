#include "Lane.h"

void RegisterLap(byte lane = 0)
{
  if(StartTiming(TycoSettings.GetMode(), lane))
    return;

  LapData lapData = {0,0};
  byte lapCount;
  if (lane == 1 && Lane1.GetLapCount() < MaxLapCount)
  {
    lapData = Lane1.RegisterLap(RaceDuration);
    lapCount = Lane1.GetLapCount();
  }
  else if (lane == 2 && Lane2.GetLapCount() < MaxLapCount)
  {
    lapData = Lane2.RegisterLap(RaceDuration);
    lapCount = Lane2.GetLapCount();
  }
  else
    return;
    
  PrintLap( lane, lapData.LapNr, lapData.LapTime);
  
  //BT.println( "laptime%" + (String)lapTime + "%" + (String)lane + "%" + (String)lapCount );

  if ( !RaceFinished && lapCount == MaxLapCount && !IsWinnerSet() )
  {
    WinnerLane = lane;
    RaceFinished = true;
    PrintRow("Winner on lane #" + (String)lane, 3, 1);
    NextPrintLoop = millis() + 2000;
//    BT.println( "winner%" + (String)lane );
  }

  if(Lane1.GetLapCount() == MaxLapCount && Lane2.GetLapCount() == MaxLapCount)
  {
    TimingStarted = false;
  }
}

void LaneOneLapInterrupt(){
  if(LaneOneLapResetTime <= millis())
  {
    Serial.println(F("Lane 1"));
    LaneOneLapCheck = true;
    LaneOneLapResetTime = millis() + 3000;
  }
}
void LaneTwoLapInterrupt(){
  if(LaneTwoLapResetTime <= millis())
  {
    Serial.println(F("Lane 2"));
    LaneTwoLapCheck = true;
    LaneTwoLapResetTime = millis() + 3000;
  }
}
