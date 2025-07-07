int congtac =2;
int led=3;
int trangthailed=0;
void setup()
{
  pinMode(congtac,INPUT);
  Serial.begin(9600);
  pinMode(led,OUTPUT);
  digitalWrite(led,LOW);
}

void loop()
{
  int trangthai=digitalRead(congtac);
  int ledsang=digitalRead(led);
  Serial.print(trangthai);
  if(trangthai==1 && ledsang==trangthailed){
    digitalWrite(led,!trangthailed);
    delay(1000);
    trangthailed=!trangthailed;
  }
}
