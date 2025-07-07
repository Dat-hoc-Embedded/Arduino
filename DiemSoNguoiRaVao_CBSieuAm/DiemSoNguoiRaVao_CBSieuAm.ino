const int trig1 = 3;  
const int echo1 = 2;

const int trig2 = 5;  
const int echo2 = 4;

int led = 6;
unsigned long thoigian1;
unsigned long thoigian2; 

int kccb1bandau;
int kccb2bandau;
//int khoangcach;
int khoangcach1;
int khoangcach2;          
//int gioihan = 25;
//int luotvao;
//int luotra;

int songuoitrongphong;
String hangdoi = "";
int timeoutcounter=0;
void setup() {
  // put your setup code here, to run once:
  pinMode(trig1, OUTPUT);
  pinMode(echo1, INPUT); 
  pinMode(trig2, OUTPUT);
  pinMode(echo2, INPUT);
  pinMode(led, OUTPUT);
  Serial.begin(9600);
  songuoitrongphong=0;
  
  delay(500);
  dokhoangcach1();
  kccb1bandau=khoangcach1;
  dokhoangcach2();
  kccb2bandau=khoangcach2;
  Serial.print(kccb1bandau);Serial.print("   ");
  Serial.println(kccb2bandau);
}

void loop() {
  // put your main code here, to run repeatedly:
  khoangcach1 = 0;
  khoangcach2 = 0;
  dokhoangcach1();
  dokhoangcach2();
  //delay(500);
  if(songuoitrongphong==0){digitalWrite(led,LOW);}
  else {digitalWrite(led,HIGH);}
  if(khoangcach1<kccb1bandau - 0 && hangdoi.charAt(0)!='1')
  {
    hangdoi+="1";
  }
  else if(khoangcach2<kccb2bandau - 0 && hangdoi.charAt(0)!='2')
  {
    hangdoi+="2";
  }
  if(hangdoi.equals("12"))
  {
    songuoitrongphong++;
    Serial.print("Hang doi: ");
    Serial.println(hangdoi);
    hangdoi="";
    delay(550);
  }
 else if(hangdoi.equals("21") && songuoitrongphong>0)
 {
    songuoitrongphong--;
    Serial.print("Hang doi: ");
    Serial.println(hangdoi);
    hangdoi="";
    delay(550);
 }
 // Reset hàng đợi nếu giá trị hàng đợi sai (11 hoặc 22) hoặc hết thời gian chờ
  if(hangdoi.length()>2 || hangdoi.equals("11") || hangdoi.equals("22") ||timeoutcounter>200)
  {
      hangdoi="";
  }
  if(hangdoi.length()==1)
  {timeoutcounter++;}
  else {timeoutcounter=0;}

  Serial.print("Hang doi: ");
  Serial.print(hangdoi);
  Serial.print(" CB1: ");
  Serial.print(khoangcach1);
  Serial.print(" CB2: ");
  Serial.print(khoangcach2);
  Serial.print(" So nguoi trong PHONG: ");
  Serial.println(songuoitrongphong);
}
void dokhoangcach1()
{

  digitalWrite(trig1, LOW); 
  delayMicroseconds(2);
  digitalWrite(trig1, HIGH);  
  delayMicroseconds(10); 
  digitalWrite(trig1, LOW);


  // Đo độ rộng xung HIGH ở chân echo.
  thoigian1 = pulseIn(echo1, HIGH);

  khoangcach1 = thoigian1 / 2 / 29.412;

}
void dokhoangcach2()
{

  digitalWrite(trig2, LOW); 
  delayMicroseconds(2);
  digitalWrite(trig2, HIGH);  
  delayMicroseconds(10); 
  digitalWrite(trig2, LOW); 


  // Đo độ rộng xung HIGH ở chân echo.
  thoigian2 = pulseIn(echo2, HIGH);

  khoangcach2 = thoigian2 / 2 / 29.412;

}
