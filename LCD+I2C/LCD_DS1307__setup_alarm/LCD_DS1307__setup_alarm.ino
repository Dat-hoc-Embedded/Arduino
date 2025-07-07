#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "RTClib.h"
int coi =3;
int nutlen=6;
int nutchon=5;
int nutxuong=4;
int gtlen,gtxuong,gtchon;
int trangthai=0;
int demchon=0,demtong=0,demsettime=-1,demsetday=-1,demsetalarm1=-1,demsetalarm2=-1;
int gio=0,phut=0,giay=0;
int ngay=0,thang=0,namn=0,namt=0,namc=0,namdv=0,nam;
int cot=0,hang=0;
int ngay1=0,thang1=0,nam1,namn1=0,namt1=0,namc1=0,namdv1=0,gio1=0,phut1=0,giay1=0;
int ngay2=0,thang2=0,nam2,namn2=0,namt2=0,namc2=0,namdv2=0,gio2=0,phut2=0,giay2=0;
int baothuc=1;
//int ngay3,thang3,nam3,gio3,phut3,giay3;
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
    lcd.clear();
    lcd.noCursor();
    lcd.setCursor(0,0);
    lcd.print("DATE: ");
    lcd.print(rtc.now().day());lcd.print("/");
    lcd.print(rtc.now().month());lcd.print("/");
    lcd.print(rtc.now().year());
    lcd.setCursor(0,1);
    lcd.print("TIME: ");
    lcd.print(rtc.now().hour());lcd.print(":");
    lcd.print(rtc.now().minute());lcd.print(":");
    lcd.print(rtc.now().second());
    delay(1000);
}
void menutong(){
    lcd.noCursor();
    if(gtlen==0){
        demtong++;
        if(demtong>4){
            demtong=0;
        }
    }else if(gtxuong==0){
        demtong--;
        if(demtong<0){
            demtong=4;
        }
    }
    if(demtong==0){
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print(">BACK");
        lcd.setCursor(0,1);
        lcd.print(" SET TIME");
    }else if(demtong==1){
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print(" BACK");
        lcd.setCursor(0,1);
        lcd.print(">SET TIME");
    }else if(demtong==2){
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print(" SET TIME");
        lcd.setCursor(0,1);
        lcd.print(">SET DAY");
    }else if(demtong==3){
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print(">ALARM 1");
        lcd.setCursor(0,1);
        lcd.print(" ALARM 2");
    }else if(demtong==4){
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print(" ALARM 1");
        lcd.setCursor(0,1);
        lcd.print(">ALARM 2");
    }
}
void tanggiamgio(int &gio){
    if(gtlen==0){
        gio++;
        if(gio>23){gio=0;}
        
    }else if(gtxuong==0){
        gio--;
        if(gio<0){gio=23;}
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
    lcd.clear();lcd.setCursor(0,0);
    lcd.print("---SAVING DATA---");
    lcd.setCursor(2,1);
    lcd.print("....DONE....");
    delay(2000);
}
void menusettime(){
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print(" ---SET TIME--- ");
        lcd.setCursor(0,1);
        lcd.print(gio);lcd.setCursor(2,1);lcd.print(":");
        lcd.print(phut);lcd.setCursor(5,1);lcd.print(":");
        lcd.print(giay);
        lcd.setCursor(10,1);
        lcd.print("BACK");
    if(gtchon==0){
        demsettime+=1;
    }
    if(demsettime==0){
        if(gtlen==0){
            cot++;
            if(cot>15){
                cot=0;
            }
            delay(200);
        }else if(gtxuong==0){
            cot--;
            if(cot<0){
                cot=15;
            }
            delay(200);
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
            demchon=1;
            trangthai=0;
        }else {
            demsettime=0;
            delay(200);
        }
    }else if(demsettime==2){
        demsettime=0;
        delay(200);
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
            ngay=0;
        }
    }else if(gtxuong==0){
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
            thang=0;
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
    }else if(gtxuong==0){
        nam--;
        if(nam<0){
            nam=9;
        }
    }
}
void menusetday(){
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print(" ---SET DAY--- ");
        lcd.setCursor(0,1);
        lcd.print(ngay);lcd.setCursor(2,1);lcd.print("/");
        lcd.print(thang);lcd.setCursor(5,1);lcd.print("/");
        lcd.print(namn);lcd.print(namt);lcd.print(namc);lcd.print(namdv);
        lcd.setCursor(12,1);
        lcd.print("BACK");
    if(gtchon==0){
        demsetday+=1;
    }
    if(demsetday==0){
        if(gtlen==0){
            cot++;
            if(cot>15){
                cot=0;
            }
            delay(200);
        }else if(gtxuong==0){
            cot--;
            if(cot<0){
                cot=15;
            }
            delay(200);
        }
    }else if(demsetday==1){
        if(cot==0||cot==1){
            tanggiamngay(ngay);
        }else if(cot==3||cot==4){
            tanggiamthang(thang);
        }else if(cot==6){
            tanggiamnam(namn);
        }else if(cot==7){
            tanggiamnam(namt);
        }else if(cot==8){
            tanggiamnam(namc);
        }else if(cot==9){
            tanggiamnam(namdv);
        }else if(cot==12||cot==13||cot==14||cot==15){
            thongbaodaluu();
            demchon=1;
            trangthai=0;
        }else{
            demsetday=0;
            delay(200);
        }
    }else if(demsetday==2){
        demsetday=0;
        delay(200);
    }
    nam=namn*1000+namt*100+namc*10+namdv;
    rtc.adjust(DateTime(nam, thang, ngay, rtc.now().hour(),rtc.now().minute() , rtc.now().second()));
    lcd.setCursor(cot,1);
    lcd.cursor();
}
void menualarm1(){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("DATE: ");lcd.setCursor(6,0);
    lcd.print(ngay1);
    lcd.setCursor(8,0);lcd.print("/");lcd.print(thang1);
    lcd.setCursor(11,0);lcd.print("/");lcd.print(namn1);lcd.print(namt1);
    lcd.print(namc1);lcd.print(namdv1);
    lcd.setCursor(0,1);
    lcd.print("TIME: ");lcd.setCursor(6,1);
    lcd.print(gio1);lcd.setCursor(8,1);lcd.print(":");
    lcd.print(phut1);lcd.setCursor(11,1);lcd.print(":");
    lcd.print(giay1);
    lcd.setCursor(15,1);
    lcd.write(byte(0));

    if(gtchon==0){
        demsetalarm1++;
    }
    if(demsetalarm1==0){
        if(gtlen==0){
            cot++;
            if(cot>15){
                cot=0;
                if(hang==0){
                    hang=1;
                }else if(hang==1){
                    hang=0;
                }
            }
            delay(200);
        }else if(gtxuong==0){
            cot--;
            if(cot<0){
                cot=15;
                if(hang==0){
                    hang=1;
                }else if(hang==1){
                    hang=0;
                }
            }
            delay(200);
        }
    }else if(demsetalarm1==1){
        if(hang==0){
            if(cot==6 ||cot ==7){
                tanggiamngay(ngay1);
            }else if (cot==9||cot==10){
                tanggiamthang(thang1);
            }else if (cot==12){
                tanggiamnam(namn1);
            }else if(cot==13){
                tanggiamnam(namt1);
            }else if(cot==14){
                tanggiamnam(namc1);
            }else if(cot==15){
                tanggiamnam(namdv1);
            }else{
                demsetalarm1=0;
            }
        }else if(hang==1){
            if(cot==6||cot==7){
                tanggiamgio(gio1);
            }else if(cot==9||cot==10){
                tanggiamphut(phut1);
            }else if(cot==12||cot==13){
                tanggiamgiay(giay1);
            }else if(cot==15){
                thongbaodaluu();
                trangthai=0;
                demchon=1;
            }else{
                demsetalarm1=0;
                delay(100);
            }
        }
    }else if(demsetalarm1==2){
        demsetalarm1=0;
        delay(100);
    }
    nam1=namn1*1000+namt1*100+namc1*10+namdv1;
    lcd.setCursor(cot,hang);
    lcd.cursor();

}
void menualarm2(){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("DATE: ");lcd.setCursor(6,0);
    lcd.print(ngay2);
    lcd.setCursor(8,0);lcd.print("/");lcd.print(thang2);
    lcd.setCursor(11,0);lcd.print("/");lcd.print(namn2);lcd.print(namt2);
    lcd.print(namc2);lcd.print(namdv2);
    lcd.setCursor(0,1);
    lcd.print("TIME: ");lcd.setCursor(6,1);
    lcd.print(gio2);lcd.setCursor(8,1);lcd.print(":");
    lcd.print(phut2);lcd.setCursor(11,1);lcd.print(":");
    lcd.print(giay2);
    lcd.setCursor(15,1);
    lcd.write(byte(0));

    if(gtchon==0){
        demsetalarm2++;
    }
    if(demsetalarm2==0){
        if(gtlen==0){
            cot++;
            if(cot>15){
                cot=0;
                if(hang==0){
                    hang=1;
                }else if(hang==1){
                    hang=0;
                }
            }
            delay(200);
        }else if(gtxuong==0){
            cot--;
            if(cot<0){
                cot=15;
                if(hang==0){
                    hang=1;
                }else if(hang==1){
                    hang=0;
                }
            }
            delay(200);
        }
    }else if(demsetalarm2==1){
        if(hang==0){
            if(cot==6 ||cot ==7){
                tanggiamngay(ngay2);
            }else if (cot==9||cot==10){
                tanggiamthang(thang2);
            }else if (cot==12){
                tanggiamnam(namn2);
            }else if(cot==13){
                tanggiamnam(namt2);
            }else if(cot==14){
                tanggiamnam(namc2);
            }else if(cot==15){
                tanggiamnam(namdv2);
            }else{
                demsetalarm2=0;
            }
        }else if(hang==1){
            if(cot==6||cot==7){
                tanggiamgio(gio2);
            }else if(cot==9||cot==10){
                tanggiamphut(phut2);
            }else if(cot==12||cot==13){
                tanggiamgiay(giay2);
            }else if(cot==15){
                thongbaodaluu();
                trangthai=0;
                demchon=1;
            }else{
                demsetalarm2=0;
                delay(100);
            }
        }
    }else if(demsetalarm2==2){
        demsetalarm2=0;
        delay(100);
    }
    nam2=namn2*1000+namt2*100+namc2*10+namdv2;
    lcd.setCursor(cot,hang);
    lcd.cursor();
}
bool ktrabaothuc(int ngay,int thang,int nam, int gio, int phut,int giay){
    if(ngay==rtc.now().day()&&thang==rtc.now().month()&&nam==rtc.now().year()
    &&gio==rtc.now().hour()&&phut==rtc.now().minute()){
                return true;
    }
    return false;
}
void doitrangthaibaothuc(){
    bool check1=ktrabaothuc(ngay1,thang1,nam1,gio1,phut1,giay1);
    bool check2=ktrabaothuc(ngay2,thang2,nam2,gio2,phut2,giay2);
    if(check1==true ||check2==true){
        trangthai=5;
    }else {
        trangthai=0;
    }
}
void thongbaocobaothuc(){
    lcd.clear();
    lcd.setCursor(3,0);
    lcd.print("THONG BAO");lcd.setCursor(2,1);
    lcd.print("--DANG KEU--");
}
void chuongbaothuc(){
    if(baothuc==1){
        thongbaocobaothuc();
        digitalWrite(coi,HIGH);
        delay(500);
        digitalWrite(coi,LOW);
        delay(50);
    }else{
        manhinhchinh();
    }
    if(gtchon==0&&trangthai==5){
        baothuc=0;
    }
}
void loop(){
    Serial.print(trangthai);
    gtlen=digitalRead(nutlen);
    gtxuong=digitalRead(nutxuong);
    gtchon=digitalRead(nutchon);

    if(gtchon==0&&trangthai==0){
        demchon++;
    }
    if(demchon==0){
        doitrangthaibaothuc();
        if(trangthai==5){
        chuongbaothuc();
        }else{
        baothuc=1;
        manhinhchinh();
        }
    } 
    if(demchon==1){
        menutong();
        delay(200);
    }
    if(demchon==2){
        if(demtong==0){
            demchon=0;
        }else if(demtong==1){
            trangthai=1;
            menusettime();
        }else if(demtong==2){
            trangthai=2;
            menusetday();
        }else if(demtong==3){
            trangthai=3;
            menualarm1();
        }else if(demtong==4){
            trangthai=4;
            menualarm2();
        }
        delay(200);
    }
    
}
