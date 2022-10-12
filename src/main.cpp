#include <Arduino.h>

#include "./inputs/Key.hpp"
#include "./inputs/RotaryEncoder.hpp"
#include "Debug.hpp"
#include "HAL.hpp"
#include "HID-Project.h"

RotaryEncoder r(static_cast<uint8_t>(HAL::InputPin::D4),
                static_cast<uint8_t>(HAL::InputPin::D5),
                static_cast<uint8_t>(HAL::InputPin::D6));

Key testKey(static_cast<uint8_t>(HAL::InputPin::D8));

void setup() {
  Serial.begin(9600);

  Consumer.begin();

#ifdef DEBUG_OUTPUT
  // Delay startup so we can capture output of any setup logging.
  delay(1000);
#endif

  r.setup();

  testKey.setup();

  DEBUG_PRINTLN("main setup completed");
}

void loop() {
  r.loop();

  testKey.loop();

  // Put in a slight delay to help debounce the reading
  delay(1);
}
