#include <Arduino.h>
#include <EEPROM.h>
#include <SPI.h>
#include <MFRC522.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
#define RST_PIN 9
#define SS_PIN  10
MFRC522 mfrc522(SS_PIN, RST_PIN);
unsigned long UID[4];
unsigned long hientai=0;
int red=6,green=5,blue=3,dem=0;
int nutxuong=7,nutchon=4,nutlen=8;
int gtlen,gtchon,gtxuong;
int gttong=0,gtmas=0;
int demtong=0,demchon=0;
int trangthai=0;
int idmoi[4]={0,0,0,0};
int kiemtra,soluongthe=0; 
int check=0;
void setup(){
   lcd.clear();
   pinMode(red,OUTPUT);pinMode(green,OUTPUT);pinMode(blue,OUTPUT);
  pinMode(nutlen,INPUT_PULLUP);
  pinMode(nutxuong,INPUT_PULLUP);
  pinMode(nutchon,INPUT_PULLUP);
  Serial.begin(9600);
  lcd.begin();
  lcd.backlight();
  SPI.begin();
  mfrc522.PCD_Init();
  soluongthe=EEPROM.read(0);//cap nhap so luong the
  //EEPROM.write(0,0);
  //for(int i=0; i<EEPROM.length(); i++)
   // {
  //EEPROM.write(i,0);
    //  }
}
void showrainbow(){
  for(int i=0;i<768;i++){
      showRGB(i);
      delay(30);
  }
  //do->xanh luc:0->255
  //xanh luc->xanh lam:256-511
  //xanh lam-do:512-767
}
void showRGB(int color){
  int xungdo;
  int xungblue;
  int xunggreen;
  if(color<=255){
    xungdo=255-color;
    xunggreen=color;
    xungblue=0;
  }else if(color<=511){
    xungdo=0;
    xunggreen=255-(color-256);
    xungblue=color-256;
  }else{
    xungdo=color-512;
    xunggreen=0;
    xungblue=255-(color-512);
  }
  analogWrite(red,xungdo);
  analogWrite(green,xunggreen);
  analogWrite(blue,xungblue);
}
void docthe(){
    int diachi=1;
    if(!mfrc522.PICC_IsNewCardPresent()){
      return;
    }
    if(!mfrc522.PICC_ReadCardSerial()){
      return;
    }
    for(byte i=0;i<4;i++){
      UID[i] = mfrc522.uid.uidByte[i];
      EEPROM.write(diachi, UID[i]); //bắt đầu lưu từ ô 1-4
      diachi = diachi + 1;
    }
    mfrc522.PICC_HaltA();  
    mfrc522.PCD_StopCrypto1();
}
bool kiemtracothemaster(){
    docthe();
    for(int i=1;i<=4;i++){
      gtmas=EEPROM.read(i);
      //Serial.print(gtmas);
      gttong=gtmas+gttong;
    }
    if(gttong==0){
      return false;
    }
    return true;

}
void manhinhchuacomaster(){
  lcd.setCursor(2,0);
  lcd.print("SETUP MASTER");
  lcd.setCursor(0,1);
  lcd.print("MOI QUET THE MAS");
}
void manhinhcomaster(){
  lcd.setCursor(2,0);
  lcd.print ("HELLO MASTER");
  lcd.setCursor(0,1);
  lcd.print("MOI QUET THE MAS");
}
int kiemtrathemaster(){   
    if(!mfrc522.PICC_IsNewCardPresent()){
      return ;
    }
    if(!mfrc522.PICC_ReadCardSerial()){
      return ;
    }
    for(byte i=0;i<4;i++){
      idmoi[i] = mfrc522.uid.uidByte[i];
    }
    if(idmoi[0]==EEPROM.read(1)&&idmoi[1]==EEPROM.read(2)&&idmoi[2]==EEPROM.read(3)&&idmoi[3]==EEPROM.read(4)){
      lcd.clear();
      kiemtra=1;
    }else {
      kiemtra=0;
    }
}
void menutong(){
  if(gtlen==0){
      demtong++;
      lcd.clear();
      if(demtong>3){
        demtong=0;
      }
      //delay(100);
  }else if(gtxuong==0){
    demtong--;
    lcd.clear();
    if(demtong<0){
      demtong=3;
    }
    //delay(100);
  }
  if(demtong==0){
    lcd.setCursor(0,0);
    lcd.print(">BACK");
    lcd.setCursor(0,1);
    lcd.print(" THEM THE");
  }else if(demtong==1){
    lcd.setCursor(0,0);
    lcd.print(" BACK");
    lcd.setCursor(0,1);
    lcd.print(">THEM THE");
  }else if(demtong==2){
    lcd.setCursor(0,0);
    lcd.print(">XOA THE BAT KY");
    lcd.setCursor(0,1);
    lcd.print(" XOA TAT CA THE");
  }else if(demtong==3){
    lcd.setCursor(0,0);
    lcd.print(" XOA THE BAT KY");
    lcd.setCursor(0,1);
    lcd.print(">XOA TAT CA THE");
  }

}
void manhinhthemthe(){
  lcd.setCursor(4,0);
  lcd.print("THEM THE");
  lcd.setCursor(0,1);
  lcd.print("MOI QUET THE....");
  if(!mfrc522.PICC_IsNewCardPresent()){
      return;
    }
  if(!mfrc522.PICC_ReadCardSerial()){
      return;
  }
  for(int i=0;i<4;i++){
      UID[i] = mfrc522.uid.uidByte[i];//nhap ma the dang quet vao UID
      Serial.print(UID[i]);Serial.print(" ");    
  }
  mfrc522.PICC_HaltA();  
  mfrc522.PCD_StopCrypto1();

  for(int i=0;i<=soluongthe;i++){
    int k=0;
    int dem=0;
    for(int j=4*i+1;j<=4*i+4;j++){
        if(UID[k]==EEPROM.read(j)){
          dem++;
        }
        k++;
    }
        if(dem==4&&i==0){
          demchon=0;
          lcd.clear();
          return;
        }
        if(dem==4&&i!=0){
            lcd.setCursor(4,0);
            lcd.print("THEM THE");
            lcd.setCursor(0,1);
            lcd.print("THE DA CO....");
            delay(1000);
            return;
        }
    }
  soluongthe+=1;
  Serial.print(soluongthe);
  EEPROM.write(0,soluongthe);
  int k2=0;
  for(int i=4*soluongthe+1;i<=soluongthe*4 +4;i++){
    EEPROM.write(i,UID[k2]);
    k2++;
  }
  lcd.setCursor(4,0);
  lcd.print("THEM THE");
  lcd.setCursor(0,1);
  lcd.print("...DA THEM THE...");
  delay(1000);
}
void xoa1the(int k){
    for(int i=k;i<=soluongthe;i++){
      int j=i+1;
      int m1=4*i+1;
      int m2=4*j+1;
        for(int p=m1,t=m2;p<=m1+3,t<=m2+3;p++,t++){
              EEPROM.write(p,EEPROM.read(t));
        }
    }
    soluongthe--;
}
void manhinhxoathebatki(){
  lcd.setCursor(4,0);
  lcd.print("XOA THE");
  lcd.setCursor(0,1);
  lcd.print("MOI QUET THE...");

  if(!mfrc522.PICC_IsNewCardPresent()){
      return;
    }
  if(!mfrc522.PICC_ReadCardSerial()){
      return;
  }
  for(int i=0;i<4;i++){
      UID[i] = mfrc522.uid.uidByte[i];//nhap ma the dang quet vao UID
      Serial.print(UID[i]);Serial.print(" ");    
  }
  mfrc522.PICC_HaltA();  
  mfrc522.PCD_StopCrypto1();

  for(int i=0;i<=soluongthe;i++){
    int k=0;int dem=0;
    for(int j=4*i+1;j<=4*i+4;j++){
      if(UID[k]==EEPROM.read(j)){
        dem++;
      }
      k++;
    }
      if(dem==4&&i==0){
        demchon=0;
        lcd.clear();
        return;
      }
      Serial.print("dem");Serial.println(dem);
      if(dem==4){
          xoa1the(i);
          lcd.setCursor(4,0);
          lcd.print("XOA THE");
          lcd.setCursor(0,1);
          lcd.print("DA XOA THE...");
          delay(1000);
      }
      if(dem!=4&&i!=0){
        if(soluongthe!=0){
          lcd.setCursor(4,0);
          lcd.print("XOA THE");
          lcd.setCursor(0,1);
          lcd.print("KHONG DUNG THE...");
          delay(1000);
          }
      }
         if(soluongthe==0){
          lcd.setCursor(4,0);
          lcd.print("XOA THE");
          lcd.setCursor(0,1);
          lcd.print("CHUA CO THE...");
          delay(1000);
      }
    }
}
void manhinhxoatatca(){
  lcd.setCursor(1,0);
  lcd.print("XOA TAT CA THE");
  lcd.setCursor(0,1);
  lcd.print("QUET THE MAS....");

  if(!mfrc522.PICC_IsNewCardPresent()){
      return;
    }
  if(!mfrc522.PICC_ReadCardSerial()){
      return;
  }
  for(int i=0;i<4;i++){
      UID[i] = mfrc522.uid.uidByte[i];//nhap ma the dang quet vao UID
      Serial.print(UID[i]);Serial.print(" ");    
  }
  mfrc522.PICC_HaltA();  
  mfrc522.PCD_StopCrypto1();
  int dem=0;
  for(int i=0;i<4;i++){
    if(UID[i]==EEPROM.read(i+1)){
      dem++;
    }
  }
  Serial.println(dem);
  if(dem==4){
    for(int i=5;i<=4*soluongthe+8;i++){
      EEPROM.write(i,0);
    }
      soluongthe=0;
      lcd.clear();
      lcd.setCursor(1,0);
      lcd.print("XOA TAT CA THE");
      lcd.setCursor(1,1);
      lcd.print("....DA XONG....");
      demchon=0;
      delay(1000);
  }else{
      Serial.print("hihi");
      lcd.clear();
      lcd.setCursor(1,0);
      lcd.print("XOA TAT CA THE");
      lcd.setCursor(0,1);
      lcd.print("SAI THE MAS...");
      delay(1000);
      lcd.clear();
  }
}
void cauvong(){
  dem++;
  delay(200);
  if(dem%2!=0){
    lcd.clear();
    lcd.setCursor(2,0);
    lcd.print("HELLO MASTER");
    lcd.setCursor(0,1);
    lcd.print("...BAT DEN...");
    delay(1000);
    showrainbow();
    lcd.clear();
  }else{
    lcd.clear();
    lcd.setCursor(2,0);
    lcd.print("HELLO MASTER");
    lcd.setCursor(0,1);
    lcd.print("...TAT DEN...");
    delay(1000);
    lcd.clear();
    digitalWrite(red,LOW); digitalWrite(green,LOW); digitalWrite(blue,LOW);
  }
}
void loop(){
  gtlen=digitalRead(nutlen);
  gtxuong=digitalRead(nutxuong);
  gtchon=digitalRead(nutchon);
      Serial.print("soluongthe");Serial.println(soluongthe);
      Serial.print(EEPROM.read(1));
  if(trangthai==0){
    if(kiemtracothemaster()==false){
      manhinhchuacomaster();
    }else{
      trangthai=2;
    }
  }
  if(trangthai==2){
      kiemtra=0;
      idmoi[0]=0;
      demchon=0;
      manhinhcomaster();
      if(!mfrc522.PICC_IsNewCardPresent()){
      return ;
    }
    if(!mfrc522.PICC_ReadCardSerial()){
      return ;
    }
    for(byte i=0;i<4;i++){
      idmoi[i] = mfrc522.uid.uidByte[i];
    }
    for(int i=1;i<=soluongthe;i++){
      int dem=0;
      int k=0;
      for(int j=4*i+1;j<=4*i+4;j++){
        if(idmoi[k]==EEPROM[j]){
          dem++;
          //Serial.print("dem");Serial.println(dem);
          //Serial.println(idmoi[k]);
        }
        k++;
      }
      if(dem==4){
        cauvong();
       return;
       
      }
    }
    if(idmoi[0]==EEPROM.read(1)&&idmoi[1]==EEPROM.read(2)&&idmoi[2]==EEPROM.read(3)&&idmoi[3]==EEPROM.read(4)){
      lcd.clear();
      kiemtra=1;
    }else {
      kiemtra=0;
    }
      if(kiemtra==1){
        trangthai=1;
      }else{
        lcd.clear();
        lcd.setCursor(1,0);
        lcd.print("HELLO MASTER");
        lcd.setCursor(0,1);
        lcd.print("SAI THE MASTER...");
        delay(1000);
        lcd.clear();
      }
  }
  if(trangthai==1){
      if(gtchon==0){
        demchon++;
        if(demchon==2){
          demchon=1;
        }
        lcd.clear();
      }
      if(demchon==0){
        menutong();
      }else if(demchon==1){
        if(demtong==0){
            trangthai=0;
        }else if(demtong==1){
            //lcd.clear();
            manhinhthemthe();
        }else if (demtong==2){
            manhinhxoathebatki();
        }else if(demtong==3){
          manhinhxoatatca();
        }
      }
       delay(100);
  }                  
}
  
