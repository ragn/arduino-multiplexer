# arduino-multiplexer library

Target of this library is to simplify the usage of the 4051 multiplexer.

## Installation

Get the latest library from github:

https://github.com/ragn/arduino-multiplexer

Install the library into your sketchbook (see Arduino [doc](http://arduino.cc/en/Guide/Libraries) on how to do this.).

## Using the library

Include the header into your sketch by adding:

#include <multiplexer.h>

## Multiplexer usage

### Create instance

Your have to create an instance of the multiplexer.

#### Single 4051

uint8_t SS0 = 0;
uint8_t SS1 = 0;
uint8_t SS2 = 0;
uint8_t DEFAULT_PIN = 0;

Multiplexer multiplexer(SS0, SS1, SS2, DEFAULT_PIN);

### Hierarchic 4051

uint8_t MASTER_SS0 = 0;
uint8_t MASTER_SS1 = 0;
uint8_t MASTER_SS2 = 0;

uint8_t SLAVE_SS0 = 0;
uint8_t SLAVE_SS1 = 0;
uint8_t SLAVE_SS2 = 0;

uint8_t DEFAULT_PIN = 0;

Multiplexer multiplexer(MASTER_SS0, MASTER_SS1, MASTER_SS2, SLAVE_SS0, SLAVE_SS1, SLAVE_SS2, DEFAULT_PIN);

### Read Value

uint16_t value = multiplexer.readAnalog();
uint16_t value = multiplexer.readAnalog(OTHER_PIN);

uint8_t value = multiplexer.readDigital();
uint8_t value = multiplexer.readDigital(OTHER_PIN);

### Write Value

uint8_t OUT_PIN = 12;
uint16_t VALLUE = 512;

multiplexer.writeAnalog(VALUE);
multiplexer.writeAnalog(VALUE, OUT_PIN);

multiplexer.writeDigital(VALUE);
multiplexer.writeDigital(VALUE, OUT_PIN);