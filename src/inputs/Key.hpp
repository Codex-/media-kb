#pragma once

#include "../Debug.hpp"
#include "../Types.hpp"
#include "HID-Project.h"

class Key {
 public:
  Key(uint8_t pin) { _pin = pin; };

  void setup();
  void loop();

 private:
  uint8_t _pin;
  uint8_t _lastState = HIGH;
};
