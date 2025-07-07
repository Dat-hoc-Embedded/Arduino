const int aPin=2;
const int bPin=3;
const int cPin=4;
const int dPin=5;
const int ePin=6;
const int fPin=7;
const int gPin=8;

const int led1Pin=9;//chan arduino dieu khien led1
const int led2Pin=10;//dkihien led2
const int led3Pin=11;//dieu khien led3
const int led4Pin=12;//dieu khien led4
//ma led 7 thanh anot chung
unsigned char led7HEX[]={0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90};
                        //0,  1,   2,   3,   4,   5,   6,   7,   8,   9
void led7Write_Byte(unsigned char b){
  //lay bit thu D0  (A) neu ==1 lay muc cao ==0 lay muc thap
  if(((b>>0 ) &0x01)==0){
    digitalWrite(aPin, HIGH);
  }else {
    digitalWrite(aPin,LOW);
  }
  if(((b>>1) &0x01)==0){
    digitalWrite(bPin, HIGH);
  }else {
    digitalWrite(bPin,LOW);
  }
  if(((b>>2 ) &0x01)==0){
    digitalWrite(cPin, HIGH);
  }else {
    digitalWrite(cPin,LOW);
  }
  if(((b>>3 ) &0x01)==0){
    digitalWrite(dPin, HIGH);
  }else {
    digitalWrite(dPin,LOW);
  }
  if(((b>>4 ) &0x01)==0){
    digitalWrite(ePin, HIGH);
  }else {
    digitalWrite(ePin,LOW);
  }
  if(((b>>5) &0x01)==0){
    digitalWrite(fPin, HIGH);
  }else {
    digitalWrite(fPin,LOW);
  }
  if(((b>>6) &0x01)==0){
    digitalWrite(gPin, HIGH);
  }else {
    digitalWrite(gPin,LOW);
  }
}
void setup (){
  pinMode(aPin, OUTPUT);
  pinMode(bPin, OUTPUT);
  pinMode(cPin, OUTPUT);
  pinMode(dPin, OUTPUT);
  pinMode(ePin, OUTPUT);
  pinMode(fPin, OUTPUT);
  pinMode(gPin, OUTPUT);

  pinMode(led1Pin,OUTPUT);
  pinMode(led2Pin,OUTPUT);
  pinMode(led3Pin,OUTPUT);
  pinMode(led4Pin,OUTPUT);  
}
void loop(){
   for(int num=0;num<1000;num++){
    //quet led 25 lan tao tre khoang 25*40=1000ms
    for(int i=0;i<25;i++){
      //bat hien thi led1
      digitalWrite(led1Pin,LOW);
      //xuat ma hien thi hang ngan
      led7Write_Byte(led7HEX[num/1000]);
      //tao tre 10ms;
      delay(10);
      //tat led hien thi led1
      digitalWrite(led1Pin, HIGH);

      //bat hien thi led2
      digitalWrite(led2Pin,LOW);
      //xuat ma hien thi led2
      led7Write_Byte(led7HEX[num/100%10]);
      //tao tre 10ms
      delay(10);
      //tat hien thi led 2
      digitalWrite ( led2Pin, HIGH);

      //bat hien thi led3
      digitalWrite(led3Pin,LOW);
      //xuat ma hien thi led3
      led7Write_Byte(led7HEX[num/10%10]);
      //tao tre 10ms
      delay(10);
      //tat hien thi led 3
      digitalWrite ( led3Pin, HIGH);

      //bat hien thi le4
      digitalWrite(led4Pin,LOW);
      //xuat ma hien thi led4
      led7Write_Byte(led7HEX[num%10]);
      //tao tre 10ms
      delay(10);
      //tat hien thi led 4
      digitalWrite ( led4Pin, HIGH);
    }
   }
}
