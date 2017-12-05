
#include <Wire.h>   // I2C must use
#include <LiquidCrystal_I2C.h>    //lcm 1602/2004 use

// LCM1602 I2C LCD
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  // Set the LCD I2C address

//LiquidCrystal_I2C lcd(0x38);  // Set the LCD I2C address

//LiquidCrystal_I2C lcd(0x38, BACKLIGHT_PIN, POSITIVE);  // Set the LCD I2C address

void setup()
{
  Serial.begin(9600);

  lcd.begin(16,2);     //begin(column,row)            // initialize the lcd 
  lcd.backlight();

  lcd.setCursor ( 0, 0 );        // go to home  setCursor ( column_number, row_number )
  lcd.print("Hello World!");  
  lcd.setCursor ( 0, 1 );        // go to the next line setCursor ( column_number, row_number )
  lcd.print ("Ameba");
  delay ( 8000 );

  lcd.clear();
  lcd.setCursor( 0, 0 );
  lcd.print("Type to display");
  lcd.setCursor( 0, 1 );
  lcd.print("On SerialMonitor");
}

void loop()
{
  if (Serial.available()>0) {
    delay(100);
    lcd.clear();
    while (Serial.available() > 0) 
    {
      lcd.write(Serial.read());
    }
  }
}
