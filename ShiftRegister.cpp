#include "ShiftRegister.h"

ShiftRegister::ShiftRegister(
  uint8_t dataPin,
  uint8_t clockPin,
  uint8_t latchPin)
  : dataPin(dataPin),
    clockPin(clockPin),
    latchPin(latchPin) {
}

void ShiftRegister::begin() {
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(latchPin, OUTPUT);

  state = 0;

  write();
}

void ShiftRegister::setBit(uint8_t bit, bool value) {
  if (bit > 15) {
    return;
  }

  if (value) {
    state |= (1UL << bit);
  } else {
    state &= ~(1UL << bit);
  }
}

void ShiftRegister::clearBit(uint8_t bit) {
  setBit(bit, false);
}

void ShiftRegister::write() {
  digitalWrite(latchPin, LOW);

  // Второй регистр
  shiftOut(dataPin, clockPin, MSBFIRST, (state >> 8) & 0xFF);

  // Первый регистр
  shiftOut(dataPin, clockPin, MSBFIRST, state & 0xFF);

  digitalWrite(latchPin, HIGH);
}
