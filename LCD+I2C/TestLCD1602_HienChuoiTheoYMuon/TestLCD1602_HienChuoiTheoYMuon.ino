
/********************************
* name:I2C LCD1602
* function:You should now see your I2C LCD1602 display the flowing characters: "SunFounder" and "hello, world".
********************************/
//Email:support@sunfounder.com
//Website:www.sunfounder.com

/********************************/
// include the library code
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
/**********************************************************/
String array1="Thanh Tu Vlogs"; //the string to print on the LCD
String array2="Xin Chao Cac Ban"; //the string to print on the LCD
int i=25;
String ichuoi;
int tim = 500; //the value of delay time
// initialize the library with the numbers of the interface pins
LiquidCrystal_I2C lcd(0x27,16,2); // set the LCD address to 0x27 for a 16 chars and 2 line display
/*********************************************************/
void setup()
{
  lcd.begin(); //initialize the lcd
  lcd.backlight(); //open the backlight 
}
/*********************************************************/
void loop() 
{
  
  
  //lcd.setCursor(0,1); // set the cursor to column 15, line 1
  
  
  hienthichuoi(0,0,array1);
  hienthiso(14,0,i);
  hienthichuoi(0,1,array2);
  
 // lcd.clear(); //Clears the LCD screen and positions the cursor in the upper-left corner.
 
}
/************************************************************/
void hienthichuoi(int cot, int dong, String chuoi)
{
  lcd.setCursor(cot,dong);
  for(int j=0;j<chuoi.length();j++)
    {
      lcd.print(chuoi[j]);
    } 
}
void hienthiso(int cot, int dong, int so)
{
  String chuoi=String(so);
  lcd.setCursor(cot,dong);
  for(int j=0;j<chuoi.length();j++)
    {
      lcd.print(chuoi[j]);
    } 
}
