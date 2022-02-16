#ifndef SETTINGS_H
#define SETTINGS_H

#include <Arduino.h>
struct Option
{
  int Value;
  String Label;
};

struct OptionSelectionModel
{
  String Category;
  struct Option Opt;
};

class Settings
{
  private:
    byte Mode;
    byte LapCount;
    String OptionsCategories[2] = {"Mode", "Lap count"};
    struct Option Options[2][5] = {
      { {-1, ""}, {-1, ""}, {-1, ""}, {-1, ""}, {-1, ""} },
      { {-1, ""}, {-1, ""}, {-1, ""}, {-1, ""}, {-1, ""} }
    };
    int CurrentOptionLevel;
    int CurrentOptionSubLevel;

  public:
    Settings(byte mode, byte lapCount);
    byte GetMode();
    String GetModeLabel();
    void SetMode(byte mode);
    byte GetLapCount();
    void SetLapCount(byte count);
    void SetOptions();

    struct OptionSelectionModel Browse(char dir);
};

#endif
