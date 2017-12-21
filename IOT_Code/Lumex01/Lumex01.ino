#include <SoftwareSerial.h>
#include <String.h>

unsigned char btchar ;
SoftwareSerial mySerial(0,1); // RX, TX
void setup() {
  // put your setup code here, to run once:
    mySerial.begin(115200) ;
   // mySerial.begin(9600) ;
    Serial.begin(9600) ;
    Serial.println("Lumex Test  ") ;
                 mySerial.print("ATd0=()") ;


}

void loop() 
{
  
    for (int i=20; i<60; i=i+10)
      {
            for (int j=10; j<40; j=j+20)
            {
                  String ab= String("AT94=(")+String(i)+","+String(j)+","+String("10,1") +")";
                  Serial.println(ab) ;
                  mySerial.print(ab ) ;
                  delay(100) ;
            }
      }
}

