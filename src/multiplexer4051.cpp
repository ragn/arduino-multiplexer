#include <multiplexer4051.h>

Multiplexer::Multiplexer(uint8_t ss0, uint8_t ss1, uint8_t ss2, uint8_t pin) :
	m_masterSs0(ss0),
	m_masterSs1(ss1),
	m_masterSs2(ss2),
	m_slaveSs0(0),
	m_slaveSs1(0),
	m_slaveSs2(0),
	m_currentPin(pin),
	m_hasSlave(false)
{
	setupMaster();
}

Multiplexer::Multiplexer(uint8_t master_ss0, uint8_t master_ss1, uint8_t master_ss2, uint8_t ss0, uint8_t ss1, uint8_t ss2, uint8_t pin) :
	m_masterSs0(master_ss0),
	m_masterSs1(master_ss1),
	m_masterSs2(master_ss2),
	m_slaveSs0(ss0),
	m_slaveSs1(ss1),
	m_slaveSs2(ss2),
	m_currentPin(pin),
	m_hasSlave(true)
{
}

Multiplexer::~Multiplexer()
{
}

void Multiplexer::setupMaster()
{
	pinMode(m_masterSs0, OUTPUT); // s0
	pinMode(m_masterSs1, OUTPUT); // s1
	pinMode(m_masterSs2, OUTPUT); // s2

	if(m_hasSlave)	
	{
		setupSlave();
	}
}

void Multiplexer::setupSlave()
{
	if(m_hasSlave == true)
	{
		pinMode(m_slaveSs0, OUTPUT);
		pinMode(m_slaveSs1, OUTPUT);
		pinMode(m_slaveSs2, OUTPUT);
	}	
}

uint16_t Multiplexer::analogRead(void)
{
	return this->analogRead(m_currentPin);
}

uint16_t Multiplexer::analogRead(uint8_t pin)
{
	selectPin(pin);	

	return analogRead(pin);
}

void Multiplexer::analogWrite(uint16_t value) 
{
	this->analogWrite(m_currentPin, value);
}

void Multiplexer::analogWrite(uint8_t pin, uint16_t value) 
{
	selectPin(pin);	

	analogWrite(pin);
}

uint8_t Multiplexer::digitalRead(void)
{
	return digitalRead(m_currentPin);
}

uint8_t Multiplexer::digitalRead(uint8_t pin)
{
	selectPin(pin);

	return digitalRead(pin);
}

void Multiplexer::digitalWrite(uint8_t value)
{
	this->digitalWrite(m_currentPin, value);
}

void Multiplexer::digitalWrite(uint8_t pin, uint8_t value) 
{	
	selectPin(pin);

	digitalWrite(pin, value);
}

void Multiplexer::configurePins(uint8_t ss0, uint8_t ss1, uint8_t ss2, uint8_t pin)
{
	digitalWrite(ss0, (pin & 0x01)); // set lowest bit
	digitalWrite(ss1, ((pin >> 1) & 0x01)); // set middle bi
	digitalWrite(ss2, ((pin >> 2) & 0x01)); // set highest bit
}

void Multiplexer::selectPin(uint8_t pin)
{
	m_currentPin = pin;

	if(m_hasSlave == true) // we have a multi multiplexer - oh dear!
	{
		configurePins(m_masterSs0, m_masterSs1, m_masterSs2, (m_currentPin / 8));
		configurePins(m_masterSs0, m_masterSs1, m_masterSs2, (m_currentPin % 8));
	}
	else
	{
		configurePins(m_masterSs0, m_masterSs1, m_masterSs2, m_currentPin);
	}
}