//********************************************************************************************************************
// Include Libraries 
//********************************************************************************************************************

#include "Touch.h"
#include "SevenSegment.h"
#include <SoftwareSerial.h>

//********************************************************************************************************************
// Defining constant 
//********************************************************************************************************************

#define arraySize(x) ((sizeof(x)) / (sizeof(x[0]))) // to get array length

//********************************************************************************************************************
// Initiate Variables and libraries objects
//********************************************************************************************************************

SoftwareSerial mySerial(15, 16); // RX, TX
SevenSegment ss2(12, 11, 13); // Latch, Data Clock
SevenSegment ss1(6, 5, 7); // Latch, Data Clock
Touch touch;

//********************************************************************************************************************
// Main Arduino Sketch
//********************************************************************************************************************

void setup() {
  
  initialization();

}

void loop() {

  updateState();
  mainProgram();

}



