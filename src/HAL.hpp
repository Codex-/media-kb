#pragma once

#include "Types.hpp"

namespace HAL {

/**
 * Pinout from Sparkfun documentation:
 * https://learn.sparkfun.com/tutorials/pro-micro--fio-v3-hookup-guide
 */
enum class InputPin : uint8_t {
  /**
   * TX
   * DIO1
   */
  TX0 = 1,

  /**
   * RX
   * DIO0
   */
  RX1 = 0,

  /**
   * I2C: SDA
   * DIO2
   */
  D2 = 2,

  /**
   * PWM
   * I2C: SCL
   * DIO3
   */
  D3 = 3,

  /**
   * DIO4
   */
  D4 = 4,

  /**
   * Analog
   */
  A6 = 4,

  /**
   * PWM
   * DIO5
   */
  D5 = 5,

  /**
   * PWM
   * DIO6
   */
  D6 = 6,

  /**
   * PWM
   * Analog
   */
  A7 = 6,

  /**
   * DIO7
   */
  D7 = 7,

  /**
   * DIO8
   */
  D8 = 8,

  /**
   * Analog
   */
  A8 = 8,

  /**
   * PWM
   */
  D9 = 9,

  /**
   * PWM
   * Analog
   */
  A9 = 9,

  /**
   * PWM
   * DIO10
   */
  D10 = 10,

  /**
   * PWM
   * Analog
   */
  A10 = 10,

  /**
   * SPI: MOSI
   * DIO16
   */
  D16 = 16,

  /**
   * SPI: MISO
   * DIO14
   */
  D14 = 14,

  /**
   * SPI: SCLK
   * DIO15
   */
  D15 = 15,

  /**
   * DIO18
   */
  D18 = 18,

  /**
   * Analog
   */
  A0 = 18,

  /**
   * DIO19
   */
  D19 = 19,

  /**
   * Analog
   */
  A1 = 19,

  /**
   * DIO20
   */
  D20 = 20,

  /**
   * Analog
   */
  A2 = 20,

  /**
   * DIO21
   */
  D21 = 21,

  /**
   * Analog
   */
  A3 = 21,
};

}  // namespace HAL
