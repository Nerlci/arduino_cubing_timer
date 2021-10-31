#ifndef __TIMER_BUTTONS__
#define __TIMER_BUTTONS__

#include <Arduino.h>

#define MODE_SIZE 6

class Buttons {
  int pin;
  void (*events[MODE_SIZE])();

  Buttons();

  Buttons(int _pin);

  void attach(int _pin); //attach Buttons object to pin
  void attachEvent(int MODE, void (*_event)()); //attach function to specific event
      //see also: Arduino.h
  void check(); //check pin state
};

#endif