#pragma once

#include <Arduino.h>
#include "ShiftRegister.h"


class SevenLedIndicatorController {
public:
  SevenLedIndicatorController(ShiftRegister &shiftRegister);

  void begin();

  void show(uint8_t digit);

  void showDot();

  void off();

  void update();

  void countdown();

private:
  ShiftRegister &shiftRegister;

  static constexpr uint8_t REGISTER_OFFSET = 8;

  bool countdownStart = false;
  unsigned long currentDigit;
  unsigned long offAt = 0;
  unsigned long changeDigit = 0;

};
