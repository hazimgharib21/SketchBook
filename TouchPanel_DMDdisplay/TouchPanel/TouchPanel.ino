
#include <SoftwareSerial.h>

#define arraySize(x) ((sizeof(x)) / (sizeof(x[0]))) // to get array length

//********************************************************************************************************************
// Class Definition
//********************************************************************************************************************

class SevenSegment{

  private:
    uint8_t _pinLatch;
    uint8_t _pinData;
    uint8_t _pinClock;
    int numHex[11] = {192, 249, 164, 176, 153, 146, 130, 248, 128, 152, 127};
  public:
    SevenSegment(uint8_t pinLatch, uint8_t pinData, uint8_t pinClock);
    void displayNum(int num);

};

class Touch{

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
//********************************************************************************************************************
// Main Arduino Sketch
//********************************************************************************************************************

SoftwareSerial mySerial(15, 16); // RX, TX
SevenSegment ss1(24, 22, 26); // Latch, Data Clock
SevenSegment ss2(30, 28, 32); // Latch, Data Clock

void setup() {
  
  initialization();
}

void loop() {
  

}





