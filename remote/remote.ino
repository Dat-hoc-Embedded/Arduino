#include <IRremote.h>
const int chanRemote=8;
IRrecv irrecv(chanRemote);
decode_results results;
int led1=2;
int led2=3;
boolean trangthailed1=LOW;
boolean trangthailed2=LOW;
boolean trangthairgb=LOW;
int Red=9;
int Green=10;
int Blue=11;
int congtac=4;
void setup() {
 Serial.begin(9600);
 pinMode(led1,OUTPUT);
 pinMode(led2,OUTPUT);
 irrecv.enableIRIn();
 pinMode(Red,OUTPUT);
 pinMode(Green,OUTPUT);
 pinMode(Blue,OUTPUT);
 pinMode(congtac,INPUT_PULLUP);
}
void loop() {
  //int trangthaicongtac=digitalRead(congtac);
  //Serial.println(trangthaicongtac);
  if(irrecv.decode(&results)){
    Serial.println(results.value,HEX);
    delay(200);
    irrecv.resume();
  }
  if(irrecv.decode(&results)){
    if(results.value==0xFFA25D){
      trangthailed1=!trangthailed1;
      digitalWrite(led1,trangthailed1);
    }
    if(results.value==0xFFE21D){
      trangthailed2=!trangthailed2;
      digitalWrite(led2, trangthailed2);
    }
    if(results.value==0xFF02FD){
      trangthairgb=!trangthairgb;
      if(trangthairgb==HIGH){
        analogWrite(Red,150);
        analogWrite(Blue,150);
        analogWrite(Green,100);
      }
      if(trangthairgb==LOW){
        analogWrite(Red,0);
        analogWrite(Blue,0);
        analogWrite(Green,0);
      }
    }
    irrecv.resume();
  }
}
void showrainbow(){
  for(int i=0;i<768;i++){
    showRGB(i);
    delay(15);
  }
  //do->xanh luc:0->255
  //xanh luc->xanh lam:256-511
  //xanh lam-do:512-767
}
void showRGB(int color){
  int xungdo;
  int xungblue;
  int xunggreen;
  if(color<=255){
    xungdo=255-color;
    xunggreen=color;
    xungblue=0;
  }else if(color<=511){
    xungdo=0;
    xunggreen=255-(color-256);
    xungblue=color-256;
  }else{
    xungdo=color-512;
    xunggreen=0;
    xungblue=255-(color-512);
  }
  analogWrite(Red,xungdo);
  analogWrite(Green,xunggreen);
  analogWrite(Blue,xungblue);
}