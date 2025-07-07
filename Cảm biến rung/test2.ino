int cambien = 5; //Chân cảm biến nối chân số 5 Arduino
int giatri;

int den = 6; //Đèn nối vào chân số 6 Arduino

void setup() 
{
  Serial.begin(9600);

  pinMode(cambien, INPUT);

  pinMode(den,OUTPUT);
  digitalWrite(den,LOW); //Đèn mặc định là tắt

}

void loop() 
{
  giatri = digitalRead(cambien); //Đọc giá trị digital từ cảm biến và gán vào biến giatri

  if (giatri == 1) //Nếu giá trị đọc từ cảm biến là 1
  {
    Serial.println("Đang rung ");
    digitalWrite(den,HIGH); //Đèn bật
  }
  else
  {
    Serial.println("Không rung");
    digitalWrite(den,LOW); //Đèn tắt
  }

  Serial.print("Giá trị cảm biến là: ");
  Serial.println(giatri);
  Serial.println("  ");
  delay(200);

}
