#include "StickValues.h"

StickValues::StickValues(int xValue, int yValue, bool switchValue){
  this->xAxis = (int) xValue;
  this->yAxis = (int) yValue;
  this->switchValue = switchValue;
}