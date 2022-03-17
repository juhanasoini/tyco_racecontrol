#ifndef SETTINGS_H
#define SETTINGS_H

#include <Arduino.h>
struct Option
{
  int Value;
  String Label;
  bool Selected;
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
    byte LaneOrder;
    String OptionsCategories[3] = {"Mode", "Lap count", "Lane order"};
    struct Option Options[3][5] = {
      { {-1, "", false}, {-1, "", false}, {-1, "", false}, {-1, "", false}, {-1, "", false} },
      { {-1, "", false}, {-1, "", false}, {-1, "", false}, {-1, "", false}, {-1, "", false} },
      { {-1, "", false}, {-1, "", false}, {-1, "", false}, {-1, "", false}, {-1, "", false} }
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
    boolean ReverseLanes();

    struct OptionSelectionModel Browse(char dir);
};

#endif
