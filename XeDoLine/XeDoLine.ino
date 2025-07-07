
//int cbsau=2;
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
  //int gtcbsau;
  
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
   
 // pinMode(cbsau,INPUT);
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
  //gtcbsau=digitalRead(cbsau);
//====================================
  if(gtcbtrai==0 && gtcbphai==0)
  {
    dithang();
  }
  else if(gtcbtrai!=0 && gtcbphai==0)
  {
    disangtrai();
  }
  else if(gtcbtrai==0 && gtcbphai!=0)
  {
    disangphai();
  }
  else {dunglai();}
  

}

void dithang()
{
  analogWrite(enbA, 120);
  analogWrite(enbB, 120);
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
  analogWrite(enbA, 120);
  analogWrite(enbB, 0);
  digitalWrite(in1, 0);
  digitalWrite(in2, 1);
  digitalWrite(in3, 0);
  digitalWrite(in4, 0);


}
void disangtrai()
{
  analogWrite(enbA, 0);
  analogWrite(enbB, 120);
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
