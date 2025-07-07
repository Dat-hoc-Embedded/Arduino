const int trig=3;
const int echo=2;
const int player=5;
unsigned long thoigian;
int khoangcach;
void setup() {
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  pinMode(player,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  khoangcach =0;
  dokhoangcach();
  if(khoangcach<50){
    digitalWrite(player, HIGH);
  }else{
    digitalWrite(player, LOW);                                                                                                                          
  }

}
void dokhoangcach(){
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);

  thoigian=pulseIn(echo, HIGH);
  khoangcach=thoigian/2/29.412;
}
