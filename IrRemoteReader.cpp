#include "IrRemoteReader.h"

#include "Config.h"
#include "Events.h"
#include <IRremote.hpp>

IrRemoteReader::IrRemoteReader(uint8_t pin)
  : pin(pin) {
}


void IrRemoteReader::begin() {
  IrReceiver.begin(pin, ENABLE_LED_FEEDBACK);

  Serial.println(F("IrRemote initialized"));
}


void IrRemoteReader::update() {

  if (!IrReceiver.decode()) {
    return;
  }


  uint8_t command = IrReceiver.decodedIRData.command;

  switch (command) {
    case IR_CMD_MUSIC:
      emitEvent(EVENT_IR_MUSIC);
      break;
    case IR_CMD_OPEN:
      emitEvent(EVENT_IR_SERVO_OPEN);
      break;
    case IR_CMD_CLOSE:
      emitEvent(EVENT_IR_SERVO_CLOSE);
      break;
    case IR_CMD_STOP:
      emitEvent(EVENT_IR_SERVO_STOP);
      break;
    case IR_BTN_1:
      emitEvent(EVENT_IR_BTN_1);
      break;
    case IR_BTN_2:
      emitEvent(EVENT_IR_BTN_2);
      break;
    case IR_BTN_3:
      emitEvent(EVENT_IR_BTN_3);
      break;
    case IR_BTN_4:
      emitEvent(EVENT_IR_BTN_4);
      break;
    default:
      break;
  }


  IrReceiver.resume();
}

void IrRemoteReader::pause() {
  IrReceiver.stopTimer();
}

void IrRemoteReader::resume() {
  IrReceiver.restartTimer();
}