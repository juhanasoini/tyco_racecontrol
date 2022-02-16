void HandleRace()
{
  if(LaneOneLapCheck)
  {
    LaneOneLapCheck = false;
    RegisterLap(1);
  }
  if(LaneTwoLapCheck)
  {
    LaneTwoLapCheck = false;
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
