#include <Servo.h>
Servo myservo;
int servopin=9;
int angle=0;
void setup() {
  myservo.attach(servopin);
  Serial.begin(9600);
  myservo.write(0);
}

void loop() {
   /*for(angle=0;angle<=90;angle++){
    Serial.print("goc la: ");Serial.print(angle);
    myservo.write(angle);
    delay(300);
   }*/
   myservo.write(0);
   delay(1000);
   myservo.write(360);
   delay(1000);
}
