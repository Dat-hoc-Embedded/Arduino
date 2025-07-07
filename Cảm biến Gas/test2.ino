int cambien = A0; //Cảm biến nối chân số 5 Arduino
int giatri;

void setup() 
{
  Serial.begin(9600);

  pinMode(cambien, INPUT); //Cảm biến nhận tín hiệu

}

void loop() 
{
  giatri = analogRead(cambien); //Đọc giá trị cảm biến và gán vào biến giatri
  Serial.print("Giá trị cảm biến: ");
  Serial.println(giatri);
  delay(200);

}
