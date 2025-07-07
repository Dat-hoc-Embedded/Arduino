#define congtac 11
int den = 8;
void setup(){
  Serial.begin(9600);
  pinMode(congtac, INPUT);
  pinMode(den,OUTPUT);
 
}
int trangthaiden=0;
void loop(){
  int trangthai=digitalRead(congtac); 
  if(trangthai==1){
    trangthaiden=!trangthaiden;
    digitalWrite(den,trangthaiden);
    delay(500);
  }
}