const int cbhn =2;
const int player=5;
void setup() {
  pinMode(cbhn,INPUT);
  pinMode(player,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int gtcbhn=digitalRead(cbhn);
  Serial.print(gtcbhn);
  if(gtcbhn==0){
      digitalWrite(player, HIGH);
  }else {
    digitalWrite(player, LOW);
  }

}
