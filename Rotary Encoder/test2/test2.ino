#include <Servo.h>
Servo myservo;
int servo = 8;
int led = 9;
 
int phaA = 2;
int phaB = 3;
int nutnhan = 7; int gtnutnhan;

int dem = 0; int hientai; int bandau; 
  
void setup() 
{ 
   Serial.begin (9600);

   pinMode(led, OUTPUT);
   myservo.attach(servo);
   myservo.write(0);
   
   pinMode(phaA,INPUT);
   pinMode(phaB,INPUT);
   pinMode(nutnhan, INPUT);
      
   bandau = digitalRead(phaA);   
} 

void loop() 
{ 
   gtnutnhan = digitalRead(nutnhan); 
   //Serial.print("Nút nhấn: "); Serial.println(gtnutnhan);
   if (gtnutnhan == 0)
   {
    digitalWrite(led, HIGH);
   }
   else
   {
    digitalWrite(led, LOW);
   }
   
   hientai = digitalRead(phaA);
   
   if (hientai != bandau)
   {     
     if (digitalRead(phaB) != hientai) 
     { 
       dem += 5;
       if (dem >= 180)
       {
        dem = 180;
       }
     } 
     else 
     {
       dem -=5;
       if (dem <= 0)
       {
        dem = 0;
       }       
     }
     myservo.write(dem);
     Serial.print("Giá trị: "); Serial.println(dem);
   } 
   bandau = hientai;
}
