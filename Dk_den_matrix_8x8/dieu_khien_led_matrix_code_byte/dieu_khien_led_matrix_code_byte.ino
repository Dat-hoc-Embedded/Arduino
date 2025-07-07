int dl=10;//chan nhan du lieu tu chan xung
int xung=11;//chan nhan xung du lieu noi voi chan shcp
int chot=12;//chan chot du lieu noi voi chan stcp
int pin[8]={2,3,4,5,6,7,8,9};//cac chan dieu khien hang 
int hientai=0;
int macot[8][8]={
   1,1,1,1,1,1,1,1,
   1,1,1,1,0,1,1,1,
   1,1,1,0,0,1,1,1,
   1,1,0,1,0,1,1,1,
   1,1,1,1,0,1,1,1,
   1,1,1,1,0,1,1,1,
   1,1,0,0,0,0,0,1,
   1,1,1,1,1,1,1,1,
};
void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  for(int i=2;i<=12;i++){
    pinMode(i,OUTPUT);
  }
  for(int i=0;i<=7;i++){
    digitalWrite(pin[i],0);
  }
}
void docmahang(int i){
  for(int j=7;j>=0;j--){
   // Serial.print(macot[i][j]);
    //delay(500);

    digitalWrite(dl,macot[i][j-2]);
    digitalWrite(xung,0);
    digitalWrite(xung,1);
  }
  
  digitalWrite(chot,0);//chot du lieu
  digitalWrite(chot,1);
}
void docmahangchaychu(int i,int k){
  for(int j=7;j>=0;j--){
    if(j-k <0){
      digitalWrite(dl,macot[i][j+8-k]);
    }else{
      digitalWrite(dl,macot[i][j-k]);
    }
    
    digitalWrite(xung,0);
    digitalWrite(xung,1);
  }
  
  digitalWrite(chot,0);//chot du lieu
  digitalWrite(chot,1);
}
void quethang(int i){//chan i muon hien thi thi de 0, cac chan con lai thi de 1
  for(int j=0;j<=7;j++){
    if(j!=i){
    digitalWrite(pin[j],0);
    }
    }
  digitalWrite(pin[i],1);
}
void loop() {
  for(int k=1;k<=8;k++){
    for(int i=0;i<=7;i++){
      digitalWrite(pin[i],0);
      docmahangchaychu(i,k);
      quethang(i);
      delay(1);
    }
    delay(70);
  }
}
