#pragma once

#include <Arduino.h>

#ifdef DEBUG_OUTPUT
#define DEBUG_PRINT(exp) \
  do {                   \
    Serial.print(exp);   \
  } while (0)
#else
#define DEBUG_PRINT(exp) \
  do {                   \
  } while (0)
#endif

#ifdef DEBUG_OUTPUT
#define DEBUG_PRINTLN(exp) \
  do {                     \
    Serial.println(exp);   \
  } while (0)
#else
#define DEBUG_PRINTLN(exp) \
  do {                     \
  } while (0)
#endif
