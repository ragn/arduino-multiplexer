#include <multiplexer4051.h>

uint8_t MASTER_SS0 = 0;
uint8_t MASTER_SS1 = 1;
uint8_t MASTER_SS2 = 2;

uint8_t SLAVE_SS0 = 3;
uint8_t SLAVE_SS1 = 4;
uint8_t SLAVE_SS2 = 5;

uint8_t DEFAULT_PIN = 10;
uint8_t OTHER_PIN = 11;

Multiplexer multiplexer(MASTER_SS0, MASTER_SS0, MASTER_SS1, SLAVE_SS0, SLAVE_SS1, SLAVE_SS2, DEFAULT_PIN);

void setup() {
  // multiplexer is setup when the constructor is called
  // according to the given pins IN-/OUTPUT pins will be set up
}

void loop() {

  uint16_t value1 = multiplexer.analogRead(); // read from default pin -> PIN
  uint16_t value2 = multiplexer.analogRead(OTHER_PIN); // read from other pin
}
