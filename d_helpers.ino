bool IsRaceMode(byte mode)
{
  return mode == 2 || mode == 3;
}

bool IsTimeTrial(byte mode)
{
  return mode == 1;
}

bool IsWinnerSet()
{
  return WinnerLane != 0;
}

bool StartTiming(byte mode, byte lane)
{
  if(TimingStarted)
    return false;

  TimingStarted = true;
  RaceStartTime = millis();
  LaneOneLastLapTime = 0;
  LaneTwoLastLapTime = 0;

  PrintElapsedTime(0);
  
  if(IsTimeTrial(mode) && TimeTrialLane == 0)
  {
    TimeTrialLane = lane;
  }
  return true;
}
