#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include "Functions.h"
#include "Thumbstick.h"
#include "StickValues.h"
#include "PinDefinitions.h"


Thumbstick s1(STICK_1_X,STICK_1_Y,STICK_1_S,STICK_1_C);
Thumbstick s2(STICK_2_X,STICK_2_Y,STICK_2_S,STICK_2_C);

RF24 radio(RF_CE, RF_CSN); // CE, CSN

const byte address[6] = "00001";


DATA_PACKET data;

void setup() {
  //Serial.begin(9600);
  
  // setup the sticks
  s1.setup();
  s2.setup();
  
  // setup the radio
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
}

void loop() {
  if(s1.calibrated() && s2.calibrated()){
    data.stick1 = s1.getStickValues();
    data.stick2 = s2.getStickValues();
    radio.write(&data,sizeof(data));
  }
  delay(25);
}


