//Before using this sketch, you need to upload a value to EEPROM 0
//Run initEEPROM.ino before this sketch

#include <IRremote.h>
#include <EEPROM.h>

//change motor max time here (ms)
const unsigned long maxTime = 10000;
unsigned long nowTime;

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

bool flag = false;

void setup()
{
    Serial.begin(9600);
    irrecv.enableIRIn();
    pinMode(upPin, OUTPUT);
    pinMode(downPin, OUTPUT);
    EEPROM.get(0, nowTime);
}

void loop()
{
    unsigned long from;
    from = millis();

    if (irrecv.decode(&results))
    {
        Serial.println(results.value, HEX);

        if(results.value == upButton)
        {
            if(nowTime <= maxTime)
            {
                digitalWrite(upPin, HIGH);
                Serial.println("Motor up");
                nowTime = nowTime + (millis() - from) + 50;
                flag = true;
            }
            else
            {
                Serial.println("Motor up to max");
                digitalWrite(upPin, LOW);
                digitalWrite(downPin, LOW);
                EEPROM.put(0, nowTime);
                flag = false;
            }
        }
        else if(results.value == downButton)
        {
            if(nowTime >= 0)
            {
                digitalWrite(downPin, HIGH);
                Serial.println("Motor down");
                nowTime = nowTime - (millis() - from) - 50;
                flag = true;
            }
            else
            {
                Serial.println("Motor down to max");
                digitalWrite(upPin, LOW);
                digitalWrite(downPin, LOW);
                EEPROM.put(0, nowTime);
                flag = false;
            }
        }

        irrecv.resume();
    }
    else if(flag)
    {
        digitalWrite(upPin, LOW);
        digitalWrite(downPin, LOW);
        EEPROM.put(0, nowTime);
        flag = false;
    }

    delay(50);
}
