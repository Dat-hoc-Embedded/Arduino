#include <Arduino.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
//khoi tao bien cua encoder
int phaA=2; int phaB=3;int nutchon=4;
int bandau;int demencoder=0;int hientai;
int gtnutchon,trangthai=0;
int demtong=0;int demchon=0;int demmenu1=0;
int phaAlast=LOW;int n=LOW;
int dosang=0;

void setup(){
    Serial.begin(9600);
    pinMode(phaA,INPUT);
    pinMode(phaB,INPUT);
    pinMode(nutchon,INPUT_PULLUP);
    lcd.begin();
    lcd.backlight();
    lcd.clear();
    bandau=digitalRead(phaA);
}
void demxoay(){
   n=digitalRead(phaA);
    if((phaAlast==LOW)&&(n==HIGH)){
        if(digitalRead(phaB)==LOW){
            demencoder++;
            delay(10);
            lcd.clear();
        }else{
            demencoder--;
            delay(10);
            lcd.clear();
        }
    }
    if(demencoder>20){
      demencoder=0;
    }else if(demencoder<0){
      demencoder=20;
    }
    phaAlast=n;
}
void menumanhinhchinh(){
    lcd.setCursor(1,0);
    lcd.print("MAN HINH CHINH");
}
void menutong(){
    if(demtong==0){
        lcd.setCursor(0,0);
        lcd.print(">BACK");
        lcd.setCursor(0,1);
        lcd.print(" MENU 1");
    }else if(demtong==1){
        lcd.setCursor(0,0);
        lcd.print(" BACK");
        lcd.setCursor(0,1);
        lcd.print(">MENU 1");
    }else if(demtong==2){
        lcd.setCursor(0,0);
        lcd.print(">MENU 2");
        lcd.setCursor(0,1);
        lcd.print(" MENU 3");
    }else if(demtong==3){
        lcd.setCursor(0,0);
        lcd.print(" MENU 2");
        lcd.setCursor(0,1);
        lcd.print(">MENU 3");
    }else if(demtong==4){
        lcd.setCursor(0,0);
        lcd.print(">MENU 4");
        lcd.setCursor(0,1);
        lcd.print(" MENU 5");
    }else if(demtong==5){
        lcd.setCursor(0,0);
        lcd.print(" MENU 4");
        lcd.setCursor(0,1);
        lcd.print(">MENU 5");
    }
}
void menu1(){
    if(demmenu1==0){
        lcd.setCursor(0,0);
        lcd.print(">BACK");
        lcd.setCursor(0,1);
        lcd.print(" MENU 1-A");
    }else if(demmenu1==1){
        lcd.setCursor(0,0);
        lcd.print(" BACK");
        lcd.setCursor(0,1);
        lcd.print(">MENU 1-A");
    }else if(demmenu1==2){
        lcd.setCursor(0,0);
        lcd.print(">MENU 1-B");
        lcd.setCursor(0,1);
        lcd.print(" MENU 1-C");
    }else if(demmenu1==3){
        lcd.setCursor(0,0);
        lcd.print(" MENU 1-B");
        lcd.setCursor(0,1);
        lcd.print(">MENU 1-C");
    }

}
void menu2(){
    lcd.setCursor(3,0);
    lcd.print("DO SANG");
    lcd.setCursor(5,1);
    lcd.print(dosang);

n=digitalRead(phaA);
    if((phaAlast==LOW)&&(n==HIGH)){
        if(digitalRead(phaB)==LOW){
            dosang++;
            delay(10);
            lcd.clear();
        }else{
            dosang--;
            delay(10);
            lcd.clear();
        }
    }
    if(dosang>100){
        dosang=100;
    }else if(dosang<0){
        dosang=0;
    }
}
void menu3(){
    lcd.setCursor(3,0);
    lcd.print("MENU 3");
    lcd.setCursor(1,1);
    lcd.print("NOI DUNG MENU 3");
}
void menu4(){
    lcd.setCursor(3,0);
    lcd.print("MENU 4");
    lcd.setCursor(1,1);
    lcd.print("NOI DUNG MENU 4");
}
void menu5(){
    lcd.setCursor(3,0);
    lcd.print("MENU 5");
    lcd.setCursor(1,1);
    lcd.print("NOI DUNG MENU 5");
}
void loop(){
    demxoay();
    gtnutchon=digitalRead(nutchon);
    if(gtnutchon==0){
        demchon++;
        if(demchon>4){
            demchon=1;
        }
        delay(200);
        lcd.clear();
    }
    if(demchon==0){
        menumanhinhchinh();
    }else if(demchon==1){
        menutong();
        demtong=demencoder/4;
    }else if(demchon==2){
        if(demtong==0){
            demchon=0;
        }else if(demtong==1){
          demmenu1=demencoder/4;
          if(demmenu1>3){
            demmenu1=0;
          }else if(demmenu1<0){
            demmenu1=3;
          }
          trangthai=1;
            menu1();
        }else if(demtong==2){
            menu2();
            trangthai=2;
        }else if(demtong==3){
            menu3();
            trangthai=3;
        }else if(demtong==4){
            menu4();
            trangthai=4;
        }else if(demtong==5){
            menu5();
            trangthai=5;
        }
        //delay(100);
    }else if(demchon==3&&trangthai==1){
        if(demmenu1==0){
            demchon=1;
        }else if(demmenu1==1){
            lcd.setCursor(3,0);
            lcd.print("MENU 1-A");
            lcd.setCursor(1,1);
            lcd.print("NOI DUNG MENU 1-A");
        }else if(demmenu1==2){
            lcd.setCursor(3,0);
            lcd.print("MENU 1-B");
            lcd.setCursor(1,1);
            lcd.print("NOI DUNG MENU 1-B");
        }else if(demmenu1==3){
            lcd.setCursor(3,0);
            lcd.print("MENU 1-C");
            lcd.setCursor(1,1);
            lcd.print("NOI DUNG MENU 1-C");
        }
    }else if(demchon==4&&trangthai==1){
        demchon=2;
    }else if(demchon==3&&(trangthai==2||trangthai==3||trangthai==4||trangthai==5)){
        demchon=1;
    }
    Serial.print(demchon);
}
