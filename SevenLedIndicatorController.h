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

private:
  ShiftRegister &shiftRegister;

  static constexpr uint8_t REGISTER_OFFSET = 8;
};
