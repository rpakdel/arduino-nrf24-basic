 /*
* Basic sender based on RF24 example
*/

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

#define CEPIN 9
#define CSPIN 10

RF24 radio(CEPIN, CSPIN);
byte addresses[][6] = { "1Node" };

void setup() 
{    
    Serial.begin(115200);
    Serial.println(F("SENDER"));

    radio.begin();
    radio.setRetries(15, 15);
    radio.setPALevel(RF24_PA_HIGH);
    radio.openWritingPipe(addresses[0]);
    radio.stopListening();
}

uint8_t count = 0;
void loop()
{
  Serial.print(F("Sender: "));
    Serial.print(count);
    if (!radio.write((uint8_t*)&count, sizeof(uint8_t)))
    {
       Serial.println(F("...no ack"));
    }
    else
    {
      Serial.println(F("...ack"));
    }   

    count++;
    delay(250);
}
