#include "Settings.h"

Settings::Settings(byte mode, byte lapCount)
{
  Mode = mode;
  LapCount = lapCount;
  CurrentOptionLevel = 0;
  CurrentOptionSubLevel = -1;
}

void Settings::SetOptions()
{
  OptionsCategories[0] = "Mode";
  OptionsCategories[1] = "Lap count";
  
  Options[0][0] = {1, "Time trial"};
  Options[0][1] = {2, "Race"};
  
  Options[1][0] = {2, "2"};
  Options[1][1] = {3, "3"};
  Options[1][2] = {4, "4"};
}
struct OptionSelectionModel Settings::Browse(char dir)
{
  OptionSelectionModel ret;
  Option opt;
  Serial.println(dir);
  
  //byte catLength = (sizeof(Options[0]) / sizeof(Options[0][0]));
  byte catLength = 2;
  //byte listLength = (sizeof(Options[CurrentOptionLevel]) / sizeof(Options[CurrentOptionLevel][0]));
  byte listLength = 2;
  switch(dir)
  {
    case '0':
      CurrentOptionLevel = 0;
      CurrentOptionSubLevel = -1;
      break;
    case 'R':
      if(CurrentOptionSubLevel < 0)
        CurrentOptionSubLevel = 0;
      else
      {
        if(CurrentOptionLevel == 0)
        {
          Mode = Options[CurrentOptionLevel][CurrentOptionSubLevel].Value;
        }
        else if(CurrentOptionLevel == 1)
        {
          LapCount = Options[CurrentOptionLevel][CurrentOptionSubLevel].Value;
        }
      }
      break;
    case 'D':
      if(CurrentOptionSubLevel > -1)
      {
        CurrentOptionSubLevel++;
        if(CurrentOptionSubLevel >= listLength)
          CurrentOptionSubLevel = 0;        
      }
      else
      {
        CurrentOptionLevel++;
        if(CurrentOptionLevel >= catLength)
          CurrentOptionLevel = 0;
      }
      break;
    case 'U':
      if(CurrentOptionSubLevel > -1)
      {
        CurrentOptionSubLevel--;
        if(CurrentOptionSubLevel < 0)
          CurrentOptionSubLevel = listLength-1;
      }
      else
      {
        CurrentOptionLevel--;
        if(CurrentOptionLevel < 0)
          CurrentOptionLevel = catLength-1;
      }
      break;
  }

  Serial.println(CurrentOptionLevel);
  Serial.println(CurrentOptionSubLevel);
  ret.Category = OptionsCategories[CurrentOptionLevel];
  if(CurrentOptionSubLevel > -1)
  {
    ret.Opt = Options[CurrentOptionLevel][CurrentOptionSubLevel];
  }
  else
    ret.Opt = {-1, ""};
  return ret;
}
byte Settings::GetMode()
{
  return Mode;
}
String Settings::GetModeLabel()
{
  byte catLength = (sizeof(Options[0]) / sizeof(Options[0][0]));
  String modeLabel = "";
  //Serial.println(Mode);
  for( byte x = 0; x < catLength; x++)
  {
    if(Options[0][x].Value == Mode)
      modeLabel = Options[0][x].Label;
  }
  return modeLabel;
}
void Settings::SetMode(byte mode)
{
  Mode = mode;
}

byte Settings::GetLapCount()
{
  return LapCount;
}
