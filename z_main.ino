void setup() {
  Serial.begin(9600);
  Reset();

  pinMode(LANE_ONE_INTERRUPT_PIN, INPUT_PULLUP);  
  pinMode(LANE_TWO_INTERRUPT_PIN, INPUT_PULLUP);
  
  attachInterrupt(digitalPinToInterrupt(LANE_ONE_INTERRUPT_PIN), LaneOneLapInterrupt, RISING);
  attachInterrupt(digitalPinToInterrupt(LANE_TWO_INTERRUPT_PIN), LaneTwoLapInterrupt, RISING);
  CurrentMode = 2;
}

void loop() {
//  if(LaneOneLapResetTime <= millis())
//    LaneOneLapCheck = false;
//  if(LaneTwoLapResetTime <= millis())
//    LaneTwoLapCheck = false;
  //catch keypad here

  
  switch(CurrentMode)
  {
    case 0:
      break;
    case 1:
    case 2:
      HandleRace();
    case 3:
      //Settings
      break;
    default:
      break; 
      
    
  }

}
