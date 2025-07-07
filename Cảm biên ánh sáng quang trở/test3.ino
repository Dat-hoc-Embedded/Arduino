int cambien = A0; //Cảm biến nối chân số 5 Arduino
int giatri;

int den = 8; //Khai báo chân đèn nối với chân số 8 trên Arduino

void setup() 
{
  Serial.begin(9600);

  pinMode(den, OUTPUT); 
  digitalWrite(den, LOW); //Mặc định đèn tắt
  pinMode(cambien, INPUT); //Cảm biến nhận tín hiệu

}

void loop() 
{
  giatri = analogRead(cambien); //Đọc giá trị analog của cảm biến và gán vào biến giatri

  if (giatri > 1000) //Nếu giá trị quang trở lớn hơn 1000
  {
    digitalWrite(den, HIGH); //Đèn sáng
  }
  else //Ngược lại
  {
    digitalWrite(den, LOW); //Đèn tắt
  }
  
  Serial.print("Giá trị cảm biến: ");
  Serial.println(giatri);
  delay(200);

}
