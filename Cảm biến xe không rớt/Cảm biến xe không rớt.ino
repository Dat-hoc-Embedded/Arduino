
int cbsau=2;
int cbtrai=13;
int cbphai=12;
  
int enbA=3;
int in1 = 5;       
int in2 = 6;        
int in3 = 9;        
int in4 = 10;  
int enbB=11;      

int maxspeed=30;

  int gtcbtrai;
  int gtcbphai;
  int gtcbsau;
  
void dithang(int duongdi);
void disangtrai();
void disangphai();
void dilui();
void resetdongco();
void quaycbsangphai();
void quaycbsangtrai();
void setup() {
  // put your setup code here, to run once:
 // myservo.attach(dongcoservo); 
   
  pinMode(cbsau,INPUT);
  pinMode(cbtrai,INPUT);
  pinMode(cbphai,INPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(enbA, OUTPUT);
  pinMode(enbB, OUTPUT);
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  digitalWrite(enbA, LOW);
  digitalWrite(enbB, LOW);
  
  Serial.begin(9600);


}

void loop()
{
  gtcbtrai=digitalRead(cbtrai);
  gtcbphai=digitalRead(cbphai);
  gtcbsau=digitalRead(cbsau);
//====================================
  if(gtcbtrai==0 && gtcbphai==0)
  {
    dithang();
  }
  else if(gtcbtrai!=0 && gtcbphai==0)
  {
    delaylui();
    delayphai();
  }
  else if(gtcbphai!=0 && gtcbtrai==0)
  {
    delaylui();
    delaytrai();  
  }
  else 
  {
    delaylui();
    delaytrai();  
  }
  

}
void delaylui()//lùi có kiểm tra cảm biến sau
{ int starttime=millis();
  
  while(millis() - starttime<=300 && gtcbsau!=1)
      
      {
        dilui();
        gtcbsau=digitalRead(cbsau);
        
      }
   dunglai();
   delay(500);
}

void delaytrai()
{
 
  int starttime=millis();
  while(millis()-starttime<=500 && gtcbtrai!=1)
      
      {
        disangtrai();
        gtcbtrai=digitalRead(cbtrai);
        
      }
      if(millis()-starttime>=500 || gtcbtrai==1){dunglai();delay(500);}
}

void delayphai()
{
  
  int starttime=millis();
  while(millis()-starttime<=500 && gtcbphai!=1)
      
      {
        disangphai();
        gtcbphai=digitalRead(cbphai);
        
      }
      if(millis()-starttime>=500 || gtcbphai==1)
      {dunglai();delay(500);}
}
void dithang()
{
  analogWrite(enbA, 70);
  analogWrite(enbB, 70);
  digitalWrite(in1, 0);
  digitalWrite(in2, 1);
  digitalWrite(in3, 0);
  digitalWrite(in4, 1);


}
void dunglai(){
  analogWrite(enbA, 0);
  analogWrite(enbB, 0);
  digitalWrite(in1, 0);
  digitalWrite(in2, 0);
  digitalWrite(in3, 0);
  digitalWrite(in4, 0);
  }

void disangphai()
{
  analogWrite(enbA, 80);
  analogWrite(enbB, 0);
  digitalWrite(in1, 0);
  digitalWrite(in2, 1);
  digitalWrite(in3, 0);
  digitalWrite(in4, 0);


}
void disangtrai()
{
  analogWrite(enbA, 0);
  analogWrite(enbB, 80);
  digitalWrite(in1, 0);
  digitalWrite(in2, 0);
  digitalWrite(in3, 0);
  digitalWrite(in4, 1);

}

void dilui()
{
  analogWrite(enbA, 80);
  analogWrite(enbB, 80);
  digitalWrite(in1, 1);
  digitalWrite(in2, 0);
  digitalWrite(in3, 1);
  digitalWrite(in4, 0);

}

void xoay()
{
  analogWrite(enbA, 80);
  analogWrite(enbB, 80);
  digitalWrite(in1, 0);
  digitalWrite(in2, 1);
  digitalWrite(in3, 1);
  digitalWrite(in4, 0);
}
