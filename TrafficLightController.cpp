#include "TrafficLightController.h"

TrafficLightController::TrafficLightController(
  ShiftRegister &shiftRegister,
  uint8_t redBit,
  uint8_t yellowBit,
  uint8_t greenBit)
  : shiftRegister(shiftRegister),
    redBit(redBit),
    yellowBit(yellowBit),
    greenBit(greenBit) {
}

void TrafficLightController::begin() {
  off();
}

void TrafficLightController::writeColor(Color color) {
  shiftRegister.setBit(redBit, false);
  shiftRegister.setBit(yellowBit, false);
  shiftRegister.setBit(greenBit, false);

  switch (color) {
    case RED:
      shiftRegister.setBit(redBit, true);
      break;
    case YELLOW:
      shiftRegister.setBit(yellowBit, true);
      break;
    case GREEN:
      shiftRegister.setBit(greenBit, true);
      break;
    case OFF:
    default:
      break;
  }

  shiftRegister.write();
}

void TrafficLightController::setColor(Color color) {
  writeColor(color);
}

void TrafficLightController::off() {
  timed = false;

  writeColor(OFF);
}

void TrafficLightController::update() {
  if (!timed) {
    return;
  }

}


