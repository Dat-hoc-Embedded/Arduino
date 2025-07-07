// defining the pins
const int trigPin1 = 8;
const int echoPin1 = 4;
const int trigPin2 = 10;
const int echoPin2 = 7;
const int trigPin3 = 12;
const int echoPin3 = 11;
int irpin =2;
// defining variables
long duration1;
long duration2;
long duration3;
int distanceleft;
int distancefront;
int distanceright;
int a=0;
int kc=20;
void setup() {
  pinMode(trigPin1, OUTPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(trigPin3, OUTPUT);// Sets the trigPin as an Output
  pinMode(echoPin1, INPUT); // Sets the echoPin as an Input
  pinMode(echoPin2, INPUT);
  pinMode(echoPin3, INPUT);
  pinMode(irpin, INPUT);
  pinMode(6, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(3, OUTPUT);
}
void loop() {
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  duration1 = pulseIn(echoPin1, HIGH);
  distanceleft = duration1 * 0.034 / 2;
  Serial.print("Distance1: ");
  Serial.println(distanceleft);
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
  duration2 = pulseIn(echoPin2, HIGH);
  distancefront = duration2 * 0.034 / 2;
  Serial.print("Distance2: ");
  Serial.println(distancefront);
  digitalWrite(trigPin3, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin3, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin3, LOW);
  duration3 = pulseIn(echoPin3, HIGH);
  distanceright = duration3 * 0.034 / 2;
  Serial.print("Distance3: ");
  Serial.println(distanceright);
  int s = digitalRead(irpin);
  if(s==HIGH)
  { 
    analogWrite(6, LOW);
    analogWrite(9, 100);
    analogWrite(5, LOW);
    analogWrite(3, 100);
      delay(1000);
    a=1;
    }
  if ((a==0)&&(s==LOW)&&(distanceleft <= kc && distancefront > kc && distanceright <= kc) || (a==0)&&(s==LOW)&&(distanceleft > kc && distancefront > kc && distanceright > kc))
  {
    analogWrite(6, 150);
    analogWrite(9, LOW);
    analogWrite(5, 100);
    analogWrite(3,LOW);
  }
  if ((a==1)&&(s==LOW)||(s==LOW)&&(distanceleft <= kc && distancefront <= kc && distanceright > kc)||(s==LOW)&&(distanceleft <= kc && distancefront <= kc && distanceright > kc)||(s==LOW)&& (distanceleft <= kc && distancefront > kc && distanceright > kc)||(distanceleft <= kc && distancefront > kc && distanceright > kc))
  {
    analogWrite(6, 100);
    analogWrite(9, LOW);
    analogWrite(5, LOW);
    analogWrite(3, 100);
    delay(100);
    a=0;
  }
  if ((s==LOW)&&(distanceleft > kc && distancefront <= kc && distanceright <= kc) ||(s==LOW)&& (distanceleft > kc && distancefront > kc && distanceright <= kc) ||(s==LOW)&& (distanceleft > kc && distancefront <= kc && distanceright > kc) )
  {
    analogWrite(6, LOW);
    analogWrite(9, 100);
    analogWrite(5, 100);
    analogWrite(3, LOW);
  }
  if(distanceleft <= kc && distancefront <= kc && distanceright <= kc){
    analogWrite(6, LOW);
    analogWrite(9, 100);
    analogWrite(5, LOW);
    analogWrite(3, 100);
      delay(1000);
  }
}
