#include "ServoController.h"

#include "Config.h"


ServoController::ServoController(
  uint8_t pin1,
  uint8_t pin2)
  : pin1(pin1),
    pin2(pin2) {
}


void ServoController::begin() {
  servo1.write(maxAngle);
  servo2.write(0);
}


void ServoController::open() {
  if (state == OPENING) {
    return;
  }

  servo1.attach(pin1);
  servo2.attach(pin2);

  state = OPENING;

  lastStepMs = millis();

  emitEvent(DOOR_OPENING_START);
}


void ServoController::close() {
  if (state == CLOSING) {
    return;
  }

  servo1.attach(pin1);
  servo2.attach(pin2);

  state = CLOSING;

  lastStepMs = millis();

  emitEvent(DOOR_CLOSING_START);
}


void ServoController::stop() {
  servo1.write(maxAngle - angle);
  servo2.write(angle);

  servo1.detach();
  servo2.detach();

  state = IDLE;
}


void ServoController::update() {
  if (state == IDLE) {
    return;
  }

  unsigned long now = millis();

  if (now - lastStepMs < SERVO_STEP_INTERVAL) {
    return;
  }

  lastStepMs = now;


  if (state == OPENING) {
    if (angle < maxAngle) {
      angle++;

      servo1.write(maxAngle - angle);
      servo2.write(angle);
    }

    if (angle >= maxAngle) {
      emitEvent(DOOR_OPENING_STOP);
      stop();
    }
  }


  else if (state == CLOSING) {
    if (angle > 0) {
      angle--;

      servo1.write(maxAngle - angle);
      servo2.write(angle);
    }

    if (angle <= 0) {
      emitEvent(DOOR_CLOSING_STOP);
      stop();
    }
  }
}