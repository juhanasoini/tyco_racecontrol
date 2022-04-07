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
  TimingStarted = false;
  for(int i=0;i<10;i++)
  {
    LapArr[i] = {0,0};
  }
  struct LapData LapArr[10];
}

struct LapData Lane::RegisterLap(unsigned long raceDuration)
{
  LapData ret;
  if(TimingStarted == false)
  {
    TimingStarted = true;
    return ret;
  }
  unsigned long lapTime = ( raceDuration - LastLapTimeTaken );
  LastLapTimeTaken = raceDuration;
  LapCount++;
  if(LapCount > 10)
  {
    int j =0;
    for(int i=0; i<9;i++)
    {
      j = i+1;
      LapArr[i] = LapArr[j];
    }
  }
  byte lapPos = LapCount-1;
  ret.LapNr = LapCount;
  ret.LapTime = lapTime;
  if(LapCount > 10)
    lapPos = 9;
  LapArr[lapPos] = ret;
  
  return ret;
}

byte Lane::GetLapCount()
{
  return LapCount;
}

struct LapData Lane::GetLap(byte num)
{
  byte maxim = MaxLapCount - 1;
  if(num<0)
    num = maxim;
  else if(num>maxim)
    num = 0;
  return LapArr[num];
}
