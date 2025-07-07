#include <Stepper.h>
#include <IRremote.h>
const int chanRemote=3;
IRrecv irrecv(chanRemote);
decode_results results;
int in1=8;
int in2=9;
int in3=10;
int in4=11;
int led=13;
int nutlen=6;
int nutxuong=7;
int cambien=3;
int relay=2;
int tiengvotay;
const int stepsperrevolution=2048;
unsigned long timer;
Stepper mystep= Stepper(stepsperrevolution,8,10,9,11);//neu 9,11,8,10 thi se bi quay nguoc
Stepper mystep2= Stepper(stepsperrevolution,8,10,9,11);
void setup() {
  mystep.setSpeed(15);
  mystep2.setSpeed(15);
  pinMode(led,OUTPUT);
  pinMode(nutlen,INPUT_PULLUP);
  pinMode(nutxuong,INPUT_PULLUP);
  pinMode(cambien, INPUT);
  Serial.begin(9600);
  irrecv.enableIRIn();
}
void loop() {
  tiengvotay=0;
  int trangthailen=digitalRead(nutlen);
  int trangthaixuong=digitalRead(nutxuong);
  int gtcb=digitalRead(cambien);
  if(trangthailen==0&&trangthaixuong!=0){
    digitalWrite(led,1);
    mystep.step(2048*4);
   }else if(trangthailen!=0&&trangthaixuong==0){
    digitalWrite(led,1);
    mystep.step(-2048*4);
  }else{
    //mystep.step(0);
  }
  delay(500);
  //if(gtcb==1){
  //  digitalWrite(relay,HIGH);
 //   delay(1000);
 //   digitalWrite(led,1);
 //   mystep.step(2048);
//  }
 // if(gtcb==1){
 //   digitalWrite(led,1);
  //  mystep.step(-2048);
//  }
  if(irrecv.decode(&results)){
   Serial.println(results.value,HEX);
   delay(200);
  }
  if(irrecv.decode(&results)){
    if(results.value==0xFF02FD){
      digitalWrite(led,HIGH);
      mystep.step(2048*4);
    }
    if(results.value==0xFF9867){
      digitalWrite(led, HIGH);
      mystep.step(-2048*4);
    }
    irrecv.resume();
  }
  digitalWrite(led,0);
}
