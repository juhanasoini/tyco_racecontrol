boolean HandleButtons()
{
  byte key = KeyPad.getKey();
  if(KeyPad.get_status() != 1)
    return false;
//  if(key != 0)
//  {
//    Serial.println(KeyPad.get_status());
//    Serial.println(key);
//  }
  struct OptionSelectionModel opt = {"", {-1, ""}};
  switch(key)
  {
    case 'A':
      Reset();
      break;
    case 'L':
      if(!InSettings())
      {
        Reset();
        SettingsMode = true;
        opt = TycoSettings.Browse('0');
      }
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
      break;
    case 'U':
      if(InSettings())
      {
        opt = TycoSettings.Browse('U');
      }
      break;
  }
  if(InSettings())
  {
    LCDPrintRow("SETTINGS", 0, CenterText("Settings"));
    LCDPrintRow(opt.Category, 1, CenterText(opt.Category));
    LCDPrintRow(opt.Opt.Label, 2, CenterText(opt.Opt.Label));    
  }
//  byte array_length = getArrayLength( SettingsTexts );
//  byte last_element = array_length - 1;
//  if( key != NO_KEY ) 
//  {
//    //Serial.write( key );
//    
//    if( key == 'A' )
//    {
//      InSettings = false;
//      RaceMode = TextArrayPointer;
//      initialize();
//      return true;
//    }
//
//    if( RaceStarted && !RaceEnded && key == 'L' )
//    {
//      return false;
//    }
//    else if( RaceStarted && !InSettings && ( key == 'U' || key == 'D' ) )
//    {
//      if( key == 'U' )
//      {
//        printLapCounter--;
//        loopOverride = true;
//      }
//      else if( key == 'D' )
//      {
//        printLapCounter++;
//        loopOverride = true;
//      }
//      return true;    
//    }    
//    else if( !InSettings && RaceStarted && key == 'R' && !RaceEnded )
//    {
//      RaceEnded = true;
//      RaceEndTime = millis();
//      return true;
//    }
//    else if( !InSettings && key == 'L' )
//    {
//      TextArrayPointer = RaceMode;
//      lcd.clear();
//      lcd.setCursor(0, 0);
//      lcd.print( F( "Mode:" ) );
//      lcd.setCursor(4, 1);
//      lcd.print( SettingsTexts[TextArrayPointer] );
//      InSettings = true;
//      return true;
//    }
//    else if( InSettings && key == 'L' )
//    {
//      InSettings = false;
//      WipeRow( 0 );
//      WipeRow( 1 );
//      lcd.setCursor( 6, 1);
//      lcd.print( F( "#Ready#" ) );
//      byte pos = centerText( SettingsTexts[RaceMode] );
//      lcd.setCursor(pos, 2);
//      lcd.print( SettingsTexts[RaceMode] );
//      return true;
//    }
//    else if( !InSettings && key != 'L' )
//    {
//      return true;
//    }
//    
//    if( InSettings )
//    {
//      if( key == 'U' )
//      {
//        if( TextArrayPointer == 0 )
//          TextArrayPointer = last_element;
//        else
//          TextArrayPointer--;
//      }
//      
//      if( key == 'D' )
//      {
//        if( TextArrayPointer == last_element )
//          TextArrayPointer = 0;
//        else
//          TextArrayPointer++;
//      }
//
//      WipeRow( 1 );
//      byte pos = centerText( SettingsTexts[TextArrayPointer] );
//      lcd.setCursor( pos, 1);
//      lcd.print( SettingsTexts[TextArrayPointer] );
//      return true;
//      
//    }
//    
//  }
  return true;
}

byte getArrayLength( String* arr )
{
  byte count = 0;
  while( arr[count] != "END" )
  {
    count++;
  }
  return count;
}

//boolean handleSerialInput()
//{
//  byte incomingByte = 0;
//    //Serial.println(BT.available());
//  if( BT.available() ) 
//  {
//    // read the incoming byte:
//    incomingByte = BT.read();
//    switch( incomingByte ) 
//    {
//      case 33: //!
//      case 49: //1
//        //Set racemode 0
//        TextArrayPointer = 0;
//        BT.println( F( "" ) );
//        BT.print( F( "Switch to \"" ) );
//        BT.print( SettingsTexts[TextArrayPointer] );
//        BT.println( F( "\"? Press \"Enter or a\" to confirm!" ) );
//        break;
//      case 34: //"
//      case 50: //2
//        //Set racemode 1
//        TextArrayPointer = 1;
//        BT.println( F( "" ) );
//        BT.print( F( "Switch to \"" ) );
//        BT.print( SettingsTexts[TextArrayPointer] );
//        BT.println( F( "\"? Press \"Enter or a\" to confirm!" ) );
//        break;
//      case 35: //#
//      case 51: //3
//        //Set racemode 2
//        TextArrayPointer = 2;
//        BT.println( F( "" ) );
//        BT.print( F( "Switch to \"" ) );
//        BT.print( SettingsTexts[TextArrayPointer] );
//        BT.println( F( "\"? Press \"Enter or a\" to confirm!" ) );
//        break;
//      case 13: // Enter
//      case 97: // a
//        RaceMode = TextArrayPointer;
//        initialize();
//        break;
//      case 75: // k
//        sendLapTimes();
//        break;
//      case 76: // l = letter Ã¤llÃ¤
//        sendActiveLane();
//        break;
//      case 71: // g
//        sendStatisticsData();
//        break;
//      case 77: // m
//        sendMode();
//        break;
//      case 113: // q
//        resetStatisticsMemory();
//        sendStatisticsData();
//        BT.println( F( "Statistics reset!" ) );
//        break;
//      default:
//        BT.print( F( "Arduino received: " ) );
//        BT.println(incomingByte);
//        Serial.print( F( "Arduino received: " ) );
//        Serial.println(incomingByte);
//        
//      break;
//    }
//
//    Serial.println( incomingByte );
//  }
//  return true;
//}
