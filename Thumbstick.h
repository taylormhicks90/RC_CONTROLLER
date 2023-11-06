#ifndef THUMBSTICK_H
#define THUMBSTICK_H

#include <Arduino.h>
#include "StickValues.h"

class Thumbstick{

  private:
    byte xPin;
    byte yPin;
    byte switchPin;
    byte ledPin;
    int xTrim = 0;
    int yTrim = 0;
    bool yInverted = false;
    bool xInverted = false;
    int xMin = 0;
    int xMax = 0;
    int yMin = 0;
    int yMax = 0;
    bool isCalibrated = false;
    const static int calibratedRange = 100;
    int getNormalizedInput(byte pin);
    int getTrimmedInput(byte pin, int trim);
    int applyDeadzone(int value);
    int getCalibratedInput(byte pin, int trim, int axisMin, int axisMax);
    void calibrate();


  public:
    Thumbstick(byte xPin,byte yPin, byte switchPin, byte ledPin);
    void init();
    void setup();
    //void setTrim(int x, int y);
    int getX();
    int getY();
    bool getSwitch();
    void setYInverted(bool inverted);
    void setXInverted(bool inverted);
    bool calibrated();
    StickValues getStickValues();
};
#endif