int cbvao=2;
int cbra=3;
int led=4;
int songuoi=0;
String vao="";
String ra="";
int timeout_vao;
int timeout_ra;
void setup() {

  pinMode(cbvao,INPUT);
  pinMode(cbra,INPUT);
  pinMode(led,OUTPUT);
  Serial.begin(9600);
  timeout_vao=0;
  timeout_ra=0;
}

void loop() {
  timeout_vao++;timeout_ra++;
 int gtcbvao=digitalRead(cbvao);Serial.println(gtcbvao);
 int gtcbra=digitalRead(cbra);Serial.println(gtcbra);

 if(songuoi>0) {digitalWrite(led,HIGH);}
 else {digitalWrite(led,LOW);}
 
 if(gtcbvao==0 && vao.charAt(0)!='v'){
    vao+="v";
  }
 if(gtcbra==0 && ra.charAt(0)!='r'){
    ra+="r";
  }
 if(vao.equals("v") && timeout_vao==1){
    Serial.print(vao);
    songuoi++;
    vao="";
    delay(300);
  }
 if(ra.equals("r") && songuoi>0 && timeout_ra==1){
    Serial.println(ra);
    songuoi--;ra="";
    delay(500);
  }
  gtcbvao=digitalRead(cbvao);
  gtcbra=digitalRead(cbra);
  if (gtcbvao==0){
    timeout_vao++;
    vao="";
   }
  else {
    timeout_vao=0;
    vao="";
    }
  if (gtcbra==0){
    timeout_ra++;
    ra="";
    }
  else {timeout_ra=0;ra="";}
  Serial.print("So nguoi trong phong la: ");
  Serial.println(songuoi);
}
