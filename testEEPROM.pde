//If EEPROM works well, you will see "Float read:123.456" in monitor

#include <EEPROM.h>

void setup()
{
  Serial.begin(9600);

  float f = 123.456;
  int eeAddress = 0;
  
  EEPROM.put(eeAddress, f);

  Serial.println("Written float data type!");

  float readf = 0;

  EEPROM.get(eeAddress, readf);

  Serial.print("Float read:");
  Serial.println(readf);
  
}

void loop()
{
  
}
