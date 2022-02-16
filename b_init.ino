void Reset()
{
  RaceDuration = 0;
  RaceStartTime = 0;
  RaceEndTime = 0;
  TimingStarted = false;
  RaceFinished = false;
  SettingsMode = false;
  Lane1.Reset(TycoSettings.GetLapCount());
  Lane2.Reset(TycoSettings.GetLapCount());

  TimeTrialLane = 0;

  LaneOneLapResetTime = 0;
  LaneTwoLapResetTime = 0;

  WinnerLane = 0;
  NextPrintLoop = 0;
  NextScrollLoop = 0;
  PrintLoopCounter = 0;
  ScrollLoopCounter = 0;

  Lcd.clear();
  Lcd.setCursor( CenterText("READY"), 1 );
  Lcd.print( "READY" );
  String str = TycoSettings.GetModeLabel();
  Lcd.setCursor( CenterText(str), 2 );
  Lcd.print( str );
}
