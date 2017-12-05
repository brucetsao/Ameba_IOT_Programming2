//#include <SoftwareSerial.h>
#include "DHT.h"

#define DHTPIN 7     // what digital pin we're connected to
#define DHTTYPE DHT11   // DHT 11
//#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
//#define DHTTYPE DHT21   // DHT 21 (AM2301)
float h,t,f ;


DHT dht(DHTPIN, DHTTYPE);

unsigned char btchar ;

void setup() {
  // put your setup code here, to run once:
      dht.begin();
    Serial.begin(9600) ;
    Serial.println("\n\n BT Start with DHT22 v1") ;
    
}

void loop() {
  // put your main code here, to run repeatedly:
      
      if (Serial.available() > 0)
          {
             Serial.println("Some coming") ; 
            btchar = Serial.read() ;
              if (btchar == '@')
                   {
                         btchar = Serial.read() ; 
                          if (btchar == 'H')
                              {
                                  Serial.println("Send Humidity") ; 
                                    SendHumidity() ;
                                    return ;
                              }
                          if (btchar == 'T')
                              {
                                     Serial.println("Send Temperature") ; 
                                    SendTemperature() ;
                                    return ;
                              }
         
                   }
          }
     
}
void SendHumidity()
{
      Serial.println("Now send Humidity") ;
      h = dht.readHumidity();
      Serial.print("#H") ;
      Serial.print(String((int)h) );
         Serial.print("*") ;   
}

void SendTemperature()
{
        Serial.println("Now send Temperature") ;
        t = dht.readTemperature();
      Serial.print("#T") ;
      Serial.print(String((int)t) );
      Serial.print("*") ;
}


