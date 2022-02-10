long numberOfMillis( long Millis )
{
  int MILLIS_PER_SEC = 1000;
  return ( Millis % MILLIS_PER_SEC );
}

long numberOfSeconds( long Millis )
{
  int MILLIS_PER_SEC = 1000;
  return ( ( Millis / MILLIS_PER_SEC ) % 60 );
}
long numberOfMinutes( long Millis ) 
{
  int MILLIS_PER_SEC = 1000;
  long MILLIS_PER_MIN = 60000;
  long minutes = ( ( ( Millis / MILLIS_PER_MIN) % MILLIS_PER_SEC ) % 60 );
  return minutes;
}
long numberOfHours( long Millis ) 
{
  long MILLIS_PER_MIN = 60000;
  long MILLIS_PER_HOUR = 3600000;
  return (( Millis / MILLIS_PER_HOUR) % MILLIS_PER_MIN);
}
String formatTime( long Millis )
{
  int milliss = numberOfMillis( Millis );
  int seconds = numberOfSeconds( Millis );
  int minutes = numberOfMinutes( Millis );
  //int hours = numberOfHours( Millis );

  String value;
  value = getDigits( (String)minutes, 2 )+":";
  value.concat( getDigits( (String)seconds, 2 ) );
  value+= ".";
  value.concat( getDigits( (String)milliss, 3 ) );
  return value;
}

String getDigits( String value, byte digits )
{
  byte valLength = value.length();
  if( valLength < digits )
  {
    for( int x = valLength; x < digits; x++)
    {
      value = "0"+value;
    }
  }
 return value;
}
