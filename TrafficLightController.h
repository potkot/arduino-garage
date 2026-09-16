#pragma once

#include <Arduino.h>
#include "ShiftRegister.h"


class TrafficLightController {
public:
  enum Color : uint8_t {
    OFF,
    RED,
    YELLOW,
    GREEN,
  };

  TrafficLightController(
    ShiftRegister &shiftRegister,
    uint8_t redBit,
    uint8_t yellowBit,
    uint8_t greenBit);

  void begin();

  void setColor(Color color);

  void setColorFor(Color color, unsigned long durationMs);

  void off();

  void update();

private:
  ShiftRegister &shiftRegister;
  uint8_t redBit;
  uint8_t yellowBit;
  uint8_t greenBit;

  bool timed = false;

  unsigned long offAt = 0;

  void writeColor(Color color);
};
