int denled=3;
void setup() {
  Serial.begin(9600);
  pinMode(denled,OUTPUT);
}
void loop() {
  int docbientro=analogRead(A0);
  int x=map(docbientro,0,1023,100,2000);
  digitalWrite(denled,HIGH);
  delay(x);
  digitalWrite(denled,LOW);
  delay(x);
}
