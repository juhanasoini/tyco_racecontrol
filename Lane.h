#ifndef LANE_H
#define LANE_H

#include <Arduino.h>
struct LapData 
{
  byte LapNr;
  unsigned long LapTime;
};

class Lane
{
  private:
    bool TimeTrialLane;
    byte Pin;
    byte LaneNr;
    byte LapCount;
    byte MaxLapCount;
    unsigned long LastLapTimeTaken;
    struct LapData LapArr[10];

  public:
    Lane(byte pin, byte laneNr, byte maxLapCount);
    void Reset(byte maxLapCount);
    struct LapData RegisterLap(unsigned long raceDuration);
    byte GetLapCount();
    struct LapData GetLap(byte num);
};
#endif
