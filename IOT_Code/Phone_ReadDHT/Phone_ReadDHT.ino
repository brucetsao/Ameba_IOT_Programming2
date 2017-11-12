#include <SoftwareSerial.h>
#include "DHT.h"

#define DHTPIN 7     // what digital pin we're connected to
#define DHTTYPE DHT11   // DHT 11
float h,t,f ;

SoftwareSerial mySerial(0, 1); // RX, TX
DHT dht(DHTPIN, DHTTYPE);

unsigned char btchar ;

void setup() {
  // put your setup code here, to run once:
      dht.begin();
    mySerial.begin(9600) ;
    Serial.begin(9600) ;
    Serial.println("BT Test Start") ;
    
}

void loop() {
  // put your main code here, to run repeatedly:
      
      if (mySerial.available() > 0)
          {
            btchar = mySerial.read() ;
              if (btchar == '@')
                   {
                         btchar = mySerial.read() ; 
                          if (btchar == 'H')
                              {
                                    SendHumidity() ;
                                    return ;
                              }
                          if (btchar == 'T')
                              {
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
      mySerial.print("#H") ;
      mySerial.println(String((int)h) );
      
}

void SendTemperature()
{
        Serial.println("Now send Temperature") ;
        t = dht.readTemperature();
      mySerial.print("#T") ;
      mySerial.println(String((int)t) );
}


