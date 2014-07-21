#include <multiplexer4051.h>

uint8_t SS0 = 0;
uint8_t SS1 = 1;
uint8_t SS2 = 2;
uint8_t PIN = 5;
uint8_t PIN2 = 6;

Multiplexer multiplexer(SS0, SS1, SS2, PIN);

void setup() {
  // multiplexer is setup when the constructor is called
  // according to the given pins IN-/OUTPUT pins will be set up
}

void loop() {

  uint16_t value1 = multiplexer.analogRead(); // read from default pin -> PIN
  uint16_t value2 = multiplexer.analogRead(PIN2); // read from other pin
}
