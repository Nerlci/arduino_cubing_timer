#ifndef __TIMER_UTILS__
#define __TIMER_UTILS__

#include <Arduino.h>

inline int getd(int pin) {
  pinMode(pin, INPUT);
  return digitalRead(pin);
}
inline int geta(int pin) {
  pinMode(pin, INPUT);
  return analogRead(pin);
}
inline void putd(int pin, int level) {
  pinMode(pin, OUTPUT);
  digitalWrite(pin, level);
}
inline void puta(int pin, int level) {
  pinMode(pin, OUTPUT);
  ledcWrite(pin, level);
}

#endif