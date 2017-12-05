
/*
 *  Copyright:  DFRobot
 *  name:       DFPlayer_Mini_Mp3 sample code
 *  Author:     lisper <lisper.li@dfrobot.com>
 *  Date:       2014-05-30
 *  Description:    sample code for DFPlayer Mini, this code is test on Uno
 *          note: mp3 file must put into mp3 folder in your tf card
 */
 
 #include <math.h>
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
  /*
    for(int i=0 ; i <10;i++)
    {
       mp3_play(i);
    }
    */
    SayNumber((int)random(120,500));
    delay(2000) ;
  /*
    PlayVoice(1,10) ;
   // delay(4000) ;
    PlayVoice(2,10) ;
  //  delay(4000) ;
    PlayVoice(3,10) ;
   // delay(4000) ;
  Serial.println("768") ;
   // while(1) ;
  delay(1000) ;
  */
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


