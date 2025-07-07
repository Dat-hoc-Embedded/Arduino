#include <IRremote.h>
#include <IRremoteInt.h>
const int chanremote=8;
IRrecv irrecv(chanremote);
decode_results results;
int in1=3;
int in2=5;
int in3=6;
int in4=9;
void setup() {
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  Serial.begin(9600);
  irrecv.enableIRIn();
}

void loop() {
  if(irrecv.decode(&results)){
    Serial.println(results.value,HEX);
    delay(200);
    irrecv.resume();
  }// lay ma dieu khien 
  if(irrecv.decode(&results)){
    if(results.value==0xFF02FD){
      tien();
    }else if(results.value==0xFF9867){
      lui();
    }else if(results.value==0xFFE01F){
      trai();
    }else if(results.value==0xFF906F){
      phai();
    }else if(results.value==0xFFA857){
      dung();
    }
    irrecv.resume();
  }
}
void lui(){
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
  }
 void tien(){
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
  int phai(){
    digitalWrite(in1,LOW);
    digitalWrite(in2,LOW);
    digitalWrite(in3,LOW);
    digitalWrite(in4,HIGH);
    }
  int trai(){
    digitalWrite(in1,LOW);
    digitalWrite(in2,HIGH);
    digitalWrite(in3,LOW);
    digitalWrite(in4,LOW);
    }
