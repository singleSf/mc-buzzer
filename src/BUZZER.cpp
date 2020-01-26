using namespace std;

#ifndef BUZZER_INIT
#define BUZZER_INIT true

#include "BUZZER.h"

BUZZER::BUZZER(byte _pin) {
  this->__pin = _pin;

  this->setEnable(true);

  pinMode(__pin, OUTPUT);
  digitalWrite(__pin, LOW);
}

BUZZER::~BUZZER() {}

void BUZZER::setEnable(bool _isEnable) {
  this->__isEnable = _isEnable;
}

void BUZZER::__toneStart(uint32_t _frequency) {
  if(!this->__isEnable){
    return;
  }
  
  tone(this->__pin, _frequency);
}

void BUZZER::__toneEnd() {
  if(!this->__isEnable){
    return;
  }
  
  noTone(this->__pin);
}

void BUZZER::__delay(uint32_t _milliSeconds, uint32_t _microSeconds) {
  if(!this->__isEnable){
    return;
  }
  
  if(_milliSeconds){
    delay(_milliSeconds);
  }else if(_microSeconds){
    delayMicroseconds(_microSeconds);
  }
}

void BUZZER::__end(uint32_t _delay) {
  this->__toneEnd();

  if (_delay) {
    this->__delay(_delay);
  }
}

void BUZZER::question(uint32_t _delayAfter) {
  for (byte i = 1; i < 4; i++) {
    this->__toneStart(500 * i);
    this->__delay(100);
  }

  this->__end(_delayAfter);
}

void BUZZER::no(uint32_t _delayAfter) {
  for (byte i = 0; i < 2; i ++) {
    this->__toneStart(500);
    this->__delay(100);
    this->__toneEnd();
    this->__delay(100);
  }

  this->__end(_delayAfter);
}

void BUZZER::ok(uint32_t _delayAfter) {
  for (word i = 2000; i <= 2500; i += 100) {
    this->__toneStart(i);
    this->__delay(100);
  }

  this->__end(_delayAfter);
}

void BUZZER::cancel(uint32_t _delayAfter) {
  for (word i = 2500; i >= 2000; i -= 100) {
    this->__toneStart(i);
    this->__delay(100);
  }

  this->__end(_delayAfter);
}

void BUZZER::alarm(uint32_t _delayAfter) {
  for (byte i = 0; i < 2; i++) {
    for (byte x = 0; x < 180; x++) {
      double sinValue  = sin(x * (3.1412 / 180));
      word   frequency = 2000 + (word)(sinValue * 1000);
      this->__toneStart(frequency);
    }
    this->__delay(100);
  }

  this->__end(_delayAfter);
}

void BUZZER::done(uint32_t _delayAfter) {
  this->__toneStart(1500);
  this->__delay(100);
  this->__toneStart(2500);
  this->__delay(100);

  this->__end(_delayAfter);
}

void BUZZER::refuse(uint32_t _delayAfter) {
  for (word i = 0; i < 5; i++) {
    this->__toneStart(775);
    this->__delay(100);
    this->__toneEnd();
    this->__delay(100);
  }

  this->__end(_delayAfter);
}

void BUZZER::ping(uint32_t _delayAfter) {
  this->__toneStart(1000);
  this->__delay(100);

  this->__end(_delayAfter);
}

void BUZZER::pong(uint32_t _delayAfter) {
  this->__toneStart(500);
  this->__delay(100);
  
  this->__end(_delayAfter);
}

void BUZZER::in(uint32_t _delayAfter) {
  for(word i = 700; i < 2000; i++){
    this->__toneStart(i);
    this->__delay(0, 10);
  }

  this->__end(_delayAfter);
}

void BUZZER::out(uint32_t _delayAfter) {
  for(word i = 2000; i > 700; i--){
    this->__toneStart(i);
    this->__delay(0, 10);
  }

  this->__end(_delayAfter);
}

#endif