#include <SoftwareSerial.h>
 
#define TX_PIN      8
#define RX_PIN      7
char value; 
SoftwareSerial bluetooth(7, 8);
int baudRate[] = {300, 1200, 2400, 4800, 9600, 19200, 38400, 57600, 115200};
   
int enbA=3;
int in1 = 5;       
int in2 = 6;        
int in3 = 9;        
int in4 = 10;  
int enbB=11;      
  
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
  value="";
  if (bluetooth.available()) {
    
    value=bluetooth.read();
    Serial.write(value);
    switch(value)
    {
      case 'u':
        dithang();
        break;
      case 'd': 
        dilui();
        break;
      case 'r':
        disangtrai();
        break;
      case 'l':
        disangphai();
        break;
      case 's':
        dunglai();
        break;
      case 'm':
        xoayphai();
        break;
     case 'n':
        xoaytrai();
        break;  
    }
  }
//  if (bluetooth.available()){
//    Serial.write(bluetooth.read());
//  }
//  if (Serial.available()){
//    bluetooth.write(Serial.read());
//  }
}

void dithang()
{
  analogWrite(enbA, 150);
  analogWrite(enbB, 150);
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
  analogWrite(enbA, 150);
  analogWrite(enbB, 0);
  digitalWrite(in1, 0);
  digitalWrite(in2, 1);
  digitalWrite(in3, 0);
  digitalWrite(in4, 0);


}
void disangtrai()
{
  analogWrite(enbA, 0);
  analogWrite(enbB, 150);
  digitalWrite(in1, 0);
  digitalWrite(in2, 0);
  digitalWrite(in3, 0);
  digitalWrite(in4, 1);

}

void dilui()
{
  analogWrite(enbA, 150);
  analogWrite(enbB, 150);
  digitalWrite(in1, 1);
  digitalWrite(in2, 0);
  digitalWrite(in3, 1);
  digitalWrite(in4, 0);

}

void xoay()
{
  analogWrite(enbA, 150);
  analogWrite(enbB, 150);
  digitalWrite(in1, 0);
  digitalWrite(in2, 1);
  digitalWrite(in3, 1);
  digitalWrite(in4, 0);
}
void xoaytrai()
{
  analogWrite(enbA, 150                                                                                                   );
  analogWrite(enbB, 150);
  digitalWrite(in1, 1);
  digitalWrite(in2, 0);
  digitalWrite(in3, 0);
  digitalWrite(in4, 1);

}
void xoayphai()
{
  analogWrite(enbA, 150);
  analogWrite(enbB, 150);
  digitalWrite(in1, 0);
  digitalWrite(in2, 1);
  digitalWrite(in3, 1);
  digitalWrite(in4, 0);


}
