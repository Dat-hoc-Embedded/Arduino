int cb=3;
int relay=2;
int trangthaiden;
int tiengvotay;
int gtcb;
unsigned long timer;
void setup() {
  pinMode(cb,INPUT);
  pinMode(relay,OUTPUT);
  trangthaiden=0;
  timer=0;
  Serial.begin(9600);
}

void loop() {
  gtcb=digitalRead(cb);
  tiengvotay=0;
  Serial.print(gtcb);
  Serial.print("--");
  if(gtcb==1){
    timer=millis();
    tiengvotay++;delay(500);
    while(millis()-timer<2000){
        gtcb=digitalRead(cb);
        if(gtcb==1){
          tiengvotay++;delay(100);
        }
      }
  }
  Serial.print(tiengvotay);
  if(tiengvotay==1){
    digitalWrite(relay,HIGH);
    delay(1000);
  }else if(tiengvotay==2){
    digitalWrite(relay, LOW);
    delay(1000);
  }
  
}
