#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

int len = 4; int gtlen;
int xuong = 5;  int gtxuong;
int menu = 6; int gtmenu;
int demmenu = 0;

byte hihi[] = {
  B00000,
  B10100,
  B11101,
  B10101,
  B00000,
  B10100,
  B11101,
  B10101
};
void setup() 
{
  Serial.begin(9600);
  
  lcd.begin();
  lcd.backlight();
  lcd.createChar(0,hihi);
  
  pinMode(len, INPUT_PULLUP);
  pinMode(xuong, INPUT_PULLUP);
  pinMode(menu, INPUT_PULLUP);
  
  menucapnhat();
}

void loop() 
{
  gtlen = digitalRead(len);
  Serial.print("Lên: "); Serial.print(gtlen); Serial.print("    ");
  gtxuong = digitalRead(xuong);
  Serial.print("Xuống: "); Serial.print(gtxuong); Serial.print("    ");
  gtmenu = digitalRead(menu);
  if (gtlen == 0)
  {
    if (demmenu >= 3)
    { demmenu = 0;  }
    else
    { demmenu++;  }   
    menucapnhat();
    delay(200);
  }
  
  if (gtxuong == 0)
  {
    if (demmenu <= 0)
    { demmenu = 3;  }
    else
    { demmenu--;  }
    menucapnhat();
    delay(200);
  }
  
  if (gtmenu == 0)
  {
    chonmenu();
    menucapnhat();
    delay(200);
  }
  Serial.print("Đếm Menu: "); Serial.print(demmenu); Serial.println("    ");
}

void menucapnhat() 
{
  if (demmenu == 0)
  {
    lcd.clear();
    lcd.print(">CAU TRA LOI 1");
    lcd.setCursor(0, 1);
    lcd.print(" CAU TRA LOI 2");  
  }
  else if (demmenu == 1)
  {
    lcd.clear();
    lcd.print(" CAU TRA LOI 1");
    lcd.setCursor(0, 1);
    lcd.print(">CAU TRA LOI 2");    
  }
  else if (demmenu == 2)
  {
    lcd.clear();
    lcd.print(">CAU TRA LOI 3");
    lcd.setCursor(0, 1);
    lcd.print(" CAU TRA LOI 4");   
  }
  else if (demmenu == 3)
  {
    lcd.clear();
    lcd.print(" CAU TRA LOI 3");
    lcd.setCursor(0, 1);
    lcd.print(">CAU TRA LOI 4");    
  }
}
  
void chonmenu() 
{
  switch (demmenu) 
  {
    case 0:
      lcd.clear();
      lcd.setCursor(5,0);
      lcd.print("CAU TRA LOI 1");
      lcd.setCursor(0,1);
      lcd.print("KHONG BE OI"); 
      delay(5000);
      break;
    case 1:
      lcd.clear();
      lcd.setCursor(5,0);
      lcd.print("CAU TRA LOI 2");
      lcd.setCursor(0,1);
      lcd.print("CO CAI NIT");
      lcd.setCursor(11,1);
      lcd.write(byte(0));
      delay(5000);
      break;
    case 2:
      lcd.clear();
      lcd.setCursor(5,0);
      lcd.print("CAU TRA LOI 3");
      lcd.setCursor(0,1);
      lcd.print("TINH DI ONG CHAU OI!");
      delay(5000);
      break;
    case 3:
      lcd.clear();
      lcd.setCursor(5,0);
      lcd.print("CAU TRA LOI 4");
      lcd.setCursor(0,1);
      lcd.print("lE THI HONG NAU");
      delay(5000);
      break;
  }
}
