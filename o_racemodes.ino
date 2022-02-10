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
//  if(!TimingStarted || RaceEnded){
  if(!TimingStarted){
    return;
  }
  RaceDuration = millis() - RaceStartTime;

  PrintElapsedTime(RaceDuration);
}
