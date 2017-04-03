
#include "Touch.h"
#include "SevenSegment.h"
#include <SoftwareSerial.h>

#define arraySize(x) ((sizeof(x)) / (sizeof(x[0]))) // to get array length

unsigned long countMillis = 0;
int countUpdate = 1000;


//********************************************************************************************************************
// Class Definition
//********************************************************************************************************************




//********************************************************************************************************************
// Main Arduino Sketch
//********************************************************************************************************************

int TouchState = 99;
int count = 0;

SoftwareSerial mySerial(15, 16); // RX, TX
SevenSegment ss1(24, 22, 26); // Latch, Data Clock
SevenSegment ss2(30, 28, 32); // Latch, Data Clock
Touch touch;

void setup() {
  
  initialization();
}

void loop() {

  updateState();
  mainProgram();

}



