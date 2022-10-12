#pragma once

#include <MD_REncoder.h>

#include "../Debug.hpp"
#include "../Types.hpp"
#include "HID-Project.h"

#define ENABLE_PULLUPS 0

class RotaryEncoder {
 public:
  RotaryEncoder(uint8_t clk, uint8_t dt, uint8_t sw) : _rotary(dt, clk) {
    _clk = clk;
    _dt = dt;
    _sw = sw;
  };

  void setup();
  void loop();

 private:
  // Pins
  uint8_t _clk;
  uint8_t _dt;
  uint8_t _sw;

  // Rotary Lib
  MD_REncoder _rotary;

  // State
  unsigned long lastSwPress = 0;

  void readRotaryState();
  void readSwState();
  uint16_t speedVolumeMultiplier(uint16_t speed);
};
