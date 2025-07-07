#define delayms 1
int shcpPin=11;// chan xung de lay gia tri nhap vao chan data
int stcpPin=12;// chan chot du lieu 
int dataPin=10;
int cot1Pin=2;
int cot2Pin=3;
int cot3Pin=4;
int cot4Pin=5;
int cot5Pin=6;
int cot6Pin=7;
int cot7Pin=8;
int cot8Pin=9;// quet cot
/*unsigned char matrixHEX[][8]={
  {0x7E,0x81,0xA5,0x81,0xA5,0x99,0x81,0x7E},//0
  //{0x00,0x00,0x84,0xFE,0x80,0x00,0x00,0x00},//1
  {0xFF,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00},
  //{0x00,0x84,0xC2,0xA2,0x92,0x8C,0x00,0x00},//2
  {0xFB,0xFB,0xFB,0xFB,0xFB,0xFB,0x03,0xFF},
  //{0x00,0x42,0x92,0x9A,0x96,0x62,0x00,0x00},//3
  {0x10,0x18,0x14,0x10,0x10,0x10,0x7C,0x00},//3
  {0x00,0x30,0x2C,0x20,0xFE,0x20,0x00,0x00},//4
  {0x00,0x5E,0x92,0x92,0x92,0x62,0x00,0x00},//5
  {0x00,0x7C,0x92,0x92,0x92,0x64,0x00,0x00},//6
  {0x00,0x02,0x02,0xE2,0x1A,0x06,0x00,0x00},//7
  {0x00,0x6C,0x92,0x92,0x92,0x6C,0x00,0x00},//8
  {0x00,0x4C,0x92,0x92,0x92,0X7C,0x00,0x00}//9
};*/
unsigned char matrixHEX[][8]=
{
  {0x00,0x1C,0x08,0x08,0x08,0x08,0x1C,0x00},//chu I  
  {0x00,0x42,0x55,0x49,0x22,0x14,0x08,0x00},//hinh trai tim
  {0x00,0x22,0x14,0x08,0x08,0x08,0x08,0x00}//chu Y
};
int num=0;
unsigned long premillis=0;
void setup() {
  // put your setup code here, to run once:
  for(int i=2;i<=12;i++){
    pinMode(i,OUTPUT);
  }
}
void nhaychu(int num){
    for(int i=0;i<=7;i++){
            HC595_shiftOut(matrixHEX[num][i]);
            switch(i){
                case 0:
                MATRIX_setCol(1,0,0,0,0,0,0,0);
                break;
                case 1:
                MATRIX_setCol(0,1,0,0,0,0,0,0);  
                break;
            case 2:
                MATRIX_setCol(0,0,1,0,0,0,0,0);  
                break;
                case 3:
                MATRIX_setCol(0,0,0,1,0,0,0,0);  
                break;
                case 4:
                MATRIX_setCol(0,0,0,0,1,0,0,0);  
                break;
                case 5:
                MATRIX_setCol(0,0,0,0,0,1,0,0);  
                break;
                case 6:
                MATRIX_setCol(0,0,0,0,0,0,1,0);  
                break;
                case 7:
                MATRIX_setCol(0,0,0,0,0,0,0,1);  
                break;
            }
            delay(delayms); 
            MATRIX_setCol(0,0,0,0,0,0,0,0);
    }
}
void chay1chu(int num){
    for(int k=8;k>=1;k--){
        for(int i=0;i<=7;i++){
            if(i-k<0){
            HC595_shiftOut(matrixHEX[num][i+8-k]);
            }else {
                HC595_shiftOut(matrixHEX[num][i-k]);
            }
            switch(i){
                case 0:
                MATRIX_setCol(1,0,0,0,0,0,0,0);
                break;
                case 1:
                MATRIX_setCol(0,1,0,0,0,0,0,0);  
                break;
            case 2:
                MATRIX_setCol(0,0,1,0,0,0,0,0);  
                break;
                case 3:
                MATRIX_setCol(0,0,0,1,0,0,0,0);  
                break;
                case 4:
                MATRIX_setCol(0,0,0,0,1,0,0,0);  
                break;
                case 5:
                MATRIX_setCol(0,0,0,0,0,1,0,0);  
                break;
                case 6:
                MATRIX_setCol(0,0,0,0,0,0,1,0);  
                break;
                case 7:
                MATRIX_setCol(0,0,0,0,0,0,0,1);  
                break;
            }
            delay(delayms); 
            MATRIX_setCol(0,0,0,0,0,0,0,0);
        }
        delay(40);
    }
}
void loop() {
  // vong lap quet cot 
  if(millis()-premillis>=320){
    premillis=millis();
   if(++num>2)num=0;// tang bien num
  }
    //xuat ma cua cot 1
    chay1chu(num);
    //nhaychu(num);
}
void HC595_shiftOut(unsigned char b){
  digitalWrite(shcpPin,LOW);
  digitalWrite(stcpPin,LOW);
  for(int  i=0;i<8;i++){
    if(b&(0x80>>i)){//tach day hex thanh day nhi phan
      digitalWrite(dataPin,LOW);// neu tach ra 0 thi tat tach ra 1 thi sang
    }else{
      digitalWrite(dataPin,HIGH);
    }
    digitalWrite(shcpPin, LOW);
    delayMicroseconds(1);
    digitalWrite(shcpPin,HIGH);
  }
  digitalWrite(stcpPin,0);//chot du lieu
  digitalWrite(stcpPin,1);
}
void MATRIX_setCol(int c1,int c2,int c3, int c4, int c5, int c6, int c7, int c8){
  digitalWrite(cot1Pin,c1);
  digitalWrite(cot2Pin,c2);
  digitalWrite(cot3Pin,c3);
  digitalWrite(cot4Pin,c4);
  digitalWrite(cot5Pin,c5);
  digitalWrite(cot6Pin,c6);
  digitalWrite(cot7Pin,c7);
  digitalWrite(cot8Pin,c8);
}
 
