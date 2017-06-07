/*
  LEDProgress.h - Library for simulating progress indication with LEDs
  Created by Rui Andrade, June 2017.
  Released into the public domain.
*/

#ifndef LEDProgress_h
#define LEDProgress_h

#include "Arduino.h"

class LEDProgress
{
  public:
   	LEDProgress(int leds[], int nleds, int maxprog);
    void setProgress(int prog);
    int getProgress();

  private:
    int* _leds; // led pins - will point to the array passed in the constructor
    int _nleds; // number of leds
    int _maxprog; // maximum progress in total
    int _prog; // current progress
    int* _buckets; // fade values for each led
    int _ledprog; // how much progress each led represents
};

#endif