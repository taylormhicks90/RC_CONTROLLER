#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include<RF24.h>
#include "StickValues.h"

struct DATA_PACKET {
  StickValues stick1;
  StickValues stick2;
};

void printData(DATA_PACKET data);
#endif