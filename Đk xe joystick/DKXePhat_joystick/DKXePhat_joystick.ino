
#include <VirtualWire.h> // khai báo thư viện VirtualWire
int trucX;
int trucY;

void setup()
{
 
  
  Serial.begin(9600);// giao tiếp Serial với baudrate 9600
  Serial.println("Ready.........");
  vw_set_ptt_inverted(true);// yêu cầu cho RF link modules
  vw_setup(1024);// cài đặt tốc độ truyền tín hiệu
  vw_set_tx_pin(8);// cài đặt chân digital để phát tín hiệu------------------------------------------------------------------
}

void loop()
{
  trucX = analogRead(A1);
  trucY = analogRead(A2);
  
  Serial.println(trucX);
  Serial.println(trucY);
  
  char text[20] = "";// khai báo string dạng array
  byte i = 0;
  
  sprintf(text,"%d,%d",trucX, trucY); 
    
  
  Serial.print("sent: ");
  Serial.println(text);
  vw_send((uint8_t *)text, sizeof(text));// gửi tín hiệu đi
  vw_wait_tx();
  delay(100);
}
