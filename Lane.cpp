#include "Lane.h"

Lane::Lane(byte pin, byte laneNr, byte maxLapCount) 
{
  LaneNr = laneNr;
  Pin = pin;
  pinMode(pin, INPUT_PULLUP); 
  Reset(maxLapCount);
}

void Lane::Reset(byte maxLapCount)
{
  LapCount = 0;
  LastLapTimeTaken = 0;
  MaxLapCount = maxLapCount;
}

struct LapData Lane::RegisterLap(unsigned long raceDuration)
{
  LapData ret;
  unsigned long lapTime = ( raceDuration - LastLapTimeTaken );
  LastLapTimeTaken = raceDuration;
  LapCount++;

  ret.LapNr = LapCount;
  ret.LapTime = lapTime;
  Serial.println(lapTime);
  LapArr[LapCount-1] = ret;
  
  return ret;
}

byte Lane::GetLapCount()
{
  return LapCount;
}

struct LapData Lane::GetLap(byte num)
{
  byte maxim = MaxLapCount - 1;
  num = num;
  if(num<0)
    num = maxim;
  else if(num>maxim)
    num = 0;
  return LapArr[num];
}
