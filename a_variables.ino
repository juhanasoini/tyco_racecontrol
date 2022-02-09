const byte LANE_ONE_INTERRUPT_PIN = 2;
const byte LANE_TWO_INTERRUPT_PIN = 3;

byte CurrentMode;//0 = Time trial, 1= Normal race, 2 = Normal race with countdown

byte TimeTrialLane;

bool LaneOneLapCheck = false;
long LaneOneLapResetTime;
long LaneOneLastLapTime;
byte LaneOneLapCounter;
long LaneOneLapArr[3];

bool LaneTwoLapCheck = false;
long LaneTwoLapResetTime;
long LaneTwoLastLapTime;
byte LaneTwoLapCounter;
long LaneTwoLapArr[3];

long RaceStartTime;
long RaceEndTime;
long RaceDuration;
bool RaceStarted;
bool RaceEnded;
