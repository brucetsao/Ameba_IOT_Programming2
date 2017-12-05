//#include <SoftwareSerial.h>
#include "DHT.h"

#define DHTPIN 7     // what digital pin we're connected to
//#define DHTTYPE DHT11   // DHT 11
#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
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

void loop()
{
  WiFiClient client = server.available();
  readok = false ;
  
  if (client)
  {
    Serial.println("Now Someone Access WebServer");

    Serial.println("new client");
    // an http request ends with a blank line
    boolean currentLineIsBlank = true;
    while (client.connected())
      {
    //    Serial.print("client connected  in while");
   //       Serial.println(millis());
          if (client.available())
          {
            //  Serial.println("something readrable");
            btchar = client.read();
            Serial.print(btchar) ;
            // give the web browser time to receive the data
            if (c == '@')
            {
             if (client.available())
                   {
                        btchar = client.read();
                         Serial.print(btchar) ;
                   

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
         
                   }    // end of client.available()
                  
               }  //  end of c == '@'
             }  


            }   //(c == '@')  judge read starting symbol
                  
          }   //(client.available())  some data incoming
      }  //end  of while (client.connected())


    }   //end of   if (client)


   //    delay(800) ;
  //  free(client);
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


