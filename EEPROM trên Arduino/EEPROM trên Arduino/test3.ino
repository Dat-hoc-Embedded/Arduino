
#include <EEPROM.h>

void setup() 
{
  for (int diachi = 0 ; diachi < EEPROM.length() ; diachi++) 
  {
    EEPROM.write(diachi, 0);
  }

}

void loop() 
{
  /** Empty loop. **/
}
