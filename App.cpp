#include "App.h"

#include "Events.h"
#include "Config.h"

#include "ServoController.h"
#include "SoundController.h"
#include "LedController.h"
#include "TrafficLightController.h"

extern ServoController servos;
extern SoundController sound;
extern LedController led;
extern TrafficLightController trafficLight;


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
        closeAt = millis() + 5000;

        break;
      case EVENT_MAXIM_CARD:
        led.setColorFor(LedController::BLUE, LED_ACCESS_TIME * 4);
        sound.playMissionImpossible();
        break;
      case EVENT_ACCESS_DENIED:
        sound.beep(1200, BEEP_TIME);
        led.setColorFor(LedController::RED, LED_ACCESS_TIME);
        break;
      case EVENT_IR_MUSIC:
        sound.playMissionImpossible();
        break;
      case EVENT_IR_SERVO_OPEN:
        servos.open();
        led.setColorFor(LedController::GREEN, LED_ACCESS_TIME);
        break;
      case EVENT_IR_SERVO_CLOSE:
        servos.close();
        led.setColorFor(LedController::RED, LED_ACCESS_TIME);
        break;
      case EVENT_IR_SERVO_STOP:
        servos.stop();
        led.off();
        break;
      case EVENT_IR_BTN_1:
        trafficLight.off();
        trafficLight.setColor(TrafficLightController::RED);
        break;
      case EVENT_IR_BTN_2:
        trafficLight.off();
        trafficLight.setColor(TrafficLightController::YELLOW);
        break;
      case EVENT_IR_BTN_3:
        trafficLight.off();
        trafficLight.setColor(TrafficLightController::GREEN);
        break;
      case EVENT_IR_BTN_4:
        trafficLight.off();
        break;
      case EVENT_NONE:
      default:
        break;
    }
  }

  if (closeAfterOpen) {
    unsigned long now = millis();

    if ((long)(now - closeAt) >= 0) {
      servos.close();
      led.setColorFor(LedController::RED, LED_ACCESS_TIME);
      closeAfterOpen = false;
    }
  }
}