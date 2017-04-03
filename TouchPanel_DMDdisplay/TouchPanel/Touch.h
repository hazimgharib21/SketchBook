// Touch.h

#ifndef _TOUCH_h
#define _TOUCH_h
#define arraySize(x) ((sizeof(x)) / (sizeof(x[0]))) // to get array length

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class Touch {

private:
	int touch[17] = {
		1, // 0
		2, // 1
		3, // 2
		4, // 3
		5, // 4
		6, // 5
		7, // 6
		8, // 7
		9, // 8
		10, // 9
		11, // 10
		12, // 11
		13, // 12
		14, // 13
		15, // 14
		16, // 15
		17 // 16
	};

	int bounce;
	byte pressed[arraySize(touch)];
	byte justPressed[arraySize(touch)];
	byte justReleased[arraySize(touch)];
	byte previousKeyState[arraySize(touch)];
	byte currentKeyState[arraySize(touch)];

	void checkTouched();

public:
	Touch();
	int getTouched();

};

#endif

