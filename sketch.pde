#include <IRremote.h>

//use pin 9/10 to control up/down
const int upPin = 9;
const int downPin = 10;

//IR receiver pin 11
const int RECV_PIN = 11;
IRrecv irrecv(RECV_PIN);

decode_results results;

//change the hex code here
unsigned long upButton = 0x123456;
unsigned long downButton = 0x654321;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn();
  pinMode(upPin, OUTPUT);
  pinMode(downPin, OUTPUT);
}
 
void loop()
{
  if (irrecv.decode(&results)) 
  {
    Serial.println(results.value, HEX);
    
    if(results.value == upButton)
    {
      digitalWrite(upPin, HIGH);
      Serial.println("Motor up");
    }
    else if(results.value == downButton)
    {
      digitalWrite(downPin, HIGH);
      Serial.println("Motor down");
    }
    
    irrecv.resume();
  }
  else
  {
    digitalWrite(upPin, LOW);
    digitalWrite(downPin, LOW);
  }
  
  delay(50);
}
