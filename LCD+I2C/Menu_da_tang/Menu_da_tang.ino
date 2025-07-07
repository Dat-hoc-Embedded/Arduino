#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
int nutlen=6;
int nutchon=5;
int nutxuong=4;
int bientro=A0;
int gtlen,gtxuong,gtchon,gtbientro,gtbiendoi;
int trangthai;
int demchon=0,demtong=0,demmenu1=0,demmenu2=0;
int dosang=0;
void manhinhchinh(){
  lcd.clear();
  lcd.setCursor(1,0);
  lcd.print("MAN HINH CHINH");
}
void menutong(){
    if(gtlen==0){
        demtong++;
        if(demtong>=4){
            demtong=0;
        }
    }else if(gtxuong==0){
        demtong--;
        if(demtong<=-1){
            demtong=3;
        }
    }
    if(demtong==0){
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print(">BACK ");
        lcd.setCursor(0,1);
        lcd.print(" MENU 1");
    }else if(demtong==1){
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print(" BACK ");
        lcd.setCursor(0,1);
        lcd.print(">MENU 1");
    }else if(demtong==2){
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print(">MENU 2 ");
        lcd.setCursor(0,1);
        lcd.print(" MENU 3");
    }
    else if(demtong==3){
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print(" MENU 2 ");
        lcd.setCursor(0,1);
        lcd.print(">MENU 3");
    }

}
void menu1(){
    trangthai=1;
    if(gtlen==0){
        demmenu1++;
        if(demmenu1>=3){
            demmenu1=0;
        }
    }else if(gtxuong==0){
        demmenu1--;
        if(demmenu1<=-1){
            demmenu1=2;
        }
    }
    if(demmenu1==0){
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print(">BACK");
        lcd.setCursor(0,1);
        lcd.print(" MENU 1-A");
    }else if (demmenu1==1){
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print(" BACK");
        lcd.setCursor(0,1);
        lcd.print(">MENU 1-A");
    }else if(demmenu1==2){
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print(" MENU 1-A");
        lcd.setCursor(0,1);
        lcd.print(">MENU 1-B");
    }
}
void menu2(){
    trangthai=2;
    if(gtlen==0){
        demmenu2++;
        if(demmenu2>=4){
            demmenu2=0;
        }
    }else if(gtxuong==0){
        demmenu2--;
        if(demmenu2<=-1){
            demmenu2=3;
        }
    }
    if(demmenu2==0){
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print(">BACK");
        lcd.setCursor(0,1);
        lcd.print(" BIEN TRO");
    }else if(demmenu2==1){
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print(">BIEN TRO");
        lcd.setCursor(0,1);
        lcd.print(" DO SANG");
    }else if(demmenu2==2){
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print(" BIEN TRO");
        lcd.setCursor(0,1);
        lcd.print(">DO SANG");
    }
}
void menu3(){}
void setup() {
  pinMode(nutlen,INPUT_PULLUP);
  pinMode(nutxuong,INPUT_PULLUP);
  pinMode(nutchon, INPUT_PULLUP);
  Serial.begin(9600);
  lcd.begin();
  lcd.backlight();
  pinMode(bientro,INPUT);
}

void loop() {
   gtbientro = analogRead(bientro);  
   gtbiendoi = map(gtbientro, 0, 1023, 0, 100);
   gtlen=digitalRead(nutlen);
   gtxuong=digitalRead(nutxuong);
   gtchon=digitalRead(nutchon);
  //thuat toan
  if(gtchon==0){
    demchon++;
  }
  if(demchon==0){
manhinhchinh();
    delay(200);
  }
  if(demchon==1){
    menutong();
    delay(200);
  }
  if(demchon==2){
    if(demtong==0){
        demchon=0;
        delay(200);
    }
    if(demtong==1){
        menu1();
        delay(200);
    }else if(demtong==0){
        demchon=0;
    }else if(demtong==2){
        menu2();
        delay(200);
    }else if(demtong==3){
        trangthai=3;
        lcd.clear();
        lcd.setCursor(4,0);
        lcd.print("MENU 3");
        lcd.setCursor(1,1);
        lcd.print("NOI DUNG MENU 3");
        delay(200);
    }
  }
  if(demchon==3){
    if(trangthai==1){
        if(demmenu1==1){
            lcd.clear();
            lcd.setCursor(4,0);
            lcd.print("MENU 1-A");
            lcd.setCursor(1,1);
            lcd.print("NOI DUNG MENU A");
        }else if (demmenu1==2){
            lcd.clear();
            lcd.setCursor(4,0);
            lcd.print("MENU 1-B");
            lcd.setCursor(1,1);
            lcd.print("NOI DUNG MENU B");
        }else if(demmenu1==0){
            demchon=1;
        }
        delay(200);
    }else if(trangthai==2){
        if(demmenu2==0){
            demchon=1;
        }else if(demmenu2==1){
            lcd.clear();
            lcd.setCursor(3,0);
            lcd.print("BIEN TRO");
            lcd.setCursor(1,1);
            lcd.print("GIA TRI: ");lcd.print(gtbiendoi);
        }else if(demmenu2==2){
            lcd.clear();
            lcd.setCursor(4,0);
            lcd.print("DO SANG");
            lcd.setCursor(1,1);
            lcd.print("GIA TRI: ");lcd.print(dosang);
            if(gtlen==0){
                dosang++;
                if(dosang>=101){dosang=100;}
                }else if(gtxuong==0){
                    dosang--;
                    if(dosang<=0){dosang=0;}
                }
            }
            delay(200);
        }else if(trangthai==3){
            demchon=1;
            delay(200);
        }
    }
  if(demchon==4&&trangthai==1&&(demmenu1==1||demmenu1==2)){
    demchon=2;
    delay(200);
  }
  if(demchon==4&&trangthai==2&&(demmenu2==1||demmenu2==2)){
    demchon=2;
    delay(200);
  }
}
