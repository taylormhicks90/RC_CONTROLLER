#include "Functions.h"

void setupRadio(RF24 radio, byte address[]){
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
}

// void printData(DATA_PACKET data)
// {
//   Serial.print(data.x1);
//   Serial.print('\t');
//   Serial.print(data.y1);
//   Serial.print('\t');
//   Serial.print(data.s1);
//   Serial.print('\t');
//   Serial.print(data.x2);
//   Serial.print('\t');
//   Serial.print(data.y2);
//   Serial.print('\t');
//   Serial.println(data.s2);
// }