#include <Arduino.h>
#include "Lane.h"
#include "Settings.h"
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <phi_interfaces.h>

LiquidCrystal_I2C Lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

//Key pad settings
byte keypad_type=Analog_keypad;
char mapping[]={'L','U','D','R','A'}; // This is an analog keypad.
byte pins[]={2}; // The pin numbers are analog pin numbers.
int values[]={0, 146, 320, 513, 744}; //These numbers need to increase monotonically.
phi_analog_keypads KeyPad(mapping, pins, values, 1, 5);
// -- Key pad settings


#define LANE_ONE_INTERRUPT_PIN 2
#define LANE_TWO_INTERRUPT_PIN 3
bool debug = false;

bool SettingsMode = false;
byte DefaultMode = 2;
byte MaxLapCount = 3;

Lane Lane1(LANE_ONE_INTERRUPT_PIN, 1, MaxLapCount);
Lane Lane2(LANE_TWO_INTERRUPT_PIN, 2, MaxLapCount);

Settings TycoSettings(DefaultMode, MaxLapCount);

byte TimeTrialLane;

volatile bool LaneOneLapCheck = false;
volatile long LaneOneLapResetTime;

volatile bool LaneTwoLapCheck = false;
volatile long LaneTwoLapResetTime;

unsigned long RaceStartTime;
//unsigned long RaceEndTime;
unsigned long RaceDuration;
unsigned long NextPrintLoop;
unsigned long NextScrollLoop;

byte PrintLoopCounter;
int ScrollLoopCounter;

bool TimingStarted;
bool RaceFinished;
byte WinnerLane;

byte checkMark[8] = {
  0b00001,
  0b00010,
  0b00010,
  0b00010,
  0b10010,
  0b01100,
  0b00100,
  0b00000
};
