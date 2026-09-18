#include "SevenLedIndicatorController.h"

#include "Config.h"

SevenLedIndicatorController::SevenLedIndicatorController(
  ShiftRegister &shiftRegister)
  : shiftRegister(shiftRegister) {
}

void SevenLedIndicatorController::begin() {
  off();
}

void SevenLedIndicatorController::show(uint8_t digit) {
  if (digit > 9) {
    off();
    return;
  }

  uint8_t mask = DIGIT_MASKS[digit];


  // Очистить второй регистр.
  for (uint8_t bit = 0; bit < 8; bit++) {
    shiftRegister.clearBit(REGISTER_OFFSET + bit);
  }

  for (uint8_t bit = 0; bit < 7; bit++) {
    if (mask & (1 << bit)) { shiftRegister.setBit(REGISTER_OFFSET + bit, true); }
  }

  shiftRegister.write();
}

void SevenLedIndicatorController::countdown() {
  countdownStart = true;

  currentDigit = WAITING_BEFORE_DOORS_CLOSE_TIME_START;

  offAt = millis() + WAITING_BEFORE_DOORS_CLOSE;
  changeDigit = millis() + 1000;

  show(currentDigit);
}

void SevenLedIndicatorController::showDot() {
}

void SevenLedIndicatorController::update() {
  if (countdownStart) {
    if ((long) (millis() - changeDigit) >= 0) {
      changeDigit = millis() + 1000;
      currentDigit = currentDigit - 1;
      show(currentDigit);
      show(currentDigit);
    }

    if ((long) (millis() - offAt) >= 0) {
      off();
      countdownStart = false;
    }
  }
}

void SevenLedIndicatorController::off() {
  shiftRegister.clearBit(8);
  shiftRegister.clearBit(9);
  shiftRegister.clearBit(10);
  shiftRegister.clearBit(11);
  shiftRegister.clearBit(12);
  shiftRegister.clearBit(13);
  shiftRegister.clearBit(14);
  shiftRegister.clearBit(15);
  shiftRegister.write();
}
