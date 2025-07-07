#include <SoftwareSerial.h>
 
#define TX_PIN      8
#define RX_PIN      7
char value; 
SoftwareSerial bluetooth(TX_PIN, RX_PIN);
int baudRate[] = {300, 1200, 2400, 4800, 9600, 19200, 38400, 57600, 115200};
   
int enbA=3;
int in1 = 5;       
int in2 = 6;        
int in3 = 9;        
int in4 = 10;  
int enbB=11;      
char kytu="";
String chuoi="";
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
   if (bluetooth.available()) {
    
    kytu=bluetooth.read();
    chuoi=chuoi+kytu;
    Serial.println(kytu);
    if(chuoi.indexOf("đi tới")>=0){
        dithang(150);
        delay(2000);dunglai();
        chuoi="";
        
      }
    if(chuoi.indexOf("đi lùi")>=0){
        dilui(150);
        delay(2000);
        dunglai();
        Serial.println(chuoi);
        chuoi="";
        
      }
     if(chuoi.indexOf("rẽ trái")>=0){
        disangtrai(150);
        delay(500);
        dunglai();
        Serial.println(chuoi);
        chuoi="";
        
      }
    if(chuoi.indexOf("rẽ phải")>=0){
        disangphai(150);
        delay(500);
        dunglai();
        Serial.println(chuoi);
        chuoi="";
       
      }
    if(chuoi.indexOf("xoay phải")>=0){
        xoayphai(150);
        delay(500);
        dunglai();
        Serial.println(chuoi);
        chuoi="";
       
      }
    if(chuoi.indexOf("xoay trái")>=0){
      xoaytrai(150);
      delay(500);
      dunglai();
      Serial.println(chuoi);
      chuoi="";
     
    }
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

void disangtrai(int tocdo)
{
  analogWrite(enbA, tocdo);
  analogWrite(enbB, 0);
  digitalWrite(in1, 0);
  digitalWrite(in2, 1);
  digitalWrite(in3, 0);
  digitalWrite(in4, 0);


}
void disangphai(int tocdo)
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
void xoayphai(int tocdo)
{
  analogWrite(enbA, tocdo);
  analogWrite(enbB, tocdo);
  digitalWrite(in1, 1);
  digitalWrite(in2, 0);
  digitalWrite(in3, 0);
  digitalWrite(in4, 1);

}
void xoaytrai(int tocdo)
{
  analogWrite(enbA, tocdo);
  analogWrite(enbB, tocdo);
  digitalWrite(in1, 0);
  digitalWrite(in2, 1);
  digitalWrite(in3, 1);
  digitalWrite(in4, 0);


}
