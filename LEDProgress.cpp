/*
  LEDProgress.cpp - Library for simulating progress indication with LEDs
  Created by Rui Andrade, June 2017.
  Released into the public domain.
*/

#include <stdlib.h>
#include "Arduino.h"
#include "LEDProgress.h"

LEDProgress::LEDProgress(int leds[], int nleds, int maxprog) {
	// Copy data into the class (leds array will only point to argument, not copied)
	_nleds = nleds;
	_maxprog = maxprog;
	_leds = leds;

	// Set LEDs up as PWM to allow partial lighting
	for (int i = 0; i < _nleds; i++) {
		pinMode(_leds[i], OUTPUT);
	}

	// Create buckets to store progress (fade value)
	_buckets = (int*) malloc(_nleds * sizeof(int));
	for (int i = 0; i  < _nleds; i++) _buckets[i] = 0;
	_ledprog = _maxprog / _nleds;
}

void LEDProgress::setProgress(int prog) {
	// Store progress
	_prog = prog;

	int i = 0;
	int full_leds = _prog / _ledprog;

	// Fill up LEDs and calculate remainder progress
	for (i = 0; i < full_leds; i++) _buckets[i] = 255; 
	int remainder = _prog - (_ledprog * full_leds);
	float perc = (float) remainder / (float) _ledprog;

	// Fill up last necessary LED
	_buckets[i] = perc * 255;

	// Write fade values to LEDs	
	for (i = 0; i < _nleds; i++) analogWrite(_leds[i], _buckets[i]);
}

int LEDProgress::getProgress() {
	return _prog;
}