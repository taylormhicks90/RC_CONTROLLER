#include "Thumbstick.h"

Thumbstick::Thumbstick(byte xPin,byte yPin, byte switchPin, byte ledPin){
  this->xPin = xPin;
  this->yPin = yPin;
  this->switchPin = switchPin;
  this->ledPin = ledPin;
  init();
}

void Thumbstick::init()
{
  pinMode(xPin, INPUT);
  pinMode(yPin, INPUT)
  pinMode(switchPin, INPUT_PULLUP);
  pinMode(ledPin,OUTPUT);

}

void Thumbstick::setup()
{
  xTrim = getNormalizedInput(xPin) * -1;
  yTrim = getNormalizedInput(yPin) * -1;
  digitalWrite(ledPin,LOW);
}

bool Thumbstick::calibrated(){
  if(isCalibrated) return true;
  calibrate();
  return false;
}

void Thumbstick::calibrate(){
  int xValue = getTrimmedInput(xPin,xTrim);
  int yValue = getTrimmedInput(yPin,yTrim);
  if(xValue < xMin) xMin = xValue; 
  if(xValue > xMax) xMax = xValue;
  if(yValue < yMin) yMin = yValue;
  if(yValue > yMax) yMax = yValue;
  if(getSwitch()){
    isCalibrated = true;
    digitalWrite(ledPin,HIGH);
  } 
}

int Thumbstick::getNormalizedInput(byte pin)
{
  return analogRead(pin) - 512;
}

int Thumbstick::getTrimmedInput(byte pin, int trim){
  int value =  getNormalizedInput(pin) + trim;
  return applyDeadzone(value);
}

int Thumbstick::applyDeadzone(int value){
  if (value >= -2 && value <= 2) value = 0;
  return value;
}

int Thumbstick::getCalibratedInput(byte pin, int trim, int axisMin, int axisMax){
  if(!calibrated()) return 0;
  int value = getTrimmedInput(pin, trim);
  int calibratedValue =  map(value,axisMin,axisMax, -1 * calibratedRange, calibratedRange);
  return applyDeadzone(calibratedValue);
}

bool Thumbstick::getSwitch()
{
  return ! digitalRead(switchPin);
}

int Thumbstick::getX()
{
  int value = getCalibratedInput(xPin,xTrim,xMin,xMax);
  if(xInverted) return value * -1;
  return value;
}

int Thumbstick::getY()
{
  int value = getCalibratedInput(yPin,yTrim,yMin,yMax);
  if(yInverted) return value * -1;
  return value;
}

StickValues Thumbstick::getStickValues(){
   return StickValues(getX(),  getY(), getSwitch());
}

void Thumbstick::setXInverted(bool inverted)
{
  this->xInverted = inverted;
}

void Thumbstick::setYInverted(bool inverted)
{
  this->yInverted = inverted;
}