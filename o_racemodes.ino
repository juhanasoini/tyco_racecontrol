
void HandleRace()
{
  if(LaneOneLapCheck)
  {
    LaneOneLapCheck = false;
    if(TycoSettings.ReverseLanes())
      RegisterLap(2);
    else
      RegisterLap(1);
  }
  if(LaneTwoLapCheck)
  {
    LaneTwoLapCheck = false;
    if(TycoSettings.ReverseLanes())
      RegisterLap(1);
    else
      RegisterLap(2);
  }

  if(TimingStarted)
  {
    RaceDuration = millis() - RaceStartTime;
    PrintElapsedTime(RaceDuration);  
  }
  if(TimingStarted && !RaceFinished){
  }
  else if(RaceFinished)
  {
    LoopLaps();
  }
}
void HandleTimeTrial()
{
  if(LaneOneLapCheck && (TimeTrialLane == 1 || TimeTrialLane == 0))
  {
    LaneOneLapCheck = false;
    if(TycoSettings.ReverseLanes())
      RegisterLap(2);
    else
      RegisterLap(1);
  }
  if(LaneTwoLapCheck && (TimeTrialLane == 2 || TimeTrialLane == 0))
  {
    LaneTwoLapCheck = false;
    if(TycoSettings.ReverseLanes())
      RegisterLap(1);
    else
      RegisterLap(2);
  }
  if(TimingStarted)
  {
    RaceDuration = millis() - RaceStartTime;
    PrintElapsedTime(RaceDuration);  
  }
}
