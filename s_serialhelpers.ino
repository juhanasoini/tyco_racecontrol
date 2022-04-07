void HandleSerialInput()
{
  char incomingChar;
  if( BT.available() > 0 ) 
  {
    incomingChar = BT.read();
    SerialPrint((String)incomingChar);
    switch( incomingChar ) 
    {
      case '1':
        TycoSettings.SetMode(1);
        Reset(false);
        break;
      case '2':
      case '3':
        TycoSettings.SetMode(2);
        Reset(false);
        break;
      case 'R':
        Reset(false);
        break;
    }
  }
}

void SerialPrint(String str)
{
   Serial.println(str);  
}

void BTPrint(String str)
{
  BT.println(str+";");
}
