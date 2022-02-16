bool IsRaceMode()
{
  byte mode = TycoSettings.GetMode();
  return mode == 2 || mode == 3;
}

bool IsTimeTrial()
{
  return TycoSettings.GetMode() == 1;
}

bool InSettings()
{
  return SettingsMode == true;
}

bool IsWinnerSet()
{
  return WinnerLane != 0;
}

bool StartTiming(byte mode, byte lane)
{
  if(TimingStarted)
    return false;

  WipeRow(0);
  WipeRow(1);
  WipeRow(2);
  WipeRow(3);

  TimingStarted = true;
  RaceStartTime = millis();

  PrintElapsedTime(0);
  
  if(IsTimeTrial() && TimeTrialLane == 0)
  {
    TimeTrialLane = lane;
  }
  return true;
}
