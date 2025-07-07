#include <VirtualWire.h> // khai báo thư viện VirtualWire
uint8_t msg[VW_MAX_MESSAGE_LEN];// biến lưu dữ liệu nhận được
uint8_t msgLen = VW_MAX_MESSAGE_LEN;

int trucX;//Đọc giá trị trục X
int trucY; // Đọc giá trị trục Y

//Khai báo các chân kết nối với L298N
int enbA=3;
int in1 = 5;       
int in2 = 6;        
int in3 = 9;        
int in4 = 10;  
int enbB=11;      

void setup() {
  Serial.begin(9600);
  Serial.println("READY..........");
  vw_setup(1024); // cài đặt tốc độ truyền tín hiệu
  vw_set_rx_pin(8);// cài đặt chân digital để nhận tín hiệu-----------------------------------------------------------------------------------------
  vw_rx_start();// bắt đầu nhận tín hiệu
    
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(enbA, OUTPUT);
  pinMode(enbB, OUTPUT);
  //========================//
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  digitalWrite(enbA, LOW);
  digitalWrite(enbB, LOW);
 
}

void loop()
{
  char text[20]="";
    String text1="";
    int giatri=0;
  if (vw_get_message(msg, &msgLen)) // nếu có tín hiệu được truyền đến
  {
    Serial.print("got: ");
    for (int i = 0; i < msgLen; i++)
    {
      text[i]=msg[i];
     // Serial.write(msg[i]);// in ký tự ra màn hình
    }
    Serial.println(text);
    sscanf(text,"%d,%d",&trucX, &trucY);
    if(trucY>30 && trucX>=-30 && trucX<=30)
      {dithang(150);Serial.println("Di toi");}
    else if(trucY<-30 && trucX>=-30 && trucX<=30)
      {dilui(150);Serial.println("Di lui");}
    else if(trucX>30 && trucY>=-30 && trucY<=30)
      {disangphai(150);Serial.println("Di sang phai");}
    else if(trucX<-30 && trucY>=-30 && trucY<=30)
      {disangtrai(150);Serial.println("di sang trai");}
    else {dunglai();Serial.println("dung");}
  }
 
}

void dithang(int tocdo)
{
  analogWrite(enbA, tocdo);
  analogWrite(enbB, tocdo);
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

void disangphai(int tocdo)
{
  analogWrite(enbA, tocdo);
  analogWrite(enbB, 0);
  digitalWrite(in1, 0);
  digitalWrite(in2, 1);
  digitalWrite(in3, 0);
  digitalWrite(in4, 0);


}
void disangtrai(int tocdo)
{
  analogWrite(enbA, 0);
  analogWrite(enbB, tocdo);
  digitalWrite(in1, 0);
  digitalWrite(in2, 0);
  digitalWrite(in3, 0);
  digitalWrite(in4, 1);

}

void dilui(int tocdo)
{
  analogWrite(enbA, tocdo);
  analogWrite(enbB, tocdo);
  digitalWrite(in1, 1);
  digitalWrite(in2, 0);
  digitalWrite(in3, 1);
  digitalWrite(in4, 0);

}

void xoay(int tocdo)
{
  analogWrite(enbA, tocdo);
  analogWrite(enbB, tocdo);
  digitalWrite(in1, 0);
  digitalWrite(in2, 1);
  digitalWrite(in3, 1);
  digitalWrite(in4, 0);
}
void xoaytrai(int tocdo)
{
  analogWrite(enbA, tocdo);
  analogWrite(enbB, tocdo);
  digitalWrite(in1, 1);
  digitalWrite(in2, 0);
  digitalWrite(in3, 0);
  digitalWrite(in4, 1);

}
void xoayphai(int tocdo)
{
  analogWrite(enbA, tocdo);
  analogWrite(enbB, tocdo);
  digitalWrite(in1, 0);
  digitalWrite(in2, 1);
  digitalWrite(in3, 1);
  digitalWrite(in4, 0);


}
