#include "Arduino.h"
#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"
// int cbhn=8;
const int pre=2   ;
const int playpause=3;
const int next=4;
SoftwareSerial mySoftwareSerial(10, 11); //TX,RX
DFRobotDFPlayerMini myDFPlayer;
void printDetail(uint8_t type, int value);
static unsigned long timer = millis();
static unsigned long timer1 = millis();
int hat;
int toi;
int lui;
int baidau=1;
boolean danghat=false;
void setup()
{
  mySoftwareSerial.begin(9600);
  Serial.begin(115200);
 // pinMode(cbhn,INPUT);
  pinMode(pre, INPUT_PULLUP);
  pinMode(playpause, INPUT_PULLUP);
  pinMode(next, INPUT_PULLUP);
  
  Serial.println();
  Serial.println(F("DFRobot DFPlayer Mini Demo"));
  Serial.println(F("Initializing DFPlayer ... (May take 3~5 seconds)"));

  if (!myDFPlayer.begin(mySoftwareSerial)) {  //Use softwareSerial to communicate with mp3.
    Serial.println(F("Unable to begin:"));
    Serial.println(F("1.Please recheck the connection!"));
    Serial.println(F("2.Please insert the SD card!"));
    while(true);
  }
  Serial.println(F("DFPlayer Mini online."));
  
  myDFPlayer.setTimeOut(500); //Set serial communictaion time out 500ms

  //----Set volume----
  myDFPlayer.volume(30);  //Set volume value (0~30).
  //myDFPlayer.volumeUp(); //Volume Up
  //myDFPlayer.volumeDown(); //Volume Down

  //----Set different EQ----
  myDFPlayer.EQ(DFPLAYER_EQ_NORMAL);

  //----Set device we use SD as default----
//  myDFPlayer.outputDevice(DFPLAYER_DEVICE_U_DISK);
  myDFPlayer.outputDevice(DFPLAYER_DEVICE_SD);
  //myDFPlayer.enableLoopAll();
    //myDFPlayer.play(1);delay(5000);
    danghat=true;
  //----Read imformation----
  hat=1;
  toi=1;
  lui=1;
  baidau=1;
}

void loop()
{
 // int gtcb=digitalRead(cbhn);
  int vpre=digitalRead(pre);
  int vplaypause=digitalRead(playpause);
  int vnext=digitalRead(next);
  
 if (millis() - timer > 200 && baidau==1) {
    timer=millis();baidau++;
   myDFPlayer.next();  //dung de phat bai dau tien
    danghat=true;
  }
  Serial.print(vplaypause);
  delay(500); 
  if(vplaypause==0 )
  {
    if(millis() - timer > 200 && hat==1)
      {
        timer=millis();hat++;
        myDFPlayer.pause();
        danghat=false;
        toi=1;
        lui=1;
        
      }
     else if(millis() - timer > 200 && hat==2){
        timer=millis();
        danghat=true;
        myDFPlayer.start();
        hat=1;
        toi=1;
        lui=1;
        
      }
  }
  if(vpre==0){
      if(millis() - timer > 200 && lui==1)
      {
        timer=millis();lui=1;
        myDFPlayer.previous();
        danghat=true;
        hat=1;
        toi=1;
        
      }
    }
  if(vnext==0){
      if(millis() - timer > 200 && toi==1)
      {
        timer=millis();toi=1;
        myDFPlayer.next();
        danghat=true;
        hat=1;
        lui=1;
      }
    }
  
  if (myDFPlayer.available()) {
  if (myDFPlayer.readType()==DFPlayerPlayFinished) {
    Serial.println(myDFPlayer.read());
    Serial.println(F("next--------------------"));
     myDFPlayer.next();  //Play next mp3 every 3 second.
    Serial.println(F("readCurrentFileNumber--------------------"));
    Serial.println(myDFPlayer.readCurrentFileNumber()); //read current play file number
    delay(500);
  }
 } 
 

}
