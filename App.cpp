#include "App.h"

#include "Events.h"
#include "Config.h"

#include "ServoController.h"
#include "SoundController.h"
#include "LedController.h"
#include "TrafficLightController.h"
#include "SevenLedIndicatorController.h"

extern ServoController servos;
extern SoundController sound;
extern LedController led;
extern TrafficLightController trafficLight;
extern SevenLedIndicatorController sevenLedIndicator;


//Метки для автоматического открытия
namespace {
  bool closeAfterOpen = false;
  unsigned long closeAt = 0;
}


void processEvents() {
  Event event;

  while (getEvent(event)) {
    switch (event.type) {
      case EVENT_ACCESS_GRANTED:
        servos.open();
        led.setColorFor(LedController::GREEN, LED_ACCESS_TIME);

        closeAfterOpen = true;
        closeAt = millis() + WAITING_BEFORE_DOORS_CLOSE;

        break;
      case EVENT_MAXIM_CARD:
        led.setColorFor(LedController::BLUE, LED_ACCESS_TIME * 4);
        sound.playMissionImpossible();
        break;
      case EVENT_ACCESS_DENIED:
        sound.beep(1200, BEEP_TIME);
        led.setColorFor(LedController::RED, LED_ACCESS_TIME);
        break;
      case EVENT_IR_BTN_ASTERISK:
        sound.playMissionImpossible();
        break;
      case EVENT_IR_BTN_ARROW_RIGHT:
        servos.open();
        led.setColorFor(LedController::GREEN, LED_ACCESS_TIME);
        break;
      case EVENT_IR_BTN_ARROW_LEFT:
        servos.close();
        led.setColorFor(LedController::RED, LED_ACCESS_TIME);
        break;
      case EVENT_IR_BTN_ARROW_DOWN:
        servos.stop();
        led.off();
        break;
      case EVENT_IR_BTN_1:
        sevenLedIndicator.show(1);
        break;
      case EVENT_IR_BTN_2:
        sevenLedIndicator.show(2);
        break;
      case EVENT_IR_BTN_3:
        sevenLedIndicator.show(3);
        break;
      case EVENT_IR_BTN_4:
        sevenLedIndicator.show(4);
        break;
      case EVENT_IR_BTN_5:
        sevenLedIndicator.show(5);
        break;
      case EVENT_IR_BTN_6:
        sevenLedIndicator.show(6);
        break;
      case EVENT_IR_BTN_7:
        sevenLedIndicator.show(7);
        break;
      case EVENT_IR_BTN_8:
        sevenLedIndicator.show(8);
        break;
      case EVENT_IR_BTN_9:
        sevenLedIndicator.show(9);
        break;
      case EVENT_IR_BTN_0:
        sevenLedIndicator.show(0);
        break;
      case EVENT_IR_BTN_NUMBER_SIGN:
        sevenLedIndicator.off();
        break;
      case DOOR_OPENING_START:
        trafficLight.setColor(TrafficLightController::RED);
        break;
      case DOOR_OPENING_STOP:
        trafficLight.setColor(TrafficLightController::GREEN);

        if (closeAfterOpen) {
          sevenLedIndicator.countdown();
          closeAt = millis() + WAITING_BEFORE_DOORS_CLOSE;
        }
        break;
      case DOOR_CLOSING_START:
        trafficLight.setColor(TrafficLightController::RED);
        break;
      case DOOR_CLOSING_STOP:
        trafficLight.setColor(TrafficLightController::YELLOW);
        break;
      case EVENT_NONE:
      default:
        break;
    }
  }

  if (closeAfterOpen) {
    unsigned long now = millis();

    if ((long) (now - closeAt) >= 0) {
      servos.close();
      led.setColorFor(LedController::RED, LED_ACCESS_TIME);
      closeAfterOpen = false;
    }
  }
}
