#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);

int cambien = A0;
int gtcambien;
float vol_out;
float vol_in;

void setup() 
{
  Serial.begin(9600);

  pinMode(cambien, INPUT);

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("DO DIEN AP 0-50V");  
  lcd.setCursor(3,1);
  lcd.print("DC: ");    
}

void loop() 
{
  gtcambien = analogRead(cambien);
  Serial.print("Cảm biến: "); Serial.print(gtcambien); Serial.print("   ");
  
  vol_out = (gtcambien * 5) / 1024.0; // Chuyển từ analog sang V; 0-1024 ~ 0-5v
  Serial.print("Volt out: "); Serial.print(vol_out); Serial.print("   ");
  
  vol_in = float(vol_out / float(930.0/float(9860.0 + 930.0))); // Tính vol nguồn cần đo
  Serial.print("Volt nguồn: "); Serial.println(vol_in);
  /*
   * Thevenin Norton
   * 
   * Vth = (Vcc x R2) / R1 + R2
   * Vout = (Vin x R2) / R1 + R2 => Vin = Vout / (R2/(R1+R2));
   */

  lcd.setCursor(7,1);
  lcd.print(vol_in);
  if (vol_in >= 10)
  {
    lcd.setCursor(12,1);   
    lcd.print("V");
  }
  else
  {
    lcd.setCursor(11,1);   
    lcd.print("V ");    
  }
  
  delay(100);
}
