#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "RTClib.h"
int coi =3;
int nut=6;
RTC_DS1307 rtc;
LiquidCrystal_I2C lcd(0x27, 16,2);
char daysOfTheWeek[7][12] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
void setup () 
{
  pinMode(nut,INPUT_PULLUP);
  Serial.begin(9600);
  lcd.begin ();  // initialize the lcd 
  lcd.backlight();//To Power ON the back light
  if (! rtc.begin()) 
  {
    lcd.print("Couldn't find RTC");
    while (1);
  }
if (! rtc.isrunning()) 
  {
    lcd.print("RTC is NOT running!");
  }
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));//auto update from computer time
    //rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));// to set the time manually 
}
void loop () 
{
  int gt=digitalRead(nut);
  if(gt==0){
      Serial.print("Da nhan");
      delay(1000);
       rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));// to set the time manually 
    }
    DateTime now = rtc.now();
    lcd.setCursor(0, 1);
    lcd.print("TIME");
    lcd.print(" ");
    lcd.print(now.hour());
    lcd.print(':');
    lcd.print(now.minute());
    lcd.print(':');
    lcd.print(now.second());
lcd.print("  ");

    lcd.setCursor(0, 0);
    lcd.print("DATE");
    lcd.print(" ");
    //lcd.print(daysOfTheWeek[now.dayOfTheWeek()]);
    //lcd.print(" ");
    lcd.print(now.day());
    lcd.print('/');
    lcd.print(now.month());
    lcd.print('/');
    lcd.print(now.year());
    lcd.print("  ");  
    
    
}
