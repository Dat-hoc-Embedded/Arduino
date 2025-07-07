#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
int phai=6;
int trai=4;
int cot=0;
int hang=0;
void setup() {
  // put your setup code here, to run once:
  lcd.begin();
  
  pinMode(phai,INPUT_PULLUP);
  pinMode(trai,INPUT_PULLUP);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("DAT DEP ZAI ^_^");
  lcd.setCursor(2,1);
  lcd.print("Dinh cao -.-");
}
void loop() {
  // put your main code here, to run repeatedly:
  int gtphai=digitalRead(phai);
  int gttrai=digitalRead(trai);
  if(gtphai==0){
    cot++;
    if(cot>15){
      cot=0;
      if(hang==0){
        hang=1;
      }else if(hang==1){
        hang=0;
      }
    }
    delay(100);
  }else if(gttrai==0){
    cot--;
    if(cot<0){
      cot=15;
      if(hang==0){
        hang=1;
      }else if (hang ==1){
        hang =0;
      }
    }
    delay(100);
  }
  lcd.setCursor(cot,hang);
  lcd.cursor();
  delay(200);
}
