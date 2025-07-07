 
int phaA = 2;
int phaB = 3;
int nutnhan = 7; int gtnutnhan;

int dem = 0; int hientai; int bandau; 
  
void setup() 
{ 
   Serial.begin (9600);
   
   pinMode(phaA,INPUT);
   pinMode(phaB,INPUT);
   pinMode(nutnhan, INPUT);
      
   bandau = digitalRead(phaA);   
} 

void loop() 
{ 
   gtnutnhan = digitalRead(nutnhan); 
   //Serial.print("Nút nhấn: "); Serial.println(gtnutnhan);
   
   hientai = digitalRead(phaA);   
   if (hientai != bandau)
   {     
     if (digitalRead(phaB) != hientai) 
     { 
       dem ++;
     } 
     else 
     {
       dem --;
     }
     Serial.print("Giá trị: "); Serial.println(dem);
   } 
   bandau = hientai;
}
