int cb=6;
int relay=5;
void setup() {
  pinMode(cb,INPUT);
  pinMode(relay,OUTPUT);
}
void loop() {
  int gtcb=digitalRead(cb);
  if(gtcb==0){
      digitalWrite(relay,HIGH);
      delay(2000);
      digitalWrite(relay,LOW);
      delay(2000);
    }else{
      digitalWrite(relay,LOW);
    }
}
