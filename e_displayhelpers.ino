void PrintElapsedTime(long elapsedTime)
{
  if(elapsedTime % 1000 != 0)
    return;
    
  if(debug)
  {
    Serial.println(formatTime( elapsedTime ));
  }
  else
  {
    //WipeRow(1);
    //WipeRow(2);
    //lcd.setCursor( 6, 0 );
    //lcd.print( formatTime( elapsedTime ) );    
  }
}
void PrintLap( byte lapNum, long lapTime, byte LCDRowNum = 1, byte LCDRowPosition = 0 )
{
  String textLap = "Lap ";
  String text = textLap + lapNum + ": ";
  text.concat( formatTime( lapTime ) );
  if(debug)
  {
    Serial.println(text);
  }
  else
  {
//    lcd.setCursor( LCDRowPosition, LCDRowNum );
//    lcd.print( text ); 
  }
}
