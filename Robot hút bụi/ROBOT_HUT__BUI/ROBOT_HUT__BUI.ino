 
//int enbA=9;
int in1 = 3;       
int in2 = 5;        
int in3 = 6;        
int in4 = 9;  
//int enbB=10;      

int trig1=10;//cb giữa
int echo1=7;
int trig2=8;//CB trái
int echo2=4;
int trig3=12;//CB phải
int echo3=11;

int tocdoxe;
int kcgiua;
int kctrai;
int kcphai;

unsigned long timer;
void setup() {
  // put your setup code here, to run once:
 // myservo.attach(dongcoservo); 
   
 
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  //pinMode(enbA, OUTPUT);
  //pinMode(enbB, OUTPUT);
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
 // analogWrite(enbA, LOW);
  //analogWrite(enbB, LOW);
  
  Serial.begin(9600);
  pinMode(trig1, OUTPUT);
  pinMode(echo1, INPUT); 
  pinMode(trig2, OUTPUT);
  pinMode(echo2, INPUT); 
  pinMode(trig3, OUTPUT);
  pinMode(echo3, INPUT); 
  tocdoxe=80;

}

void loop()
{
  kcgiua=dokhoangcach(trig1,echo1);
  kctrai=dokhoangcach(trig2,echo2);
  kcphai=dokhoangcach(trig3,echo3);
  Serial.print(kctrai);
  Serial.print("--");
  Serial.print(kcphai);
  Serial.print("--");
  Serial.println(kcgiua);

  if(kcgiua<=8 || kcgiua>1000)
  {
      if(kctrai>8 && kcphai>8)//Di thang vao vat cang
          {if(kctrai>kcphai) //huong nao xa hon di ve huong do
              {dunglai(); delay(300);dilui(tocdoxe); delay(500); disangtraikhongdelay(1000,tocdoxe+10);Serial.println("Di Sang Trai");}
           else if(kctrai<kcphai)//huong nao xa hon di ve huong do
              {dunglai(); delay(300);dilui(tocdoxe); delay(500); disangphaikhongdelay(800,tocdoxe+10);Serial.println("Di Sang Phai");}
           else {dunglai(); delay(300);dilui(tocdoxe); delay(500); disangtraikhongdelay(1000,tocdoxe+10);Serial.println("Di Sang Trai Khi Bang");}
      }
      else if(kctrai>8 && (kcphai<=8|| kcphai>1000))//Huong phia truoc va ben phai bi ket thi lui roi di ve ban trai
        {dunglai(); delay(300);dilui(tocdoxe); delay(500); disangtraikhongdelay(1000,tocdoxe+10);Serial.println("Di Sang Trai");}
      else if((kctrai<=8 || kctrai>1000) && kcphai>8) //Huong phia truoc va ben trai bi ket thi lui roi di ve ban phai
        {dunglai(); delay(300);dilui(tocdoxe); delay(500); disangphaikhongdelay(800,tocdoxe+10);Serial.println("Di Sang Phai");}
      else if((kctrai<=8 || kctrai>1000) && (kcphai<=8 || kcphai>1000)) //Di vao goc tuong thi lui roi quay dau
        {dunglai(); delay(300);dilui(tocdoxe); delay(500); xoaykhongdelay(2000,tocdoxe);Serial.println("Xoay");}
  }
 else
  {
      if(kctrai<=8 && kcphai>8) //Co xu huong va vao tuong ben trai thi re nhe qua phai
          {dunglai(); delay(300);dilui(tocdoxe);delay(500);disangphaikhongdelay(700,tocdoxe+10);Serial.println("Di Lech Sang Phai");}
      else if(kctrai>8 && (kcphai<=8 || kcphai>1000)) //Co xu huong va vao tuong ben phai thi re nhe qua trai
          {dunglai(); delay(300);dilui(tocdoxe);delay(500);disangtraikhongdelay(1000,tocdoxe+10);Serial.println("Di Lech Sang Trai");}
      else if((kctrai<=8 || kctrai>1000) && (kcphai<=8 || kcphai>1000))//di vao duong hep thi lui lai va xoay
          {dunglai(); delay(300);dilui(tocdoxe); delay(500); xoaykhongdelay(2000,tocdoxe); Serial.println("Xoay Khi Vao Dg Hep");}
      else {dithangcheckcb(tocdoxe);Serial.println("Di Thang");} //khong vuon gi thi di thang
  }
 
}

