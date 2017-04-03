// 
// 
// 

#include "SevenSegment.h"

SevenSegment::SevenSegment(uint8_t pinLatch, uint8_t pinData, uint8_t pinClock) {

	// Set pin to output
	pinMode(pinLatch, OUTPUT);
	pinMode(pinData, OUTPUT);
	pinMode(pinClock, OUTPUT);

	// Initialize pin state
	digitalWrite(pinLatch, LOW);
	digitalWrite(pinData, LOW);
	digitalWrite(pinData, LOW);

	_pinLatch = pinLatch;
	_pinData = pinData;
	_pinClock = pinClock;

}

void SevenSegment::displayNum(int num) {

	if (num > 9) {
		num = 0;
	}

	digitalWrite(_pinLatch, LOW);
	shiftOut(_pinData, _pinClock, MSBFIRST, numHex[num]);
	digitalWrite(_pinLatch, HIGH);
}
