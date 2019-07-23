/*
MIT License

Copyright (c) 2018 Brian T. Park

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include <Arduino.h> // Serial
#include "Printer.h"

#if defined(ARDUINO_SAMD_ZERO)
  // If have a real Arduino Zero and using the "Arduino/Genuino Zero (Native
  // USB Port)" configuration on the Arduino IDE,  you may need to uncomment
  // the following to clobber SERIAL_PORT_MONITOR to point to the correct
  // SerialUSB.
  //
  // On the other hand, if you are using a SparkFun breakout board, or one of
  // the "SAMD21 M0 Mini" clones, you should be using the SparkFun SAMD Boards,
  // and selecting the "SparkFun SAMD21 Dev Breakout" or the "SparkFun SAMD21
  // Mini Breakout" settings, which will set the SERIAL_PORT_MONITOR macro
  // correctly to SerialUSB.
  #if 0
    #undef SERIAL_PORT_MONITOR
    #define SERIAL_PORT_MONITOR SerialUSB
  #endif
#elif defined(ESP32)
  #define SERIAL_PORT_MONITOR Serial
#elif defined(__linux__) or defined(__APPLE__)
  #define SERIAL_PORT_MONITOR Serial
#endif

namespace aunit {

Print* Printer::sPrinter = &SERIAL_PORT_MONITOR;

}
