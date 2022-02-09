

void RegisterLap(byte lane = 0)
{
  long lapTime;
  int lapCount = 0;
  if(!RaceStarted && IsRaceMode(CurrentMode))
  {
    RaceStarted = true;
    RaceStartTime = millis();
    LaneOneLastLapTime = RaceStartTime;
    LaneTwoLastLapTime = RaceStartTime;
    return;
  }
  else if(IsTimeTrial(CurrentMode) && TimeTrialLane == 0)
  {
    TimeTrialLane = lane;
    RaceStartTime = millis();
    return;
  }
  
  if (lane == 1)
  {
    lapTime = ( RaceDuration - LaneOneLastLapTime );
    LaneOneLapArr[LaneOneLapCounter] = lapTime;
    LaneOneLastLapTime = RaceDuration;
    LaneOneLapCounter++;
    lapCount = LaneOneLapCounter;
  }
  else if (lane == 2)
  {
    lapTime = ( RaceDuration - LaneTwoLastLapTime );
    LaneTwoLapArr[LaneOneLapCounter] = lapTime;
    LaneTwoLastLapTime = RaceDuration;
    LaneTwoLapCounter++;
    lapCount = LaneTwoLapCounter;
  }
Serial.println(lapTime);
Serial.println(lane);
Serial.println(lapCount);
  //PrintLap( lapCount, lapTime, lane, 3 );
  //BT.println( "laptime%" + (String)lapTime + "%" + (String)lane + "%" + (String)lapCount );
//  updateStatistics(lane, lapTime);
//
//  if ( !RaceEnded && lapCount == RaceLapCount && winnerSet == false )
//  {
//    winnerSet = true;
//    lcd.setCursor(1, 3);
//    lcd.print( "Winner on lane #" + (String)lane );
//    BT.println( "winner%" + (String)lane );
//  }
}

void LaneOneLapInterrupt(){
  if(!LaneOneLapCheck)
  {
    Serial.println(F("Lane 1"));
    RegisterLap(1);
    LaneOneLapCheck = true;
    LaneOneLapResetTime = millis() + 3000;
  }
}
void LaneTwoLapInterrupt(){
  if(!LaneTwoLapCheck)
  {
    Serial.println(F("Lane 2"));
    RegisterLap(2);
    LaneTwoLapCheck = true;
    LaneTwoLapResetTime = millis() + 3000;
  }
}
