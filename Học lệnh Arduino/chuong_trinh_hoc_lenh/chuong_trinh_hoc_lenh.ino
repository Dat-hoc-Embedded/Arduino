#include <Servo.h>
#include <EEPROM.h>
#include <Arduino.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
Servo servo1;
int servo =7;
int diachi1=1;
int diachi2=1;
int diachi3=1;
int diachi4=1;
byte giatri;//int tu 0-255;
byte tong;
int nutset=3,nutchon=4,nutchay=5;
int phaA=8,phaB=9;int phaAlast=LOW;int n=LOW;int demencoder=0;//khai bao bien chay encoder
int gtset,gtchon,gtchay;
int demset=0,demchon=0,demchay=0;
int demtong=0;
int bientro=A0;int gtbientro;int gtbiendoi;
int trangthai=0;

unsigned long thoigian;
void setup(){
    Serial.begin(9600);
    pinMode(nutchon,INPUT_PULLUP);
    pinMode(nutchay,INPUT_PULLUP);
    pinMode(nutset,INPUT_PULLUP);
    pinMode(bientro,INPUT);
    servo1.attach(servo);
    servo1.write(0);

    pinMode(phaA,INPUT);
    pinMode(phaB,INPUT);
    
    lcd.begin();
    lcd.backlight();
    lcd.clear();
    thoigian=millis();
    diachi3=EEPROM.read(0)+1;
    diachi4=EEPROM.read(0)+1;
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
    phaAlast=n;
}
void manhinhchinh(){
    lcd.setCursor(2,0);
    lcd.print("CHUONG TRINH");
    lcd.setCursor(1,1);
    lcd.print("ROBOT HOC LENH");
}
void menutong(){
    if(demencoder>18){
        demencoder=0;
    }else if(demencoder<0){
        demencoder=18;
    }
    demtong=demencoder/5;
    if(demtong==0){
        lcd.setCursor(0,0);
        lcd.print(">BACK");
        lcd.setCursor(0,1);
        lcd.print(" LENH 1");
    }else if(demtong==1){
        lcd.setCursor(0,0);
        lcd.print(" BACK");
        lcd.setCursor(0,1);
        lcd.print(">LENH 1");
    }else if(demtong==2){
        lcd.setCursor(0,0);
        lcd.print(">LENH 2");
        lcd.setCursor(0,1);
        lcd.print(" XOA LENH");
    }else if(demtong==3){
        lcd.setCursor(0,0);
        lcd.print(" LENH 2");
        lcd.setCursor(0,1);
        lcd.print(">XOA LENH");
    }
}
void menuhoclenh1(){
    if(gtchay==0){
        demchay++;
        if(demchay>1){
            demchay=0;
        }
        delay(200);
    }
    //hoc lenh 1
    if(demchay==0){
        diachi2=1;//khoi tao lai dia chi 2
        lcd.setCursor(5,0);
        lcd.print("LENH 1");
        lcd.setCursor(0,1);
        lcd.print(".DANG HOC LENH..");

        tong=EEPROM.read(0);
        gtbientro=analogRead(bientro);
        gtbiendoi=map(gtbientro,0,1023,0,180);
        servo1.write(gtbiendoi);
        if(gtset==0){
            demset++;
            if(demset>0){
                EEPROM.write(diachi1,gtbiendoi);
                Serial.print("           "); 
              Serial.print("Địa chỉ 1: "); Serial.print(diachi1); Serial.print("   ");
              Serial.print("Góc Servo: "); Serial.println(gtbiendoi);
                delay(50);
                diachi1=diachi1+1; 
                EEPROM.write(0,diachi1);
                delay(50);
                if(diachi1==EEPROM.length()){
                    diachi1=0;
                }
                demset=0;
                lcd.setCursor(5,0);
                lcd.print("LENH 1");
                lcd.setCursor(1,1);
                lcd.print("...DANG LUU...");
                delay(500);
            }
            delay(100);
        }
    }
    //chay lenh 1
    if(demchay==1){
        if(tong==0){
            lcd.setCursor(5,0);
            lcd.print("LENH 1");
            lcd.setCursor(0,1);
            lcd.print("CHUA HOC LENH");
            demchay=0;
            delay(2000);
            return;
        }
        diachi1=tong;
        if(diachi2<diachi1){
            lcd.setCursor(5,0);
            lcd.print("LENH 1");
            lcd.setCursor(0,1);
            lcd.print(".DANG CHAY LENH.");
            giatri=EEPROM.read(diachi2);
            if(millis()-thoigian>3000){
                thoigian=millis();
                Serial.print("           "); 
                Serial.print("Địa chỉ 2: "); Serial.print(diachi2); Serial.print("   "); 
                Serial.print("Góc Servo: "); Serial.println(giatri); 
                diachi2++;
                servo1.write(giatri);
            }
            delay(50);
        }else{
            diachi2=1;
        }
    }
}
void menuhoclenh2(){
    if(gtchay==0){
        demchay++;
        if(demchay>1){
            demchay=0;
        }
        delay(200);
    }
    if(demchay==0){
        lcd.setCursor(5,0);
        lcd.print("LENH 2");
        lcd.setCursor(0,1);
        lcd.print(".DANG HOC LENH..");
        gtbientro=analogRead(bientro);
        gtbiendoi=map(gtbientro,0,1023,0,180);
        servo1.write(gtbiendoi);
        if(gtset==0){
            demset++;
            if(demset>0){
                EEPROM.write(diachi3,gtbiendoi);
                Serial.print("           "); 
              Serial.print("Địa chỉ 3: "); Serial.print(diachi3); Serial.print("   ");
              Serial.print("Góc Servo: "); Serial.println(gtbiendoi);
                delay(50);
                diachi3=diachi3+1;
                if(diachi3==EEPROM.length()){
                    diachi3=0;
                }
                demset=0;
                lcd.setCursor(5,0);
                lcd.print("LENH 2");
                lcd.setCursor(1,1);
                lcd.print("...DANG LUU...");
                delay(500);
            }
            delay(100);
        }
    }
    if(demchay==1){
        if(diachi4<diachi3){
            lcd.setCursor(5,0);
            lcd.print("LENH 2");
            lcd.setCursor(0,1);
            lcd.print(".DANG CHAY LENH.");
            giatri=EEPROM.read(diachi4);
            if(millis()-thoigian>3000){
                thoigian=millis();
                Serial.print("           "); 
                Serial.print("Địa chỉ 4: "); Serial.print(diachi4); Serial.print("   "); 
                Serial.print("Góc Servo: "); Serial.println(giatri); 
                servo1.write(giatri);
                diachi4++;
            }
            delay(50);
        }else{
            diachi4=EEPROM.read(0)+1;
        }
    }
}
void xoalenh(){
    int tam=EEPROM.read(0);
    for(int i=0;i<tam;i++){
        EEPROM.write(i,0);
    }
    lcd.setCursor(4,0);
    lcd.print("XOA LENH");
    lcd.setCursor(0,1);
    lcd.print("...DA XOA LENH...");
    delay(2000);
    demchon=1;
}
void loop(){
    demxoay();
    gtchon=digitalRead(nutchon);
    gtchay=digitalRead(nutchay);
    gtset=digitalRead(nutset);
    if(gtchon==0){
        demchon++;
        if(demchon>3){
            demchon=0;
        }
        lcd.clear();
        delay(200);
    }
    if(demchon==0){
        manhinhchinh();
    }else if(demchon==1){
        menutong();
    }else if(demchon==2){
        if(demtong==0){
            demchon=0;
        }else if(demtong==1){
            menuhoclenh1();
            trangthai=1;
        }else if(demtong==2){
            menuhoclenh2();
            trangthai=2;
        }else if(demtong==3){
            xoalenh();
            trangthai=3;
        }
    }else if(demchon==3&&(trangthai==1||trangthai==2)){
        demchon=1;
        demchay=0;
        demset=0;
    }
    //Serial.println(gtbiendoi);
    //Serial.println(demchon);
}
