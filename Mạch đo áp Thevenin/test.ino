
int cambien = A0;
int gtcambien;
float vol_out;
float vol_in;

void setup() 
{
  Serial.begin(9600);

  pinMode(cambien, INPUT);

}

void loop() 
{
  gtcambien = analogRead(cambien);
  Serial.print("Cảm biến: "); Serial.print(gtcambien); Serial.print("   ");
  
  vol_out = (gtcambien * 5) / 1024.0; // Chuyển từ analog sang V; 0-1023 ~ 0-5v
  Serial.print("Volt out: "); Serial.print(vol_out); Serial.print("   ");
  
  vol_in = float(vol_out / float(930.0/float(9860.0 + 930.0))); // Tính vol nguồn cần đo
  Serial.print("Volt nguồn: "); Serial.println(vol_in);
  /*
   * Thevenin Norton
   * 
   * Vth = (Vcc x R2) / R1 + R2
   * Vout = (Vin x R2) / R1 + R2 => Vin = Vout / (R2/(R1+R2));
   */
  
  delay(100);
}
