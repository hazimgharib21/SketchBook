// SevenSegment.h

#ifndef _SEVENSEGMENT_h
#define _SEVENSEGMENT_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class SevenSegment {

private:
	uint8_t _pinLatch;
	uint8_t _pinData;
	uint8_t _pinClock;
	int numHex[11] = { 192, 249, 164, 176, 153, 146, 130, 248, 128, 152, 127 };
public:
	SevenSegment(uint8_t pinLatch, uint8_t pinData, uint8_t pinClock);
	void displayNum(int num);

};

#endif

