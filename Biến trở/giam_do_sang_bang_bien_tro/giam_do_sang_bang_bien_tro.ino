int led=3;
void setup() {
  pinMode(led,OUTPUT);
}
void loop() {
  int docbientro=analogRead(A0);
  int x=map(docbientro,0,1023,0,255);
  analogWrite(led,x);
  
}
