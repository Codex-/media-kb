#include "./Key.hpp"

void Key::setup() {
  pinMode(_pin, INPUT_PULLUP);
}

void Key::loop() {
  // checking the state of the button

  uint8_t newState = digitalRead(_pin);

  // replaces button press with UP arrow

  if (newState == LOW && _lastState == HIGH) {
    // and it's currently pressed:
    DEBUG_PRINTLN("key pressed");

    Consumer.write(MEDIA_PLAY_PAUSE);

    delay(50);
  }

  if (newState == HIGH && _lastState == LOW) {
    // and it's currently released:
    DEBUG_PRINTLN("key released");

    // Consumer.release(MEDIA_PLAY_PAUSE);

    delay(50);
  }

  _lastState = newState;
}
