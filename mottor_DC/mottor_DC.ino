int in1=8;
int in2=9;
int in3=10;
int in4=11;
int nutlen=6;
int nutxuong=2;
int led=13;
void setup() {
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);
  pinMode(led,OUTPUT);
  pinMode(nutlen,INPUT_PULLUP);
  pinMode(nutxuong,INPUT_PULLUP);
  digitalWrite(led,0);
  Serial.begin(9600);
}
void loop() {
  //trangthai=digitalRead(congtac);
  //if(trangthai==1){
  //  dung();flag=1;
   // return;
 // }else {
    //int docbientro=analogRead(A0);
   // int x=map(docbientro,0,1023,0,255);
   // lui(x);
  //} 
  int trangthailen=digitalRead(nutlen);
  int trangthaixuong=digitalRead(nutxuong);
  if(trangthailen==0&&trangthaixuong!=0){
    tien();
    digitalWrite(led,HIGH);
  }else if(trangthaixuong==0&&trangthailen!=0){
    lui();
    digitalWrite(led,HIGH);
    delay(500);
  }else{
    dung();
  }  
  digitalWrite(led,LOW);
  Serial.print(trangthailen);
}
void tien(){
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
}
void lui(){
  digitalWrite(in1,LOW);
 digitalWrite(in2,HIGH);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
}
void dung(){
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
}
