//before LED turns on, don't power off the arduino

#include <EEPROM.h>

void setup()
{
  pinMode(13, OUTPUT);
  
  for (int i = 0 ; i < EEPROM.length() ; i++)
  {
    EEPROM.write(i, 0);
  }

  unsigned long nowTime = 0;
  
  EEPROM.put(0, nowTime);

  digitalWrite(13, HIGH);
}

void loop()
{

}
