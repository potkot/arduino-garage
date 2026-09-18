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
    case IR_BTN_NUMBER_SIGN:
      emitEvent(EVENT_IR_BTN_NUMBER_SIGN);
      break;
    case IR_BTN_ASTERISK:
      emitEvent(EVENT_IR_BTN_ASTERISK);
      break;
    case IR_BTN_ARROW_RIGHT:
      emitEvent(EVENT_IR_BTN_ARROW_RIGHT);
      break;
    case IR_BTN_ARROW_LEFT:
      emitEvent(EVENT_IR_BTN_ARROW_LEFT);
      break;
    case IR_BTN_ARROW_DOWN:
      emitEvent(EVENT_IR_BTN_ARROW_DOWN);
      break;
    case IR_BTN_ARROW_TOP:
      emitEvent(EVENT_IR_BTN_ARROW_TOP);
      break;
    case IR_BTN_OK:
      emitEvent(EVENT_IR_BTN_OK);
      /**
       * @todo Убрать после
       */
      emitEvent(EVENT_ACCESS_GRANTED);
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
    case IR_BTN_5:
      emitEvent(EVENT_IR_BTN_5);
      break;
    case IR_BTN_6:
      emitEvent(EVENT_IR_BTN_6);
      break;
    case IR_BTN_7:
      emitEvent(EVENT_IR_BTN_7);
      break;
    case IR_BTN_8:
      emitEvent(EVENT_IR_BTN_8);
      break;
    case IR_BTN_9:
      emitEvent(EVENT_IR_BTN_9);
      break;
    case IR_BTN_0:
      emitEvent(EVENT_IR_BTN_0);
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
