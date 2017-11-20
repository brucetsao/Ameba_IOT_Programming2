/*
 * TimeRTC.pde
 * example code illustrating Time library with Real Time Clock.
 * 
 */

#include <TimeLib.h>
#include <Wire.h>
#include <DS1307RTC.h>  // a basic DS1307 library that returns time as a time_t
//#include <DateTime.h>
//#include <DateTimeStrings.h>

tmElements_t setRTCData ;
void setup()  {
  Serial.begin(9600);
  while (!Serial) ; // wait until Arduino Serial Monitor opens
  setSyncProvider(RTC.get);   // the function to get the time from the RTC
/*
  if(timeStatus()!= timeSet) 
     Serial.println("Unable to sync with the RTC");
  else
     Serial.println("RTC has set the system time");      
//RTC.write(DateTime(__DATE__, __TIME__));

*/
setRTCData.Year = 47;
setRTCData.Month = 11;
setRTCData.Day = 17;
setRTCData.Hour = 23;
setRTCData.Minute = 15;
setRTCData.Second = 0;
RTC.write(setRTCData) ;
//RTC.write(DateTime(__DATE__, __TIME__)) ;
}

void loop()
{

    digitalClockDisplay();
 
  delay(1000);
}

void digitalClockDisplay(){
  // digital clock display of the time
  Serial.print(hour());
  printDigits(minute());
  printDigits(second());
  Serial.print(" ");
  Serial.print(day());
  Serial.print(" ");
  Serial.print(month());
  Serial.print(" ");
  Serial.print(year()); 
  Serial.println(); 
}

void printDigits(int digits){
  // utility function for digital clock display: prints preceding colon and leading 0
  Serial.print(":");
  if(digits < 10)
    Serial.print('0');
  Serial.print(digits);
}

