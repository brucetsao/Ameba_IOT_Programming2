#include <SoftwareSerial.h>
#define rxPin  0
#define txPin  1


SoftwareSerial mySerial (rxPin, txPin);

char msg[32];
String LEDstr = String("AT95=(30,30,10,200)");

void Write_AT_Command(char *string){
  mySerial.print(string);
  while (mySerial.read() != 'E') {}
  delay(2);
}

void StringWrite_AT_Command(String  string){
  mySerial.print(string);
  while (mySerial.read() != 'E') {}
  delay(2);
}


void setup() {
  
  mySerial.begin(115200);
  //mySerial.println("ATd1=()"); // show data in the display memory
  //mySerial.println("ATd0=()"); // clear display
  //mySerial.print(Write_AT_Command("AT95=(30,30,10,200)"));
  mySerial.print("Hello World");
  delay(3000) ;
}




void Write_5X7_Character( int line, int column, char Char) {
  mySerial.write(0x80);
  mySerial.write(line);
  mySerial.write(column);
  mySerial.print(Char);
  while (mySerial.read() !='E') {} 
  delay(2);                                                                                                                                                
 }

void loop() {
  //LEDstr.toCharArray(msg,sizeof(msg));
  //Write_AT_Command(msg);
  mySerial.println("at95=(20,20,10,1)");
//  StringWrite_AT_Command(String("AT95=(15,15,10,1)"));
  //mySerial.println("Yo yo yo");
  delay(1000);
  //Write_5X7_Character(1,1,)
}
