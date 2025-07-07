#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "RTClib.h"
int coi =3;
int nutlen=6;
int nutchon=5;
int nutxuong=4;
int gtlen,gtxuong,gtchon;
int trangthai=0;
unsigned long hientai=0;
int demchon=0,demtong=0,demsettime=-1,demsetdate=-1,demtdoirelay=0;
int cot=0,hang=0;
int gio=0,phut=0,giay=0,ngay=0,thang=0,nam=0,namn=0,namt=0,namc=0,namdv=0;
int gio1s=0,phut1s=0,gio1e=0,phut1e=0,demdk1=-1;
int gio2s=0,phut2s=0,gio2e=0,phut2e=0,demdk2=-1;
String s1="1",s2="1";
RTC_DS1307 rtc;
LiquidCrystal_I2C lcd(0x27, 16,2);
char daysOfTheWeek[7][12] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
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
void setup() {
  pinMode(nutlen,INPUT_PULLUP);
  pinMode(nutchon,INPUT_PULLUP);
  pinMode(nutxuong, INPUT_PULLUP);
  pinMode(coi,OUTPUT);
  digitalWrite(coi,LOW);
  Serial.begin(9600);
  lcd.begin ();  // initialize the lcd 
  lcd.backlight();//To Power ON the back light
  lcd.createChar(0,tick);
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
    lcd.noCursor();
    hientai=millis();
    lcd.setCursor(0,0);
    lcd.print("DATE: ");
    if(rtc.now().day()<10){
      lcd.print(0);lcd.print(rtc.now().day());
    }else{
      lcd.print(rtc.now().day());
    }
    lcd.print("/");
    if(rtc.now().month()<10){
      lcd.print(0);lcd.print(rtc.now().month());
    }else{
      lcd.print(rtc.now().month());
    }
    lcd.print("/");
    if(rtc.now().year()<10){
      lcd.print(0);lcd.print(rtc.now().year());
    }else{
      lcd.print(rtc.now().year());
    }
    lcd.setCursor(0,1);
    lcd.print("TIME: ");
    if(rtc.now().hour()<10){
      lcd.print(0);lcd.print(rtc.now().hour());
    }else{
      lcd.print(rtc.now().hour());
    }
    lcd.print(":");
    if(rtc.now().minute()<10){
      lcd.print(0);lcd.print(rtc.now().minute());
    }else{
      lcd.print(rtc.now().minute());
    }
    lcd.print(":");
    if(rtc.now().second()<10){
      lcd.print(0);lcd.print(rtc.now().second());
    }else{
      lcd.print(rtc.now().second());
    }
    
}
void menutong(){
    lcd.noCursor();
    if(gtxuong==0){
        demtong--;
        lcd.clear();
        if(demtong<0){
            demtong=4;
        }
    }else if(gtlen==0){
        demtong++;
        lcd.clear();
        if(demtong>4){
            demtong=0;
        }
    }
    if(demtong==0){
        lcd.setCursor(0,0);
        lcd.print(">BACK");
        lcd.setCursor(0,1);
        lcd.print(" SET TIME");
    }else if(demtong==1){
        lcd.setCursor(0,0);
        lcd.print(" BACK");
        lcd.setCursor(0,1);
        lcd.print(">SET TIME");
    }else if(demtong==2){
        lcd.setCursor(0,0);
        lcd.print(">SET DATE");
        lcd.setCursor(0,1);
        lcd.print(" DIEU KHIEN 1");
    }else if(demtong==3){
        lcd.setCursor(0,0);
        lcd.print(" SET DATE");
        lcd.setCursor(0,1);
        lcd.print(">DIEU KHIEN 1");
    }else if(demtong==4){
        lcd.setCursor(0,0);
        lcd.print(" DIEU KHIEN 1");
        lcd.setCursor(0,1);
        lcd.print(">DIEU KHIEN 2");
    }
    
}
void tanggiamgio(int &gio){
  if(gtlen==0){
    gio++;
    if(gio>23){
      gio=0;
    }
  }else if (gtxuong==0){
    gio--;
    if(gio<0){
      gio=23;
    }
  }
}
void tanggiamphut(int &phut){
    if(gtlen==0){
        phut++;
        if(phut>59){phut=0;}
        
    }else if(gtxuong==0){
        phut--;
        if(phut<0){phut=59;}
    }
}
void tanggiamgiay(int &giay){
    if(gtlen==0){
        giay++;
        if(giay>59){giay=0;}
        
    }else if(gtxuong==0){
        giay--;
        if(giay<0){giay=59;}
    }
}
void thongbaodaluu(){
    lcd.noCursor();
    lcd.clear();lcd.setCursor(0,0);
    lcd.print("---SAVING DATA---");
    lcd.setCursor(2,1);
    lcd.print("....DONE....");
    delay(1000);
}
void menusettime(){
        lcd.setCursor(0,0);
        lcd.print(" ---SET TIME--- ");
        lcd.setCursor(0,1);
        if(gio<10){
          lcd.print(0);lcd.print(gio);
        }else {
          lcd.print(gio);
        }
        lcd.setCursor(2,1);lcd.print(":");
        if(phut<10){
          lcd.print(0);lcd.print(phut);
        }else {
          lcd.print(phut);
        }
        lcd.setCursor(5,1);lcd.print(":");
        if(giay<10){
          lcd.print(0);lcd.print(giay);
        }else {
          lcd.print(giay);
        }
        lcd.setCursor(10,1);
        lcd.print("BACK");
        if(gtchon==0){
            demsettime++;
        }
        if(demsettime==0){
          if(gtlen==0){
            cot++;
            if(cot>15){
              cot=0;
            }
          }else if(gtxuong==0){
            cot--;
            if(cot<0){
              cot=15;
            }
          }
        }else if(demsettime==1){
            if(cot==0||cot==1){
                tanggiamgio(gio);
            }else if(cot==3||cot==4){
                tanggiamphut(phut);
            }else if(cot==6||cot==7){
                tanggiamgiay(giay);
            }else if(cot==10||cot==11||cot==12||cot==13){
                thongbaodaluu();
                lcd.clear();
                demchon=1;
                demsettime=-1;
                trangthai=0;
            }else{
                demsettime=0;
                delay(200);
            }
        }else if(demsettime==2){
          demsettime=0;
        }
    rtc.adjust(DateTime(rtc.now().year(), rtc.now().month(), rtc.now().day(), gio, phut, giay));
    //Serial.print(demsettime);
    lcd.setCursor(cot,1);
    lcd.cursor();
}
void tanggiamngay(int &ngay){
  if(gtlen==0){
    ngay++;
    if(ngay>31){
      ngay=1;
    }
  }else if (gtxuong==0){
    ngay--;
    if(ngay<0){
      ngay=31;
    }
  }
}
void tanggiamthang(int &thang){
  if(gtlen==0){
    thang++;
    if(thang>12){
      thang=1;
    }
  }else if(gtxuong==0){
    thang--;
    if(thang<0){
      thang=12;
    }
  }
}
void tanggiamnam(int &nam){
  if(gtlen==0){
    nam++;
    if(nam>9){
      nam=0;
    }
  }else if (gtxuong==0){
    nam--;
    if(nam<0){
      nam=9;
    }
  }
}
void menusetdate(){
        lcd.setCursor(0,0);
        lcd.print(" ---SET DATE--- ");
        lcd.setCursor(0,1);
        if(ngay<10){
          lcd.print(0);lcd.print(ngay);
        }else {
          lcd.print(ngay);
        }
        lcd.setCursor(2,1);lcd.print(":");
        if(thang<10){
          lcd.print(0);lcd.print(thang);
        }else {
          lcd.print(thang);
        }
        lcd.setCursor(5,1);lcd.print(":");
        if(nam<10){
          lcd.print(0);lcd.print(nam);
        }else {
          lcd.print(nam);
        }
        lcd.setCursor(11,1);
        lcd.print("BACK");

  if(gtchon==0){
    demsetdate++;
  }
  if(demsetdate==0){
      if(gtlen==0){
        cot++;
        if(cot>15){
          cot=0;
        }
      }else if (gtxuong==0){
        cot--;
        if(cot<0){
          cot=15;
        }
      }
  }else if(demsetdate==1){
    if(cot==0||cot==1){
      tanggiamngay(ngay);
    }else if (cot==3||cot==4){
      tanggiamthang(thang);
    }else if (cot==6){
      tanggiamnam(namn);
    }else if(cot==7){
      tanggiamnam(namt);
    }else if (cot==8){
      tanggiamnam(namc);
    }else if (cot==9){
      tanggiamnam(namdv);
    }else if(cot==11 || cot==12|| cot==13||cot==14){
      thongbaodaluu();
      lcd.clear();
      demchon=1;
      demsetdate=-1;
      trangthai=0;
    }else{
      demsetdate=0;
    }
  }else if(demsetdate==2){
      demsetdate=0;
  }
  nam=namn*1000+namt*100+namc*10+namdv;
  rtc.adjust(DateTime(nam, thang, ngay, rtc.now().hour(), rtc.now().minute(), rtc.now().second()));
  lcd.setCursor(cot,1);
  lcd.cursor();
}
void thaydoirelay(String &s){
  if(gtlen==0){
      demtdoirelay++;
      if(demtdoirelay>2){
        demtdoirelay=0;
        lcd.clear();
      }
  }else if(gtxuong==0){
    demtdoirelay--;
    lcd.clear();
    if(demtdoirelay<0){
      demtdoirelay=2;
    }
  }
  if(demtdoirelay==0){
    s="1";
  }else if(demtdoirelay==1){
    s="2";
  }else if(demtdoirelay==2){
    s="1+2";
  }
}
void dieukhien1(){
    lcd.setCursor(0,0);
    lcd.print("ON: ");lcd.setCursor(4,0);
    if(gio1s<10){
          lcd.print(0);lcd.print(gio1s);
        }else {
          lcd.print(gio1s);
        }
    lcd.setCursor(6,0);
    lcd.print(":");
    if(phut1s<10){
          lcd.print(0);lcd.print(phut1s);
        }else {
          lcd.print(phut1s);
        }
    lcd.setCursor(10,0);lcd.print("RE:");lcd.print(s1);

    lcd.setCursor(0,1);
    lcd.print("OF: ");lcd.setCursor(4,1);
    if(gio1e<10){
          lcd.print(0);lcd.print(gio1e);
        }else {
          lcd.print(gio1e);
        }
    lcd.setCursor(6,1);
    lcd.print(":");
    if(phut1e<10){
          lcd.print(0);lcd.print(phut1e);
        }else {
          lcd.print(phut1e);
        }
    lcd.setCursor(12,1);lcd.write(byte(0));

    if(gtchon==0){
      demdk1++;
    }
    if(demdk1==0){
      if(gtlen==0){
        cot++;
        if(cot>15){
          cot=0;
          if(hang==0){
            hang=1;
          }else {
            hang=0;
          }
        }
      }else if( gtxuong==0){
        cot--;
        if(cot<0){
          cot=15;
          if(hang==0){
            hang=1;
          }else{
            hang=0;
          }
        }
      }
    }else if (demdk1==1){
        if(hang==0){
          if(cot==4||cot==5){
            tanggiamgio(gio1s);
          }else if(cot==7||cot==8){
            tanggiamphut(phut1s);
          }else if(cot==13||cot==14||cot==15){
            thaydoirelay(s1);
          }else{
            demdk1=0;
          }
        }else{
          if(cot==4||cot==5){
            tanggiamgio(gio1e);
          }else if (cot==7||cot==8){
            tanggiamphut(phut1e);
          }else  if(cot==12){
            thongbaodaluu();
            lcd.clear();
            trangthai=0;
            demchon=1;
            demdk1=-1;
          }else {
            demdk1=0;
          }
        }
    }else if(demdk1==2){
      demdk1=0;
    }
    lcd.setCursor(cot,hang);
    lcd.cursor();
}
void dieukhien2(){
    lcd.setCursor(0,0);
    lcd.print("ON: ");lcd.setCursor(4,0);
    if(gio2s<10){
          lcd.print(0);lcd.print(gio2s);
        }else {
          lcd.print(gio2s);
        }
    lcd.setCursor(6,0);
    lcd.print(":");
    if(phut2s<10){
          lcd.print(0);lcd.print(phut2s);
        }else {
          lcd.print(phut2s);
        }
    lcd.setCursor(10,0);lcd.print("RE:");lcd.print(s2);

    lcd.setCursor(0,1);
    lcd.print("OF: ");lcd.setCursor(4,1);
    if(gio2e<10){
          lcd.print(0);lcd.print(gio2e);
        }else{
          lcd.print(gio2e);
        }
    lcd.setCursor(6,1);
    lcd.print(":");
    if(phut2e<10){
          lcd.print(0);lcd.print(phut2e);
        }else {
          lcd.print(phut2e);
        }
    lcd.setCursor(12,1);lcd.write(byte(0));

    if(gtchon==0){
      demdk2++;
    }
    if(demdk2==0){
      if(gtlen==0){
        cot++;
        if(cot>15){
          cot=0;
          if(hang==0){
            hang=1;
          }else {
            hang=0;
          }
        }
      }else if( gtxuong==0){
        cot--;
        if(cot<0){
          cot=15;
          if(hang==0){
            hang=1;
          }else{
            hang=0;
          }
        }
      }
    }else if (demdk2==1){
        if(hang==0){
          if(cot==4||cot==5){
            tanggiamgio(gio2s);
          }else if(cot==7||cot==8){
            tanggiamphut(phut2s);
          }else if(cot==13||cot==14||cot==15){
            thaydoirelay(s2);
          }else{
            demdk2=0;
          }
        }else{
          if(cot==4||cot==5){
            tanggiamgio(gio2e);
          }else if (cot==7||cot==8){
            tanggiamphut(phut2e);
          }else  if(cot==12){
            thongbaodaluu();
            lcd.clear();
            trangthai=0;
            demchon=1;
            demdk2=-1;
          }else {
            demdk2=0;
          }
        }
    }else if(demdk2==2){
      demdk2=0;
    }
    lcd.setCursor(cot,hang);
    lcd.cursor();
}
void battatdelay(int gio1s,int gio1e,int phut1s,int phut1e,String s1){
  if(rtc.now().hour()==gio1s&&rtc.now().minute()==phut1s){
    if(s1=="1"){
      //kich delay 1;
    }else if(s1=="2"){
      //kich delay 2;
    }else if(s1=="1+2"){
      //kich ca 2 de lay
    }
    
  }
  if(rtc.now().hour()==gio1e&&rtc.now().minute()==phut1e){
    if(s1=="1"){
      //tat delay 1;
    }else if(s1=="2"){
      //tat delay 2;
    }else if(s1=="1+2"){
      //tat ca 2 de lay
    }
  }

}
void loop() {
  Serial.print(demchon);
    gtlen=digitalRead(nutlen);
    gtxuong=digitalRead(nutxuong);
    gtchon=digitalRead(nutchon);
  if(gtchon==0&&trangthai==0){
    lcd.clear();
    demchon++;
  }
  if(demchon==0){
    manhinhchinh();
  }else if(demchon==1){
    menutong();
    delay(200);
  }else if(demchon==2){
    if(demtong==0){
        demchon=0;
    }else if(demtong==1){
        trangthai=1;
        menusettime();
    }else if(demtong==2){
      trangthai=2;
      menusetdate();
    }else if(demtong==3){
      trangthai=3;
      dieukhien1();
    }else if(demtong==4){
      trangthai=4;
      dieukhien2();
    }
    delay(200);
  }
  battatdelay(gio1s,gio1e,phut1s,phut1e,s1);
  battatdelay(gio2s,gio2e,phut2s,phut2e,s2);
}
