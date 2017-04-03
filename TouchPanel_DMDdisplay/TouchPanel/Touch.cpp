// 
// 
// 

#include "Touch.h"


Touch::Touch() {

	bounce = 10;

	for (int i = 0; i < arraySize(touch); i++) {
		pinMode(touch[i], INPUT_PULLUP);
	}

}

int Touch::getTouched() {

	int thisSwitch = 255;
	checkTouched();
	for (int i = 0; i < arraySize(touch); i++) {
		currentKeyState[i] = justPressed[i];
		if (currentKeyState[i] != previousKeyState[i]) {
			if (currentKeyState[i]) {
				thisSwitch = i;
			}
		}
		previousKeyState[i] = currentKeyState[i];
	}
	return thisSwitch;
}

void Touch::checkTouched() {

	static byte previousState[arraySize(touch)];
	static byte currentState[arraySize(touch)];
	static long lastTime;

	if (millis() < lastTime) {
		lastTime = millis();
	}

	if ((lastTime + bounce) > millis()) {
		return;
	}

	lastTime = millis();

	for (int i = 0; i < arraySize(touch); i++) {
		justPressed[i] = 0;
		justReleased[i] = 0;
		currentState[i] = digitalRead(touch[i]);

		if (currentState[i] == previousState[i]) {
			if ((pressed[i] == LOW) && (currentState[i] == LOW)) {
				justPressed[i] = 1;
			}
			else if ((pressed[i] == HIGH) && (currentState[i] == HIGH)) {
				justReleased[i] = 1;
			}
			pressed[i] = !currentState[i];
		}
		previousState[i] = currentState[i];
	}
}