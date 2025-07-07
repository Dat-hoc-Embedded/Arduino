#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "RTClib.h"
int coi =3;
int nutlen=6;
int nutmenu=5;
int nutxuong=4;
int gtlen,gtxuong,gtmenu;
int demlen=0,demxuong;
int demmenu=0;
int setngay=1,setthang=1,hangnghin=0,hangtram=0,hangchuc=0,hangdonvi=0,setgio=0,setphut=0,setgiay=0;
int setnam;
RTC_DS1307 rtc;
LiquidCrystal_I2C lcd(0x27, 16,2);
char daysOfTheWeek[7][12] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
void setup () 
{
  pinMode(nutlen,INPUT_PULLUP);
  pinMode(nutmenu,INPUT_PULLUP);
  pinMode(nutxuong, INPUT_PULLUP);
  pinMode(coi,OUTPUT);
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
   // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));// to set the time manually 
     
}
void manhinhchinh(){
  //DateTime now = rtc.now();
    lcd.setCursor(0, 1);
    lcd.print("TIME");
    lcd.print(" ");
    lcd.print(rtc.now().hour());
    lcd.print(':');
    lcd.print(rtc.now().minute());
    lcd.print(':');
    lcd.print(rtc.now().second());
    lcd.print("  ");

    lcd.setCursor(0, 0);
    lcd.print("DATE");
    lcd.print(" ");
    //lcd.print(daysOfTheWeek[now.dayOfTheWeek()]);
    //lcd.print(" ");
    lcd.print(rtc.now().day());
    lcd.print('/');
    lcd.print(rtc.now().month());
    lcd.print('/');
    lcd.print(rtc.now().year());
    lcd.print("  ");   

}
void caidatngay(){
  lcd.clear();
  lcd.setCursor(2,0);
  lcd.print("CAI DAT NGAY");
  lcd.setCursor(4,1);
  lcd.print("NGAY: ");
  lcd.print(setngay);
  if(gtlen==0){
    setngay++;
    if(setngay>=32){
      setngay=1;
    }
  }
  if(gtxuong==0){
    setngay--;
    if(setngay<=0){
      setngay=31;
    }
  }
}
void caidatthang(){
  lcd.clear();
  lcd.setCursor(2,0);
  lcd.print("CAI DAT THANG");
  lcd.setCursor(4,1);
  lcd.print("THANG: ");
  lcd.print(setthang);
  if(gtlen==0){
    setthang++;
    if(setthang>=13){
      setthang=1;
    }
  }
  if(gtxuong==0){
    setthang--;
    if(setthang<=0){
      setthang=12;
    }
  }
}
void caidatnamhangnghin(){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("CAI DAT NAM:");
  lcd.print(hangnghin);lcd.print("000");
  lcd.setCursor(1,1);
  lcd.print("HANG NGHIN: ");
  lcd.print(hangnghin);
  if(gtlen==0){
    hangnghin++;
  }
  if(gtxuong==0){
    hangnghin--;
    if(hangnghin<=0){
      hangnghin=0;
    }
  }
}
void caidatnamhangtram(){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("CAI DAT NAM:");
  lcd.print(hangnghin);lcd.print(hangtram);lcd.print("00");
  lcd.setCursor(1,1);
  lcd.print("HANG TRAM: ");
  lcd.print(hangtram);
  if(gtlen==0){
    hangtram++;
  }
  if(gtxuong==0){
    hangtram--;
    if(hangtram<=0){
      hangtram=0;
    }
  }
}
void caidatnamhangchuc(){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("CAI DAT NAM:");
  lcd.print(hangnghin);lcd.print(hangtram);lcd.print(hangchuc);
  lcd.print("0");
  lcd.setCursor(1,1);
  lcd.print("HANG CHUC: ");
  lcd.print(hangchuc);
  if(gtlen==0){
    hangchuc++;
  }
  if(gtxuong==0){
    hangchuc--;
    if(hangchuc<=0){
      hangchuc=0;
    }
  }
}
void caidatnamhangdonvi(){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("CAI DAT NAM:");
  lcd.print(hangnghin);lcd.print(hangtram);lcd.print(hangchuc);
  lcd.print(hangdonvi);
  lcd.setCursor(1,1);
  lcd.print("HANG DON VI: ");
  lcd.print(hangdonvi);
  if(gtlen==0){
    hangdonvi++;
  }
  if(gtxuong==0){
    hangdonvi--;
    if(hangdonvi<=0){
      hangdonvi=0;
    }
  }
}
void caidatgio(){
  lcd.clear();
  lcd.setCursor(2,0);
  lcd.print("CAI DAT GIO");
  lcd.setCursor(4,1);
  lcd.print("GIO: ");
  lcd.print(setgio);
  if(gtlen==0){
    setgio++;
    if(setgio>=25){
      setgio=0;
    }
  }
  if(gtxuong==0){
    setgio--;
    if(setgio<=-1){
      setgio=24;
    }
  }
}
void caidatphut(){
  lcd.clear();
  lcd.setCursor(2,0);
  lcd.print("CAI DAT PHUT");
  lcd.setCursor(4,1);
  lcd.print("PHUT: ");
  lcd.print(setphut);
  if(gtlen==0){
    setphut++;
    if(setphut>=60){
      setphut=0;
    }
  }
  if(gtxuong==0){
    setphut--;
    if(setphut<=-1){
      setphut=59;
    }
  }
}
void caidatgiay(){
  lcd.clear();
  lcd.setCursor(2,0);
  lcd.print("CAI DAT GIAY");
  lcd.setCursor(4,1);
  lcd.print("GIAY: ");
  lcd.print(setgiay);
  if(gtlen==0){
    setgiay++;
    if(setgiay>=60){
      setgiay=0;
    }
  }
  if(gtxuong==0){
    setgiay--;
    if(setgiay<=-1){
      setgiay=59;
    }
  }
}void luucaidat(){
  rtc.adjust(DateTime(setnam, setthang, setngay, setgio, setphut, setgiay));// to set the time manually
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Saving the date");
  delay(1000);
  lcd.setCursor(0,1);
  lcd.print("...Done...");
  delay(2000);
  Serial.print(rtc.now().month());
  lcd.clear();
}
void capnhapmenu(){
  if(demmenu==0){
    manhinhchinh();
  }
  if(demmenu==1){
    caidatngay();
    delay(200);
  }
  if(demmenu==2){
    caidatthang();
    delay(200);
  }
  if(demmenu==3){
    caidatnamhangnghin();
    delay(200);
  }
  if(demmenu==4){
    caidatnamhangtram();
    delay(200);
  }
  if(demmenu==5){
    caidatnamhangchuc();
    delay(200);
  }
  if(demmenu==6){
    caidatnamhangdonvi();
    setnam=hangnghin*1000+hangtram*100+hangchuc*10+hangdonvi;
    delay(200);
  }
  if(demmenu==7){
    caidatgio();
    delay(200);
  }
  if(demmenu==8){
    caidatphut();
    delay(200);
  }
  if(demmenu==9){
    caidatgiay();
    delay(200);
  }
  if(demmenu==10){
    luucaidat();
    demmenu=0;
  }
}
void loop () 
{
    //doc gia tri nut nhan
    gtlen=digitalRead(nutlen);
    gtxuong=digitalRead(nutxuong);
    gtmenu=digitalRead(nutmenu);

    if(gtmenu==0){
      demmenu++;
    }
    capnhapmenu();
    //cai dat bao thuc
    if(rtc.now().hour()==1&&rtc.now().minute()==59){
      digitalWrite(coi,HIGH);
    }
}
