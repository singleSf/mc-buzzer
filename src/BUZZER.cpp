using namespace std;

#ifndef BUZZER_INIT
#define BUZZER_INIT true

#include "BUZZER.h"

BUZZER::BUZZER(byte _pin) {
  __pin = _pin;

  pinMode(__pin, OUTPUT);
  digitalWrite(__pin, LOW);
}

BUZZER::~BUZZER() {}

void BUZZER::__end(uint32_t _delay) {
  noTone(__pin);

  if (_delay) {
    delay(_delay);
  }
}

void BUZZER::question(uint32_t _delayAfter) {
  for (byte i = 1; i < 4; i++) {
    tone(__pin, 500 * i);
    delay(100);
  }

  __end(_delayAfter);
}

void BUZZER::no(uint32_t _delayAfter) {
  for (byte i = 0; i < 2; i ++) {
    tone(__pin, 500);
    delay(100);
    noTone(__pin);
    delay(100);
  }

  __end(_delayAfter);
}

void BUZZER::ok(uint32_t _delayAfter) {
  for (word i = 2000; i <= 2500; i += 100) {
    tone(__pin, i);
    delay(100);
  }

  __end(_delayAfter);
}

void BUZZER::cancel(uint32_t _delayAfter) {
  for (word i = 2500; i >= 2000; i -= 100) {
    tone(__pin, i);
    delay(100);
  }

  __end(_delayAfter);
}

void BUZZER::alarm(uint32_t _delayAfter) {
  for (byte i = 0; i < 2; i++) {
    for (byte x = 0; x < 180; x++) {
      double sinVal  = sin(x * (3.1412 / 180));
      word   toneVal = 2000 + (int(sinVal * 1000));
      tone(__pin, toneVal);
    }
    delay(100);
  }

  __end(_delayAfter);
}

void BUZZER::done(uint32_t _delayAfter) {
  tone(__pin, 1500);
  delay(100);
  tone(__pin, 2500);

  __end(_delayAfter);
}

void BUZZER::refuse(uint32_t _delayAfter) {
  for (word i = 0; i < 5; i++) {
    tone(__pin, 775);
    delay(100);
    noTone(__pin);
    delay(100);
  }

  __end(_delayAfter);
}

void BUZZER::ping(uint32_t _delayAfter) {
  tone(__pin, 1000);
  delay(100);

  __end(_delayAfter);
}

void BUZZER::pong(uint32_t _delayAfter) {
  tone(__pin, 500);
  delay(100);
  
  __end(_delayAfter);
}

void BUZZER::in(uint32_t _delayAfter) {
  for(word i = 700; i < 2000; i++){
    tone(__pin, i);
  }

  __end(_delayAfter);
}

void BUZZER::out(uint32_t _delayAfter) {
  for(word i = 2000; i > 700; i--){
    tone(__pin, i);
  }

  __end(_delayAfter);
}

#endif