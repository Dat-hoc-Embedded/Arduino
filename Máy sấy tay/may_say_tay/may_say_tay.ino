int trig1=2;
int echo1=3;
int relay=5;
int trig2=7;
int echo2=8;
int loa=9;
unsigned long thoigian;
int khoangcachduoi;
int khoangcachtruoc;
void setup() {
  pinMode(relay,OUTPUT);
  pinMode(trig1,OUTPUT);
  pinMode(echo1,INPUT);
  pinMode(trig2,OUTPUT);
  pinMode(echo2,INPUT);
  digitalWrite(relay,HIGH);
  pinMode(loa,OUTPUT);
  digitalWrite(loa,LOW);
}
void loop() {
  khoangcachduoi=0;
  khoangcachtruoc=0;
  khoangcachduoi=dokhoangcach(trig1,echo1);
  khoangcachtruoc=dokhoangcach(trig2,echo2);
  if(khoangcachtruoc<30){
    digitalWrite(loa,HIGH);
  }else{
    digitalWrite(loa,LOW);
  }
  if(khoangcachduoi<10){
    digitalWrite(relay, LOW);
    delay(7000);
    digitalWrite(relay, HIGH);
  }
}
int dokhoangcach(int trig, int echo){
  int khoangcach;
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);

  thoigian=pulseIn(echo, HIGH);
  khoangcach=thoigian/2/29.412;
  return khoangcach;
}
