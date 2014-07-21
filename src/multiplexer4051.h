#ifndef _MULTIPLEXER_4051_H
#define _MULTIPLEXER_4051_H

#include "Arduino.h"

class Multiplexer
{
public:
	static const uint8_t Y0 = 0;
	static const uint8_t Y1 = 1;
	static const uint8_t Y2 = 2;
	static const uint8_t Y3 = 3;
	static const uint8_t Y4 = 4;
	static const uint8_t Y5 = 5;
	static const uint8_t Y6 = 6;
	static const uint8_t Y7 = 7;
	
	Multiplexer(uint8_t ss0, uint8_t ss1, uint8_t ss2, uint8_t pin);
	Multiplexer(uint8_t master_ss0, uint8_t master_ss1, uint8_t master_ss2, uint8_t ss0, uint8_t ss1, uint8_t ss2, uint8_t pin);
	~Multiplexer();

	uint16_t analogRead(void);
	uint16_t analogRead(uint8_t pin);
	
	void analogWrite(uint16_t value);
	void analogWrite(uint8_t pin, uint16_t value);

	uint8_t digitalRead(void);	
	uint8_t digitalRead(uint8_t pin);

	void digitalWrite(uint8_t value);
	void digitalWrite(uint8_t pin, uint8_t value);	

private:

	uint8_t m_masterSs0;
	uint8_t m_masterSs1;
	uint8_t m_masterSs2;

	uint8_t m_slaveSs0;
	uint8_t m_slaveSs1;
	uint8_t m_slaveSs2;

	uint8_t m_outPin1;
	uint8_t m_outPin2;
	uint8_t m_outPin3;

	uint8_t m_currentPin;
	boolean m_hasSlave;

	void setupMaster();
	void setupSlave();
	void configurePins(uint8_t ss0, uint8_t ss1, uint8_t ss2, uint8_t pin);
	void selectPin(uint8_t pin);
};

#endif