#include <SoftwareSerial.h>


SoftwareSerial mySerial(0, 1); // RX, TX
void setup() {
  // put your setup code here, to run once:
    mySerial.begin(9600) ;
    Serial.begin(9600) ;
    Serial.println("BT Test Start") ;
    
}

void loop() {
  // put your main code here, to run repeatedly:
      if (mySerial.available() > 0)
          {
            Serial.write(mySerial.read() ) ;
          }
       if (Serial.available() > 0)
          {
            mySerial.write(Serial.read() ) ;
          }       
}
