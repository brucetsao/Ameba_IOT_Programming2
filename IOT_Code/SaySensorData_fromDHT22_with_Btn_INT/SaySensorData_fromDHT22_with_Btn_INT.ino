#include <Wire.h>   // I2C must use
#include <LiquidCrystal_I2C.h>    //lcm 1602/2004 use

#include <SoftwareSerial.h>
#include <DFPlayer_Mini_Mp3.h>

#include "DHT.h"

#define DHTPIN 7     // what digital pin we're connected to
//#define DHTTYPE DHT11   // DHT 11
#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
//#define DHTTYPE DHT21   // DHT 21 (AM2301)
float h,t,f ;


DHT dht(DHTPIN, DHTTYPE);

unsigned char btchar ;
SoftwareSerial mySerial(8,9); // RX, TX
const byte interruptPin = 3;
boolean SayFlag = false ;
// LCM1602 I2C LCD
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  // Set the LCD I2C address

void setup() {
  // put your setup code here, to run once:
      dht.begin();
    lcd.begin(20,4);     //begin(column,row)            // initialize the lcd 
    lcd.backlight();
      
    mySerial.begin(9600) ;
    Serial.begin(9600) ;
    Serial.println("MP3 Test for DHT Sensor ") ;
    mp3_set_serial (mySerial);      //set Serial for DFPlayer-mini mp3 module 
    delay(1);                     // delay 1ms to set volume
    mp3_set_volume (30);          // value 0~30

   attachInterrupt(interruptPin, IntHandler, FALLING);
}

void loop() 
{
        GetDHTData() ;
       PrintSensorData2LCD() ;
        
     if (SayFlag)
       SayIt() ;
 
   //  SayTemperature() ;
    // SayHumidity() ;

  delay(1000) ;
}

void GetDHTData()
{
  h = dht.readHumidity();
  // Read temperature as Celsius (the default)
   t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  f = dht.readTemperature(true);
}

void PrintSensorData2LCD()
{
    lcd.clear() ;
    lcd.setCursor ( 0, 0 );        // go to home  setCursor ( column_number, row_number )
    lcd.print("Temperature:");  
    lcd.print(t);  
    lcd.setCursor ( 0, 1 );        // go to the next line setCursor ( column_number, row_number )
   lcd.print ("Humidity:");
    lcd.print(h);  
}
void SayHumidity()
{
      Serial.println("Now Say Humidity") ;
      PlayVoice(11,35) ;
      SayNumber((int)h);
}
void SayTemperature()
{
        Serial.println("Now send Temperature") ;
      PlayVoice(10,35) ;
      SayNumber((int)t);
}

 void PlayVoice(int no, int waiting) 
 {
         // Serial.print(no) ;
            mp3_play(no);
        delay(waiting*100) ;  
 }
 
 void PlayNumber(int no) 
 {
            mp3_play(no);
        delay(700) ;  
 }
void SayNumber(unsigned int num)
{
    int ii ;
      String saystr = String(num) ;
              Serial.print("@") ;

      for (int i = 0 ; i <  saystr.length() ; i++)
        {
              ii = (int)saystr.substring(i,i+1).toInt();
              Serial.print(ii) ;
              PlayNumber(ii) ;
        }
              Serial.print("#\n\n") ;

}

void IntHandler()
  {
      noInterrupts() ;
      SayFlag = true ;
  }



void SayIt() {

      SayTemperature() ;
    SayHumidity() ;
      SayFlag = false ;
  interrupts() ;

}

