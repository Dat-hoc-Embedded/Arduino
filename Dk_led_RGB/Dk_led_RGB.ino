int Red=9;
int Green=10;
int Blue=11;
void setup() {
  // put your setup code here, to run once:
  pinMode(Red,OUTPUT);
  pinMode(Green,OUTPUT);
  pinMode(Blue,OUTPUT);
  analogWrite(Red,0);
  analogWrite(Green,0);
  analogWrite(Blue,0);
}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(Red,255);
  analogWrite(Green,255);
  analogWrite(Blue,255);
}
