#include <Wire.h>   // I2C must use
#include <LiquidCrystal_I2C.h>    //lcm 1602/2004 use



//-------------- dht use
#include "DHT.h"
#define DHTPIN 7     // what digital pin we're connected to


//#define DHTTYPE DHT11   // DHT 11
#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
//#define DHTTYPE DHT21   // DHT 21 (AM2301)

DHT dht(DHTPIN, DHTTYPE);


// LCM1602 I2C LCD
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  // Set the LCD I2C address


void setup()   /*----( SETUP: RUNS ONCE )----*/
{
    Serial.begin(9600);
  Serial.println("DHTxx test!");
    dht.begin();
  lcd.begin(20,4);     //begin(column,row)            // initialize the lcd 
  lcd.backlight();
  
}// END Setup

static int count=0;
void loop()   
{
  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);

 
  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.print(" *C ");
  Serial.print(f);
  Serial.print(" *F\t\n");
//---------------
  lcd.setCursor ( 0, 0 );        // go to home  setCursor ( column_number, row_number )
  lcd.print("Temperature:");  
  lcd.print(t);  
  lcd.setCursor ( 0, 1 );        // go to the next line setCursor ( column_number, row_number )
  lcd.print ("Humidity:");
    lcd.print(h);  
  delay(1000);
} // END Loop

