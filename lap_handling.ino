

void RegisterLap(byte lane = 0)
{
  if(StartTiming(CurrentMode, lane))
    return;

  long lapTime;
  byte lapCount = 0;
//  Serial.println(RaceDuration);
//  Serial.println(LaneOneLastLapTime);
//  Serial.println(LaneTwoLastLapTime);
//  Serial.println(RaceStartTime);
  if (lane == 1 && LaneOneLapCounter < RaceLapCount)
  {
    lapTime = ( RaceDuration - LaneOneLastLapTime );
    LaneOneLapArr[LaneOneLapCounter] = lapTime;
    LaneOneLastLapTime = RaceDuration;
    LaneOneLapCounter++;
    lapCount = LaneOneLapCounter;
  }
  else if (lane == 2 && LaneTwoLapCounter < RaceLapCount)
  {
    lapTime = ( RaceDuration - LaneTwoLastLapTime );
    LaneTwoLapArr[LaneTwoLapCounter] = lapTime;
    LaneTwoLastLapTime = RaceDuration;
    LaneTwoLapCounter++;
    lapCount = LaneTwoLapCounter;
  }
  else
    return;
    
  PrintLap( lapCount, lapTime, lane, 3 );
  
  //BT.println( "laptime%" + (String)lapTime + "%" + (String)lane + "%" + (String)lapCount );
//  updateStatistics(lane, lapTime);

  if ( !RaceEnded && lapCount == RaceLapCount && !IsWinnerSet() )
  {
    WinnerLane = lane;
    RaceEnded = true;
//    lcd.setCursor(1, 3);
//    lcd.print( "Winner on lane #" + (String)lane );
//    BT.println( "winner%" + (String)lane );
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
