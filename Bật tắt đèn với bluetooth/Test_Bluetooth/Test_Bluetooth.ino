#include <SoftwareSerial.h>
 
#define TX_PIN      7//nghia la rxd vao chan 7
#define RX_PIN      6//nghia la txd vao chan 6
char value; 
SoftwareSerial bluetooth(TX_PIN, RX_PIN);
int baudRate[] = {300, 1200, 2400, 4800, 9600, 19200, 38400, 57600, 115200};
 
void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);  
  while (!Serial) {}
  
  Serial.println("Configuring, please wait...");
  
  for (int i = 0 ; i < 9 ; i++) {
     bluetooth.begin(baudRate[i]);
     String cmd = "AT+BAUD4";
     bluetooth.print(cmd);
     bluetooth.flush();
     delay(100);
  }
  
  bluetooth.begin(9600);
  Serial.println("Config done");
  while (!bluetooth) {}
  
  Serial.println("Enter AT commands:");
}
 
void loop() {
  value="";
  if (bluetooth.available()) {
    
    value=bluetooth.read();
    Serial.write(value);
    if(value == '1')             
      digitalWrite(13, HIGH);  
    else if(value == '0')       
      digitalWrite(13, LOW);
  }
  
}
