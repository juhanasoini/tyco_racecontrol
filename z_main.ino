void setup() {
  Serial.begin(9600);
  BT.begin(9600);
  Lcd.begin(20, 4);
  
  attachInterrupt(digitalPinToInterrupt(LANE_ONE_INTERRUPT_PIN), LaneOneLapInterrupt, RISING);
  attachInterrupt(digitalPinToInterrupt(LANE_TWO_INTERRUPT_PIN), LaneTwoLapInterrupt, RISING);

  Lcd.createChar(1, checkMark);
  
  TycoSettings.SetOptions();
  PrintTyco();
  Reset(true);
}

void loop() {
  HandleSerialInput();
  HandleButtons();
    
  switch(TycoSettings.GetMode())
  {
    case 0:
      break;
    case 1:
      HandleTimeTrial();
      break;
    case 2:
    case 3:
      HandleRace();
      break;
    default:
      break;
  }
}
