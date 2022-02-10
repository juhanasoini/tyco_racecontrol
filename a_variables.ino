bool debug = true;

const byte LANE_ONE_INTERRUPT_PIN = 2;
const byte LANE_TWO_INTERRUPT_PIN = 3;

byte CurrentMode;//0 =Settings, 1 = Time trial, 2 = Normal race, 3 = Normal race with countdown

byte TimeTrialLane;
byte RaceLapCount = 3;

volatile bool LaneOneLapCheck = false;
volatile long LaneOneLapResetTime;
long LaneOneLastLapTime;
byte LaneOneLapCounter;
long LaneOneLapArr[3];

volatile bool LaneTwoLapCheck = false;
volatile long LaneTwoLapResetTime;
long LaneTwoLastLapTime;
byte LaneTwoLapCounter;
long LaneTwoLapArr[3];

long RaceStartTime;
long RaceEndTime;
long RaceDuration;
bool TimingStarted;
bool RaceEnded;
byte WinnerLane;
