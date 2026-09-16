#pragma once

#include <Arduino.h>

enum EventType : uint8_t
{
    EVENT_NONE = 0,

    // RFID
    EVENT_ACCESS_GRANTED,
    EVENT_MAXIM_CARD,
    EVENT_ACCESS_DENIED,

    // IR
    EVENT_IR_MUSIC,
    EVENT_IR_SERVO_OPEN,
    EVENT_IR_SERVO_CLOSE,
    EVENT_IR_SERVO_STOP,
    EVENT_IR_BTN_1,
    EVENT_IR_BTN_2,
    EVENT_IR_BTN_3,
    EVENT_IR_BTN_4,

    // Buttons
    EVENT_BUTTON_1,
    EVENT_BUTTON_2,
    EVENT_BUTTON_3,
    EVENT_BUTTON_4,
    EVENT_BUTTON_5,
    EVENT_BUTTON_6,
    EVENT_BUTTON_7,
    EVENT_BUTTON_8,

    //События открывания дверей
    DOOR_OPENING_START,
    DOOR_OPENING_STOP,
    DOOR_CLOSING_START,
    DOOR_CLOSING_STOP,


};

struct Event
{
    EventType type;
};

void emitEvent(EventType type);

bool getEvent(Event &event);