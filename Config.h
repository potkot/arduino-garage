#pragma once

#include <Arduino.h>

// RFID модуль MFRC522
constexpr uint8_t RFID_RST_PIN = 4;
constexpr uint8_t RFID_SS_PIN = 10;

// Сдвиговый регистр
constexpr uint8_t REGISTER_DATA_PIN = 6;
constexpr uint8_t REGISTER_CLOCK_PIN = 3;
constexpr uint8_t REGISTER_LATCH_PIN = 5;

// RGB светодиод на сдвиговом регистре
constexpr uint8_t REGISTER_LED_BLUE = 0;
constexpr uint8_t REGISTER_LED_RED = 1;
constexpr uint8_t REGISTER_LED_GREEN = 2;

// Светодиоды для светофора на сдвиговом регистре
constexpr uint8_t REGISTER_TRAFFIC_LIGHT_RED = 4;
constexpr uint8_t REGISTER_TRAFFIC_LIGHT_YELLOW = 5;
constexpr uint8_t REGISTER_TRAFFIC_LIGHT_GREEN = 3;

// Piezo пищалка
constexpr uint8_t PIEZO_PIN = 8;

// Сервоприводы
constexpr uint8_t SERVO1_PIN = 7;
constexpr uint8_t SERVO2_PIN = 9;

// ИК приемник
constexpr uint8_t IR_PIN = 2;

// Сдвиговый регистр 74HC165
constexpr uint8_t BUTTON_DATA_PIN = A0;
constexpr uint8_t BUTTON_CLOCK_PIN = A1;
constexpr uint8_t BUTTON_LATCH_PIN = A2;

constexpr uint8_t BUTTON_COUNT = 8;


// ИК комманды

constexpr uint8_t IR_BTN_ARROW_LEFT = 0x8;
constexpr uint8_t IR_BTN_ARROW_RIGHT = 0x5A;
constexpr uint8_t IR_BTN_ARROW_DOWN = 0x52;
constexpr uint8_t IR_BTN_1 = 0x45;
constexpr uint8_t IR_BTN_2 = 0x46;
constexpr uint8_t IR_BTN_3 = 0x47;
constexpr uint8_t IR_BTN_4 = 0x44;
constexpr uint8_t IR_BTN_5 = 0x40;
constexpr uint8_t IR_BTN_6 = 0x43;
constexpr uint8_t IR_BTN_7 = 0x7;
constexpr uint8_t IR_BTN_8 = 0x15;
constexpr uint8_t IR_BTN_9 = 0x9;
constexpr uint8_t IR_BTN_0 = 0x19;
constexpr uint8_t IR_BTN_ASTERISK = 0x16;
constexpr uint8_t IR_BTN_NUMBER_SIGN = 0xD;
constexpr uint8_t IR_BTN_ARROW_TOP = 0x18;
constexpr uint8_t IR_BTN_OK = 0x1C;

// RFID карты
constexpr uint8_t ACCESS_UID[] = {0x43, 0xFE, 0x3F, 0x38};
constexpr uint8_t MAXIM_UID[] = {0x34, 0xD7, 0xDF, 0xC1, 0x91, 0x9F, 0x70};


// Тайминги

constexpr unsigned long BUTTON_SCAN_INTERVAL = 10;
constexpr unsigned long BUTTON_DEBOUNCE_TIME = 30;

constexpr unsigned long SERVO_STEP_INTERVAL = 15;

constexpr unsigned long LED_ACCESS_TIME = 2000;
constexpr unsigned long LED_DENIED_TIME = 1000;
constexpr unsigned long LED_MAXIM_TIME = 1000;

constexpr unsigned long BEEP_TIME = 120;

constexpr unsigned long TRAFFIC_LIGHT_TIME = 3000;

// Семисегментный индикатор
static constexpr uint8_t DIGIT_MASKS_DOT = 0b00000000;

static constexpr uint8_t DIGIT_MASKS[10] = {
  0b00111111, // 0
  0b00000110, // 1
  0b01011011, // 2
  0b01001111, // 3
  0b01100110, // 4
  0b01101101, // 5
  0b01111101, // 6
  0b00000111, // 7
  0b01111111, // 8
  0b01101111 // 9
};

constexpr unsigned long WAITING_BEFORE_DOORS_CLOSE = 9000;
constexpr unsigned long WAITING_BEFORE_DOORS_CLOSE_TIME_START = 9;
