int red=6;
int green=5;
int blue=3;
void setup() {
  // put your setup code here, to run once:
  pinMode(red,OUTPUT);
  pinMode(blue,OUTPUT);
  pinMode(green,OUTPUT);
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
  analogWrite(red,xungdo);
  analogWrite(green,xunggreen);
  analogWrite(blue,xungblue);
}
void loop() {
  // put your main code here, to run repeatedly:
  showrainbow();
}
