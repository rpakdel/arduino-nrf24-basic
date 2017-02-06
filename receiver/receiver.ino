/*
* Basic example sourced from RF library example
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
    Serial.println(F("Receiver"));

    radio.begin();
    radio.setPALevel(RF24_PA_MIN);
    radio.setAutoAck(1);
    radio.setRetries(15, 15);
    radio.openReadingPipe(0, addresses[0]);
    radio.startListening();
}

void loop()
{      
    while (radio.available())
    {      
      uint8_t buffer;
      radio.read((uint8_t*)&buffer, sizeof(uint8_t));    
      Serial.print(F("Receiver: "));
      Serial.println(buffer);
    }
}
