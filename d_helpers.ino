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

bool StartTiming(byte lane)
{
  if(TimingStarted || RaceFinished)
    return false;

  BTPrint("start");

  WipeRow(0);
  WipeRow(1);
  WipeRow(2);
  WipeRow(3);

  TimingStarted = true;
  RaceStartTime = millis();
  
  LaneOneLapResetTime = RaceStartTime + 3000;
  LaneTwoLapResetTime = RaceStartTime + 3000;

  PrintElapsedTime(0);
  
  if(IsTimeTrial() && TimeTrialLane == 0)
  {
    TimeTrialLane = lane;
    if(lane == 1)
      Lcd.setCursor(0,0);
    else
      Lcd.setCursor(19,0);
    Lcd.print(lane);
  }
 
  return true;
}
