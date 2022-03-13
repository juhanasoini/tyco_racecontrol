boolean HandleButtons()
{
  byte key = KeyPad.getKey();
  if(KeyPad.get_status() != 1)
    return false;

  struct OptionSelectionModel opt = {"", {-1, ""}};
  switch(key)
  {
    case 'A':
      Reset(true);
      break;
    case 'L':
      if(!InSettings())
      {
        Reset(false);
        SettingsMode = true;
        opt = TycoSettings.Browse('0');
      }
      else
        opt = TycoSettings.Browse('L');
      break;
    case 'R':
      if(InSettings())
      {
        opt = TycoSettings.Browse('R');
      }
      break;
    case 'D':
      if(InSettings())
      {
        opt = TycoSettings.Browse('D');
      }
      else if(TimingStarted)
      {
        PrintLoopCounter++;
        PrintLaps(TimeTrialLane);
      }
      break;
    case 'U':
      if(InSettings())
      {
        opt = TycoSettings.Browse('U');
      }
      else if(TimingStarted)
      {
        PrintLoopCounter--;
        PrintLaps(TimeTrialLane);
      }
      break;
  }
  if(InSettings())
  {
    LCDPrintRow("SETTINGS:", 0, 0);
    LCDPrintRow("> "+opt.Category, 1, 1 );
    if(opt.Opt.Label != "")
    {
      LCDPrintRow(">> "+opt.Opt.Label, 2, 0);
      if(opt.Opt.Selected == true)
      {
        Lcd.setCursor(19, 2);
        Lcd.write((byte)1);         
      }
    }      
    else
      WipeRow(2);
  }

  return true;
}