void dithang(int tocdo)
{
  //analogWrite(enbA, tocdo);
  //analogWrite(enbB, tocdo+18);
  analogWrite(in1, 80);
  digitalWrite(in2, 0);
  analogWrite(in3, 80+18);
  digitalWrite(in4, 0);


}
void dunglai(){
  //analogWrite(enbA, 0);
  //analogWrite(enbB, 0);
  digitalWrite(in1, 0);
  digitalWrite(in2, 0);
  digitalWrite(in3, 0);
  digitalWrite(in4, 0);
  }

void disangphai(int tocdo)
{
  //analogWrite(enbA, tocdo+20);
  //analogWrite(enbB, tocdo-10);
  analogWrite(in1, 80+20);
  digitalWrite(in2, 0);
  digitalWrite(in3, 0);
  analogWrite(in4, 80-10);


}
void disangtrai(int tocdo)
{
  //analogWrite(enbA, tocdo-20);
  //analogWrite(enbB, tocdo+40);
  digitalWrite(in1, 0);
  analogWrite(in2, 80-20);
  digitalWrite(in3, 80+40);
  analogWrite(in4, 0);

}

void dilui(int tocdo)
{
  //analogWrite(enbA, tocdo);
  //analogWrite(enbB, tocdo+30);
  digitalWrite(in1, 0);
  analogWrite(in2, 80);
  digitalWrite(in3, 0);
  analogWrite(in4, 80+30);

}

void xoay(int tocdo)
{
  //analogWrite(enbA, tocdo);
  //analogWrite(enbB, tocdo);
  digitalWrite(in1, 0);
  analogWrite(in2, 80);
  analogWrite(in3, 80);
  digitalWrite(in4, 0);
}

///////////////////////////////////////////////
void disangtraikhongdelay(int timedelay, int tocdo)
{
 
  unsigned long starttime=millis();
  while(millis()-starttime<=timedelay && kctrai>8)
      
      {
        disangtrai(tocdo);
        kctrai=dokhoangcach(trig2,echo2);
        
      }
      if(millis()-starttime>=timedelay || kctrai<=8){dunglai();delay(200);}
}

void disangphaikhongdelay(int timedelay, int tocdo)
{
 
  unsigned long starttime=millis();
  while(millis()-starttime<=timedelay && kcphai>8)
      
      {
        disangphai(tocdo);
        kcphai=dokhoangcach(trig3,echo3);
        
      }
      if(millis()-starttime>=timedelay || kcphai<=8){dunglai();delay(200);}
}

void xoaykhongdelay(int timedelay, int tocdo)
{
 
  unsigned long starttime=millis();
  while(millis()-starttime<=timedelay && kctrai>8)
      
      {
        xoay(tocdo);
        kctrai=dokhoangcach(trig2,echo2);
        
      }
      if(millis()-starttime>=timedelay || kctrai<=8){dunglai();delay(200);}
}

void dithangcheckcb(int tocdo)
{
 
  unsigned long starttime=millis();
  while(millis()-starttime<=1200 && kctrai>8 && kcphai>8 && kcgiua>8)
      
      {
        dithang(tocdo);
        kcgiua=dokhoangcach(trig1,echo1);
        kctrai=dokhoangcach(trig2,echo2);
        kcphai=dokhoangcach(trig3,echo3);
        
      }
      if(millis()-starttime>=1200 || kctrai<=8 || kcphai>=8 || kcgiua>=8){dunglai();delay(200);starttime=millis();}
    while(millis()-starttime<=600 && kctrai>8 && kcphai>8 && kcgiua>8)
      
      {
        dilui(tocdo);
        kcgiua=dokhoangcach(trig1,echo1);
        kctrai=dokhoangcach(trig2,echo2);
        kcphai=dokhoangcach(trig3,echo3);
        
      }
      if(millis()-starttime>=600 || kctrai<=8 || kcphai>=8 || kcgiua>=8){dunglai();delay(200);starttime=millis();}
}

//////////////////////////////////////////////

int dokhoangcach(int tri, int ech)
{
  unsigned long thoigian;
  int khoangcach;
  digitalWrite(tri, LOW); 
  delayMicroseconds(2);
  digitalWrite(tri, HIGH);  
  delayMicroseconds(10); 
  digitalWrite(tri, LOW); 
  // Đo độ rộng xung HIGH ở chân echo.
  thoigian = pulseIn(ech, HIGH);
  khoangcach = thoigian / 2 / 29.412;
  return khoangcach;
}
