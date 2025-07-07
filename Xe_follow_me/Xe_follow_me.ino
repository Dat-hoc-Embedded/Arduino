int enbA=3;
int in1 = 5;       
int in2 = 6;        
int in3 = 9;        
int in4 = 10;  
int enbB=11;      
const int echo1=8;//cam bien giua 
const int trig1=7;
int echo2=4;//cam bien phai
int trig2=2;
int echo3=12;//cam bien trai 
int trig3=13;
unsigned long thoigian; 
int khoangcach;  
void setup() {
  pinMode(echo1,INPUT);
  pinMode(trig1,OUTPUT);
  pinMode(echo2,INPUT);
  pinMode(trig2,OUTPUT);
  pinMode(echo3,INPUT);
  pinMode(trig3,OUTPUT);

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
void loop() {
  int kcgiua=dokhoangcach(trig1,echo1);
  int kcphai=dokhoangcach(trig2,echo2);
  int kctrai=dokhoangcach(trig3,echo3);
  Serial.println(kcgiua);Serial.println(kcphai);Serial.println(kctrai);
  if(kcgiua<25 && kcgiua>5){
    dithang();Serial.println("Di thang");
  }else if(kcgiua<=5){
    dilui();Serial.println("Di lui");
  }else if(kcgiua>=25){
    dunglai();Serial.println("Dung lai");
  }
  if(kctrai<25 && kctrai>5){
    disangtrai();Serial.println("Di sang trai");
  }
  if(kcphai<25 && kcphai>5){
    disangphai();Serial.println("Di sang phai");
  }

}
int dokhoangcach(trig,echo)
{

  digitalWrite(trig, LOW); 
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);  
  delayMicroseconds(10); 
  digitalWrite(trig, LOW); 


  // Đo độ rộng xung HIGH ở chân echo.
  thoigian = pulseIn(echo, HIGH);

  khoangcach = thoigian / 2 / 29.412;
  return khoangcach;
}
void dithang()
{
  analogWrite(enbA, 80);
  analogWrite(enbB, 80);
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
