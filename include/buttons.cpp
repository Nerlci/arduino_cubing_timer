#include <buttons.h>

#include <Arduino.h>

Buttons::Buttons() {
  //
}

Buttons::Buttons(int _pin) {
  pinMode(_pin, INPUT);
  this->pin = _pin;
}

void Buttons::attach(int _pin) {
  pinMode(_pin, INPUT);
  this->pin = _pin;
  state=digitalRead(_pin);
}

void Buttons::attachEvent(int MODE, void (*_event)()){
  this->attached[MODE] = true;
  this->events[MODE] = _event;
  
}

void Buttons::check(){
  int _state = digitalRead(this->pin), event;
  if (_state!=state)
  {
    delay(20);
    if (_state!=state)
    {
      attachEvent(CHANGE, *events);
      MODE = state==HIGH? FALLING: RISING;
    }
  }
  else if (_state==state)
  {
    delay(20);
    MODE = state==HIGH? ONHIGH: ONLOW; 
  }

  if (_state!=state)
  {
    state=_state;
  }
  attachEvent(MODE, *events);
}