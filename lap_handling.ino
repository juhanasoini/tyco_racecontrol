#include "Lane.h"

void RegisterLap(byte lane = 0)
{
  if(StartTiming(lane))
    return;

  LapData lapData = {0,0};
  byte lapCount;
  String btMessage = "";
  if (lane == 1 && ( (!IsTimeTrial() && Lane1.GetLapCount() < TycoSettings.GetLapCount()) || IsTimeTrial()))
  {
    lapData = Lane1.RegisterLap(RaceDuration);
    lapCount = Lane1.GetLapCount();
  }
  else if (lane == 2 && ( (!IsTimeTrial() && Lane2.GetLapCount() < TycoSettings.GetLapCount()) || IsTimeTrial()))
  {
    lapData = Lane2.RegisterLap(RaceDuration);
    lapCount = Lane2.GetLapCount();
  }
  else
    return;
    
  PrintLap( lane, lapData.LapNr, lapData.LapTime);
  btMessage += "lap=" + (String)lane + "%" + (String)lapData.LapNr +"%"+(String)lapData.LapTime;
  
  if(IsTimeTrial())
  {
    PrintLaps(lane, true);
  }
  
  int maxLapCount = TycoSettings.GetLapCount();
  if ( !IsTimeTrial() && !RaceFinished && lapCount == maxLapCount && !IsWinnerSet() )
  {
    btMessage += "#winner=" + (String)lane;
    WinnerLane = lane;
    RaceFinished = true;
    PrintRow("Winner on lane #" + (String)lane, 3, 1);
    NextPrintLoop = millis() + 2000;
  }
  
  if(!IsTimeTrial() && Lane1.GetLapCount() == maxLapCount && Lane2.GetLapCount() == maxLapCount)
  {
    if(btMessage != "")
      btMessage += "#";
    btMessage += "stop";
    TimingStarted = false;
  }
  BTPrint(btMessage);
}

void LaneOneLapInterrupt(){
  if(LaneOneLapResetTime <= millis())
  {
    LaneOneLapCheck = true;
    LaneOneLapResetTime = millis() + 3000;
  }
}
void LaneTwoLapInterrupt(){
  if(LaneTwoLapResetTime <= millis())
  {
    LaneTwoLapCheck = true;
    LaneTwoLapResetTime = millis() + 3000;
  }
}
