int cbmua=7;
void setup() {
  // put your setup code here, to run once:
  pinMode(cbmua,INPUT);
  Serial.begin(9600); 
}

void loop(){
  int thchandigital=digitalRead(cbmua);
  int thchananalog=digitalRead(A0);
  Serial.print(thchandigital);
  Serial.println(thchananalog);
  delay(500);
}
