#include <Wire.h>
#include <LiquidCrystal_I2C.h>
//    https://maxpromer.github.io/LCD-Character-Creator/
// Set the LCD address to 0x27 in PCF8574 by NXP and Set to 0x3F in PCF8574A by Ti
LiquidCrystal_I2C lcd(0x27, 16, 2);

byte muiten[] = {
  B00000,
  B00100,
  B01110,
  B11111,
  B00100,
  B00100,
  B00100,
  B00000
};

byte loa[] = {
  B00001,
  B00011,
  B00111,
  B11111,
  B11111,
  B00111,
  B00011,
  B00001
};

byte tim[] = {
  B00000,
  B01010,
  B11111,
  B11111,
  B01110,
  B00100,
  B00000,
  B00000
};

byte tick[] = {
  B00000,
  B00000,
  B00001,
  B00011,
  B10110,
  B11100,
  B01000,
  B00000
};

byte nhietdo[] = {
  B11000,
  B11000,
  B00111,
  B01000,
  B01000,
  B01000,
  B00111,
  B00000
};

byte phantram[] = {
  B11000,
  B11001,
  B00010,
  B00100,
  B01000,
  B10011,
  B00011,
  B00000
};

byte notnhac[] = {
  B00001,
  B00011,
  B00101,
  B01001,
  B01011,
  B11011,
  B11000,
  B00000
};

byte caichuong[] = {
  B00100,
  B01110,
  B01110,
  B01110,
  B01110,
  B11111,
  B00000,
  B00100
};

byte test9[] = {
  B01000,
  B00100,
  B00010,
  B00001,
  B00001,
  B00010,
  B00100,
  B01000
};

void setup() 
{
  lcd.begin();
  lcd.backlight();
  
  lcd.createChar(0, muiten);
  lcd.createChar(1, loa);
  lcd.createChar(2, tim);
  lcd.createChar(3, tick);
  lcd.createChar(4, nhietdo);
  lcd.createChar(5, phantram);
  lcd.createChar(6, notnhac);
  lcd.createChar(7, caichuong);
  lcd.createChar(8, test9);
}

void loop() 
{ 
  lcd.setCursor(0,0);
  lcd.write(byte(0));

  lcd.setCursor(2,0);
  lcd.write(byte(1));

  lcd.setCursor(4,0);
  lcd.write(byte(2)); 

  lcd.setCursor(6,0);
  lcd.write(byte(3)); 

  lcd.setCursor(8,0);
  lcd.write(byte(4)); 

  lcd.setCursor(10,0);
  lcd.write(byte(5)); 

  lcd.setCursor(12,0);
  lcd.write(byte(6)); 

  lcd.setCursor(14,0);
  lcd.write(byte(7));

  lcd.setCursor(5,1);
  lcd.write(byte(8));
}
