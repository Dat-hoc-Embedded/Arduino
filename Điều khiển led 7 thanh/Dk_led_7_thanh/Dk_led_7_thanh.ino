const int aPin=2;
const int bPin=3;
const int cPin=4;
const int dPin=5;
const int ePin=6;
const int fPin=7;
const int gPin=8;
//ma led 7 thanh katot chung
unsigned char led7Hex[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
void led7Write_Byte(unsigned char b){
  //lay bit thu D0  (A) neu ==1 lay muc cao ==0 lay muc thap
  if(((b>>0 ) &0x01)==1){
    digitalWrite(aPin, HIGH);
  }else {
    digitalWrite(aPin,LOW);
  }
  if(((b>>1) &0x01)==1){
    digitalWrite(bPin, HIGH);
  }else {
    digitalWrite(bPin,LOW);
  }
  if(((b>>2 ) &0x01)==1){
    digitalWrite(cPin, HIGH);
  }else {
    digitalWrite(cPin,LOW);
  }
  if(((b>>3 ) &0x01)==1){
    digitalWrite(dPin, HIGH);
  }else {
    digitalWrite(dPin,LOW);
  }
  if(((b>>4 ) &0x01)==1){
    digitalWrite(ePin, HIGH);
  }else {
    digitalWrite(ePin,LOW);
  }
  if(((b>>5) &0x01)==1){
    digitalWrite(fPin, HIGH);
  }else {
    digitalWrite(fPin,LOW);
  }
  if(((b>>6) &0x01)==1){
    digitalWrite(gPin, HIGH);
  }else {
    digitalWrite(gPin,LOW);
  }
}
void setup() {
  pinMode(aPin, OUTPUT);
  pinMode(bPin, OUTPUT);
  pinMode(cPin, OUTPUT);
  pinMode(dPin, OUTPUT);
  pinMode(ePin, OUTPUT);
  pinMode(fPin, OUTPUT);
  pinMode(gPin, OUTPUT);
}
void loop() {
  for(int i=0;i<10;i++){
    led7Write_Byte(led7Hex[i]);
    delay(1000);
  }
}
