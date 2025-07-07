#include <LiquidCrystal_I2C.h>
#include <Wire.h> //Gọi thư viện I2C để sử dụng các thư viện I2C
LiquidCrystal_I2C lcd(0x27,16,2); //Khai báo địa chỉ I2C (0x27 or 0x3F) và LCD 16x02

int cambien=3;int giatri;int dem=0;
void setup() {
  // put your setup code here, to run once:
  lcd.begin();
  lcd.backlight();
  Serial.begin(9600);
  pinMode(cambien,INPUT);
    int reset=8;
  pinMode(reset,INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  giatri=digitalRead(cambien);
  
  
  if(giatri==0){
    dem++;
    delay(300);
 }

  manhinhhienthi();
}
void manhinhhienthi(){
  lcd.setCursor(2,0);
  lcd.print("MAY DEM TRUNG");
  lcd.setCursor(0,1);
  lcd.print("SO LUONG: ");
  lcd.print(dem);

}