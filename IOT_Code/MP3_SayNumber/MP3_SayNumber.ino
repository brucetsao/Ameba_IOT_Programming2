#include <SoftwareSerial.h>
#include <DFPlayer_Mini_Mp3.h>
 
SoftwareSerial mySerial(8,9); // RX, TX
void setup () {
    Serial.begin (9600);
    mySerial.begin (9600);
    Serial.println("MP3 Test ") ;
    mp3_set_serial (mySerial);      //set Serial for DFPlayer-mini mp3 module 
    delay(1);                     // delay 1ms to set volume
    mp3_set_volume (30);          // value 0~30
}
 
void loop () { 
     SayNumber((int)random(120,500));
    delay(2000) ;
  
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


