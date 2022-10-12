#include "RotaryEncoder.hpp"

void RotaryEncoder::setup() {
  // Configure switch pin
  pinMode(_sw, INPUT_PULLUP);

  // Configure pins from MD_REncoder
  _rotary.begin();

  // Set speed baseline
  _rotary.setPeriod(1000); // TODO play with this and scale this out to make it easier to calc the multiplier.
}

void RotaryEncoder::loop() {
  readRotaryState();
  readSwState();
}

void RotaryEncoder::readRotaryState() {
  // Direction since last state
  uint8_t direction = _rotary.read();

  if (!direction) {
    return;
  }

  uint16_t speed = _rotary.speed();
  uint16_t x = speedVolumeMultiplier(speed);

  switch (direction) {
    case DIR_CCW:
      DEBUG_PRINT("-1");
      Consumer.write(MEDIA_VOLUME_DOWN);
      break;
    case DIR_CW:
      DEBUG_PRINT("+1");
      Consumer.write(MEDIA_VOLUME_UP);
      break;
  }

  DEBUG_PRINT("  ");
  DEBUG_PRINTLN(_rotary.speed());
}

void RotaryEncoder::readSwState() {
  int swState = digitalRead(_sw);
  // If we detect LOW signal, button is pressed
  if (swState == LOW) {
    // if 50ms have passed since last LOW pulse, it means that the
    // button has been pressed, released and pressed again
    if (millis() - lastSwPress > 50) {
      DEBUG_PRINTLN("Button pressed!");
      Consumer.write(MEDIA_VOLUME_MUTE);
    }

    // Remember last button press event
    lastSwPress = millis();  // TODO this might overflow lol
  }
}

uint16_t RotaryEncoder::speedVolumeMultiplier(uint16_t speed) {
  if (speed == 0) {
    return 1;
  }

  return 1;
}
