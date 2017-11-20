/*
 *  Copyright:  DFRobot
 *  name:       DFPlayer_Mini_Mp3 sample code
 *  Author:     lisper <lisper.li@dfrobot.com>
 *  Date:       2014-05-30
 *  Description:    sample code for DFPlayer Mini, this code is test on Uno
 *          note: mp3 file must put into mp3 folder in your tf card
 */
 
 
#include <SoftwareSerial.h>
#include <DFPlayer_Mini_Mp3.h>
 
SoftwareSerial mySerial(8,9); // RX, TX
const byte interruptPin = 3;
boolean SayFlag = false ;
 
void setup () {
    Serial.begin (9600);
    mySerial.begin (9600);
    Serial.println("MP3 Test ") ;
    mp3_set_serial (mySerial);      //set Serial for DFPlayer-mini mp3 module 
    delay(1);                     // delay 1ms to set volume
    mp3_set_volume (30);          // value 0~30

  attachInterrupt(interruptPin, IntHandler, RISING);

 // pinMode(SayIt, INPUT_IRQ_RISE);
 // digitalSetIrqHandler(button, button_handler);
   
}
 
void loop () { 

   // while(1) ;
   if (SayFlag)
       SayIt() ;
  delay(1000) ;
}

 void PlayNumber(int no) 
 {
            mp3_play(no);
        delay(700) ;  
 }
 /*
void button_handler(uint32_t id, uint32_t event) {
  if (ledState == 0) {
    // turn on LED
    ledState = 1;
    digitalWrite(led, ledState);
  } else {
    // turn off LED
    ledState = 0;
    digitalWrite(led, ledState);
  }
}
*/

/*
   mp3_play ();     //start play
   mp3_play (5);    //play "mp3/0005.mp3"
   mp3_next ();     //play next 
   mp3_prev ();     //play previous
   mp3_set_volume (uint16_t volume);    //0~30
   mp3_set_EQ ();   //0~5
   mp3_pause ();
   mp3_stop ();
   void mp3_get_state ();   //send get state command
   void mp3_get_volume (); 
   void mp3_get_u_sum (); 
   void mp3_get_tf_sum (); 
   void mp3_get_flash_sum (); 
   void mp3_get_tf_current (); 
   void mp3_get_u_current (); 
   void mp3_get_flash_current (); 
   void mp3_single_loop (boolean state);    //set single loop 
   void mp3_DAC (boolean state); 
   void mp3_random_play (); 
 */
  void IntHandler()
  {
      noInterrupts() ;
      SayFlag = true ;
  }


 void SayIt() {

      PlayNumber(3) ;
    PlayNumber(8) ;
    PlayNumber(6) ;
  Serial.println("768") ;
      SayFlag = false ;
  interrupts() ;

}
