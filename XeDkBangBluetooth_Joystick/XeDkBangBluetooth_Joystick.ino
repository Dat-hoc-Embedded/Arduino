#include <SoftwareSerial.h>
 
#define TX_PIN      8
#define RX_PIN      7
char value; 
SoftwareSerial bluetooth(RX_PIN, TX_PIN);
int baudRate[] = {300, 1200, 2400, 4800, 9600, 19200, 38400, 57600, 115200};
   
int enbA=3;
int in1 = 5;       
int in2 = 6;        
int in3 = 9;        
int in4 = 10;  
int enbB=11;      
int xAxis=140, yAxis=140;  
void setup() {
  Serial.begin(9600);
  while (!Serial) {}
  
  Serial.println("Configuring, please wait...");
  
  for (int i = 0 ; i < 9 ; i++) {
     bluetooth.begin(baudRate[i]);
     String cmd = "AT+BAUD4";
     bluetooth.print(cmd);
     bluetooth.flush();
     delay(100);
  }
  
  bluetooth.begin(9600);
  Serial.println("Config done");
  while (!bluetooth) {}
  
  Serial.println("Enter AT commands:");
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
  
 


}

void loop()
{
  while (bluetooth.available() >= 2) {
    xAxis = bluetooth.read();
    delay(10);
    yAxis = bluetooth.read();
   Serial.print(xAxis);
   Serial.print(",");
   Serial.println(yAxis);
  }
  delay(10);

  if (xAxis > 120 && xAxis <160 && yAxis > 120 && yAxis <160){
    dunglai();Serial.println("Dung");
    }
  else if (yAxis > 120 && yAxis <160){    

        if (xAxis < 120){
          disangphai(150);Serial.println("Di Sang trai");
        }
                
      if (xAxis > 160) {
        disangtrai(150);Serial.println("Di Sang phai");
       }

  }else if (xAxis > 120 && xAxis <160){

      if (yAxis < 120){
      dithang(150);Serial.println("Di Thang");
      }
    if (yAxis > 160){dilui(150);Serial.println("Di Lui");}

  }
  else {dunglai();}
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
