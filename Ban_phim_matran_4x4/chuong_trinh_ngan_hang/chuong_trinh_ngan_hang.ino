#include <Arduino.h>
#include <Keypad.h>
#include <EEPROM.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns

char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {9, 8, 7, 6}; //{R1,R2,R3,R4}
byte colPins[COLS] = {5, 4, 3, 2}; //{C1,C2,C3,C4}
int coi=10;
int nutxuong=11,nutchon=12,nutlen=13;
int gtlen,gtchon,gtxuong;
int demtong=0,demchon=0,demlogin=-1,demdichvu=0,demchondichvu=0,demchuyentien=-1,demnaptien=-1;
int trangthai=0,trangthailogin=0,trangthaidichvu=0;
int demid=0;char id[100]={0};
int demmk=0;char mk[100]={0};
int demidchuyen=0;char idchuyen[100]={0};
int cot=0,hang=0;
int sodu=0,vimomo=0;
int naptien=0,napvi=0;
int tienchuyen;
char mkdung[]={'3','0','1','0','2','0','0','3'};
//Create an object of keypad
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
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
byte eye[] = {
  B00000,
  B00000,
  B01110,
  B10101,
  B10101,
  B01110,
  B00000,
  B00000
};
byte login[] = {
  B00000,
  B10000,
  B10100,
  B10110,
  B11111,
  B00110,
  B00100,
  B00000
};
void setup(){
  Serial.begin(9600);
    lcd.begin();
    lcd.backlight();
    lcd.clear();
    lcd.createChar(0,login);
    lcd.createChar(1,tick);
    lcd.createChar(2,eye);
    pinMode(nutlen,INPUT_PULLUP);
    pinMode(nutchon,INPUT_PULLUP);
    pinMode(nutxuong,INPUT_PULLUP);
}
void manhinhkhoitao(){
    char key = keypad.getKey();
    lcd.setCursor(0,0);
    lcd.print("BIDV WELCOME ^_^");
    lcd.setCursor(1,1);
    lcd.print("PRESS 0:");lcd.print("LOGIN");
    if(key){
        if(key=='0'){
            lcd.clear();
            trangthai=1;
        }
    }
}
void nhapma(char id[], int &dem){
    char key=keypad.getKey();
    if(key){
        tone(coi,3000,200);
        id[dem]=key;
        dem++;
    }
}
void menutong(){
    lcd.noCursor();
    if(gtlen==0){
        demtong++;
        lcd.clear();
        if(demtong>3){
            demtong=0;
        }
    }else if (gtxuong==0){
        demtong--;
        lcd.clear();
        if(demtong<0){
            demtong=3;
        }
    }
    if(demtong==0){
        lcd.setCursor(0,0);
        lcd.print(">BACK");
        lcd.setCursor(0,1);
        lcd.print(" LOGIN");
    }else if(demtong==1){
        lcd.setCursor(0,0);
        lcd.print(" BACK");
        lcd.setCursor(0,1);
        lcd.print(">LOGIN");
    }else if(demtong==2){
        lcd.setCursor(0,0);
        lcd.print(">SUPPORT");
        lcd.setCursor(0,1);
        lcd.print(" CREAT ACCOUNT");
    }else if(demtong==3){
        lcd.setCursor(0,0);
        lcd.print(" SUPPORT");
        lcd.setCursor(0,1);
        lcd.print(">CREAT ACCOUNT");
    }

}
void manhinhcheck(){
    lcd.setCursor(0,0);
    lcd.print("SO DU BIDV:");lcd.print(sodu);
    lcd.setCursor(0,1);
    lcd.print("VI MOMO:");lcd.print(vimomo);
    char key=keypad.getKey();
    if(key){
        tone(coi,3000,200);
        if(key=='A'){
            demchondichvu=0;
        }
    }
}
void manhinhchuyentien(){
    lcd.setCursor(0,0);
    lcd.print("ID:");
    lcd.setCursor(15,0);lcd.print("x");
    lcd.setCursor(0,1);
    lcd.print("SO TIEN:");lcd.print(tienchuyen);
    lcd.setCursor(14,1);lcd.write(byte(2));lcd.write(byte(0));
    lcd.cursor();
    lcd.setCursor(cot,hang);
    if(gtchon==0){
        delay(200);
        demchuyentien++;
    }
    if(demchuyentien==0){
        if(gtxuong==0){
            cot--;
            if(cot<0){
                cot=15;
                if(hang==0){
                    hang=1;
                }else{hang=0;}
            }
        }else if(gtlen==0){
            cot++;
            if(cot>15){
                cot=0;
                if(hang==0){
                    hang=1;
                }else {hang=0;}
            }
        }
    }else if(demchuyentien==1){
        if(hang==0&&cot==15){
            if(demidchuyen==0&&tienchuyen==0){
                lcd.clear();
                demchondichvu=0;
                trangthaidichvu=0;
                return;
            }
            for(int i=0;i<demidchuyen;i++){
                id[i]=0;
                demidchuyen=0;
            }
            tienchuyen=0;
            lcd.clear();
            demchuyentien=0;
        }
        if(hang==1&&cot==15){
            sodu=sodu-tienchuyen;
            lcd.clear();
            lcd.setCursor(2,0);
            lcd.print("---STATUS---");
            lcd.setCursor(4,1);
            lcd.print("SUCCESS");
            delay(2000);
            lcd.clear();
            demchondichvu=0;
            trangthaidichvu=0;
        }
        if(hang==0&&cot!=15){
            nhapma(idchuyen,demidchuyen);
        }
        if(hang==1&&cot!=15&&cot!=14){
            if(gtlen==0){
                tienchuyen+=1000;
            }else if(gtxuong==0){
                tienchuyen-=1000;
                if(tienchuyen<0){
                    tienchuyen=0;
                }
            }
        }
        for(int i=0;i<demidchuyen;i++){
            lcd.setCursor(i+3,0);
            lcd.print(idchuyen[i]);
        }
        
    }else if(demchuyentien==2){
        demchuyentien=0;
    }
}
void manhinhnaptien(){
    lcd.setCursor(0,0);
    lcd.print("BIDV:");lcd.print(naptien);
    lcd.setCursor(15,0);lcd.print("x");
    lcd.setCursor(0,1);
    lcd.print("MOMO:");lcd.print(napvi);
    lcd.setCursor(15,1);lcd.write(byte(0));
    lcd.cursor();
    lcd.setCursor(cot,hang);
    if(gtchon==0){
        delay(200);
        demnaptien++;
    }
    if(demnaptien==0){
        if(gtxuong==0){
            cot--;
            if(cot<0){
                cot=15;
                if(hang==0){
                    hang=1;
                }else{hang=0;}
            }
        }else if(gtlen==0){
            cot++;
            if(cot>15){
                cot=0;
                if(hang==0){
                    hang=1;
                }else {hang=0;}
            }
        }
    }else if(demnaptien==1){
        if(hang==0&&cot==15){
            if(naptien==0&&napvi==0){
                lcd.clear();
                demchondichvu=0;
                trangthaidichvu=0;
                return;
            }
            naptien=0;
            napvi=0;
            lcd.clear();
            demnaptien=0;
        }
        if(hang==1&&cot==15){
            sodu+=naptien;
            vimomo+=napvi;
            lcd.clear();
            lcd.setCursor(2,0);
            lcd.print("---STATUS---");
            lcd.setCursor(4,1);
            lcd.print("SUCCESS");
            delay(2000);
            lcd.clear();
            demchondichvu=0;
            trangthaidichvu=0;
        }
        if(hang==0&&cot!=15){
            if(gtlen==0){
                naptien+=1000;
            }else if(gtxuong==0){
                naptien-=1000;
                if(naptien<0){
                    naptien=0;
                }
            }
        }
        if(hang==1&&cot!=15){
            if(gtlen==0){
                napvi+=1000;
            }else if(gtxuong==0){
                napvi-=1000;
                if(napvi<0){
                    napvi=0;
                }
            }
        }
    }else if(demnaptien==2){
        demnaptien=0;
    }
}
void manhinhdangxuat(){
    lcd.setCursor(1,0);
    lcd.print("ARE YOU SURE?");
    lcd.setCursor(2,1);
    lcd.print("1:YES");
    lcd.setCursor(8,1);
    lcd.print("0:NO");
    char key=keypad.getKey();
    if(key){
        lcd.clear();
        tone(coi,3000,200);
        if(key=='1'){
            demid=0;
            demmk=0;
            trangthai=1;
            demchon=0;
            trangthailogin=0;
            demlogin=-1;
            demchondichvu=0;
            trangthaidichvu=0;
        }else if(key=='0'){
            demchondichvu=0;
            trangthaidichvu=0;
        }
    }
}
void manhinhdichvu(){
  lcd.noCursor();
  if(gtchon==0&&trangthaidichvu==0){
    demchondichvu++;
    delay(200);
    lcd.clear();
  }
    if(gtxuong==0&&trangthaidichvu==0){
        demdichvu--;
        lcd.clear();
        if(demdichvu<0){
            demdichvu=3;
        }
    }else if(gtlen==0&&trangthaidichvu==0){
        demdichvu++;
        lcd.clear();
        if(demdichvu>3){
            demdichvu=0;
        }
    }
    if(demchondichvu==0){
        if(demdichvu==0){
            lcd.setCursor(0,0);
            lcd.print(">CHECK ACCOUNT");
            lcd.setCursor(0,1);
            lcd.print(" SEND MONEY");
        }else if(demdichvu==1){
            lcd.setCursor(0,0);
            lcd.print(" CHECK ACCOUNT");
            lcd.setCursor(0,1);
            lcd.print(">SEND MONEY");
        }else if(demdichvu==2){
            lcd.setCursor(0,0);
            lcd.print(">ADD MONEY");
            lcd.setCursor(0,1);
            lcd.print(" LOGOUT");
        }else if(demdichvu==3){
            lcd.setCursor(0,0);
            lcd.print(" ADD MONEY");
            lcd.setCursor(0,1);
            lcd.print(">LOGOUT");
        }
    }else if(demchondichvu==1){
        if(demdichvu==0){
            manhinhcheck();
        }else if(demdichvu==1){
            trangthaidichvu=1;
            manhinhchuyentien();
        }else if(demdichvu==2){
            trangthaidichvu=2;
            manhinhnaptien();
        }else{
            trangthaidichvu=3;
            manhinhdangxuat();
        }
    }
    //Serial.print("demchondichvu");Serial.println(demchondichvu);
   // Serial.print(trangthaidichvu);
}
int sosanh2mang(){
    if(demmk!=8){
        return 1;
    }
    return strcmp(mkdung,mk);
}
void manhinhlogin(){
    if(trangthailogin==0){
        lcd.setCursor(0,0);
        lcd.print("ID:");
        lcd.setCursor(15,0);lcd.print("x");
        lcd.setCursor(0,1);
        lcd.print("PASS:");
        lcd.setCursor(14,1);lcd.write(byte(2));lcd.write(byte(0));
        lcd.cursor();
        lcd.setCursor(cot,hang);
        if(gtchon==0){
            delay(100);
            demlogin++;
        }
        if(demlogin==0){
            if(gtxuong==0){
                cot--;
                if(cot<0){
                    cot=15;
                    if(hang==0){
                        hang=1;
                    }else{hang=0;}
                }
            }else if(gtlen==0){
                cot++;
                if(cot>15){
                    cot=0;
                    if(hang==0){
                        hang=1;
                    }else {hang=0;}
                }
            }
        }else if(demlogin==1){
            if(hang==0&&cot==15){
                if(demid==0&&demmk==0){
                    lcd.clear();
                    demlogin=-1;
                    trangthai=1;
                    demchon=0;
                    return;
                }
                for(int i=0;i<demid;i++){
                    id[i]=0;
                    demid=0;
                }
                for(int i=0;i<demmk;i++){
                    mk[i]=0;
                    demmk=0;
                }
                lcd.clear();
                demlogin=0;
            }
            if(hang==1&&cot==15){
                  if(sosanh2mang()==255){
                  lcd.clear();
                  lcd.setCursor(1,0);
                  lcd.print("CHOOSE SERVICE");
                  lcd.setCursor(0,1);
                  lcd.print("...AUTO NEXT...");
                    delay(2000);
                  lcd.clear();
                  demlogin=0;
                  trangthailogin=1;
                  return;
                }else{
                  lcd.clear();
                  lcd.setCursor(2,0);
                  lcd.print("--ERROR 102--");
                  lcd.setCursor(0,1);
                  lcd.print("..PASS INCORRECT..");
                  delay(2000);
                  lcd.clear();
                  hang=0;
                }
            }
            if(hang==1&&cot==14){
                for(int i=0;i<demmk;i++){
                    lcd.setCursor(i+5,1);
                    lcd.print(mk[i]);
                }
                delay(500);
                demlogin=0;
            }
            if(hang==0&&cot!=15){
                nhapma(id,demid);
            }
            if(hang==1&&cot!=15&&cot!=14){
                nhapma(mk,demmk);
            }

            for(int i=0;i<demid;i++){
                lcd.setCursor(i+3,0);
                lcd.print(id[i]);
            }
            for(int i=0;i<demmk;i++){
                lcd.setCursor(i+5,1);
                lcd.print(mk[i]);
                lcd.setCursor(i+5,1);
                lcd.print("*");
            }
        }else if(demlogin==2){
            demlogin=0;
        }
    }else if(trangthailogin==1){
        manhinhdichvu();
    }
}
void manhinhsupport(){
    lcd.setCursor(1,0);
    lcd.print("BIDV KINH CHAO");
    lcd.setCursor(1,1);
    lcd.print("SDT: 09432176");
    char key=keypad.getKey();
    if(key){
      lcd.clear();
        tone(coi,3000,200);
        if(key=='A'){
            trangthai=1;
            demchon=0;

        }
    }
}
void manhinhtaotk(){
    lcd.setCursor(3,0);
    lcd.print("TINH NANG");
    lcd.setCursor(2,1);
    lcd.print("DANG BAO TRI");
    char key=keypad.getKey();
    if(key){
        tone(coi,3000,200);
        if(key=='A'){
            trangthai=1;
            demchon=0;

        }
        lcd.clear();
    }
}
void loop(){
    gtlen=digitalRead(nutlen);
    gtxuong=digitalRead(nutxuong);
    gtchon=digitalRead(nutchon); 
    
    if(trangthai==0){
        demchon=0;
        manhinhkhoitao();
    }
    if(trangthai==1){
       menutong();
      if(gtchon==0){
        demchon++;
        lcd.clear();
      }
       delay(100);
    }
    if(demchon==1){
        if(demtong==0){
            trangthai=0;
        }else if(demtong==1){
            trangthai=2;
            manhinhlogin();
        }else if(demtong==2){
            trangthai=3;
            manhinhsupport();
        }else if(demtong==3){
            trangthai=4;
            manhinhtaotk();
        }
        delay(100);
    }
    Serial.print("demchon");Serial.println(demchon);
    //Serial.print("demlogin");Serial.println(demlogin);
    //Serial.print("trangthai");Serial.println(trangthai);
}
