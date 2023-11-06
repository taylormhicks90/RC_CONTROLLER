#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include<RF24.h>

struct DATA_PACKET {
  short x1 = 0;
  short y1 = 0;
  bool s1 = false;
  short x2 = 0;
  short y2 = 0;
  bool s2 = false;
};

void printData(DATA_PACKET data);
#endif