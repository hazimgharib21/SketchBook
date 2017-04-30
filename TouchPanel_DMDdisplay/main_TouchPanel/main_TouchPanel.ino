#include <SoftwareSerial.h>



#include <EEPROM.h>



#define DEBOUNCE 50 
#define baudrate 9600
#define Combaudrate 2400
#define debugMode true // set to true only for debugging
#define serialMode false
#define arraySize(x) ((sizeof(x))/(sizeof(x[0])))

byte buttons[] = { 
  37, //start
  39, // Bungalow House
  41, // Piano
  43, // Books
  45, // Terrace House
  47,  // Hamburger
  49,// Home theatre
  51,// Designer Bags
  53,// Sports Jersey
  35,// Ensiklopedia
  33,// Mini Van
  31,// Kucing
  29,// Foreign Language Class
  27,// Lambo
  25,// Bicycle
  21,// 2KG of fruits
  23// Cincin
};

SoftwareSerial mySerial(0, 1);

const byte NUMBUTTONS = sizeof(buttons);
byte pressed[NUMBUTTONS], justpressed[NUMBUTTONS], justreleased[NUMBUTTONS];

const byte buzzerPin = 13;

int numHex[11] = { 192, 249, 164, 176, 153, 146, 130, 248, 128, 152, 127 };
byte latchPin[] = {12, 6};
byte dataPin[] = {11, 5};
byte clockPin[] = {13, 7};
unsigned long countMillis = 0;
int countUpdate = 1000;

byte count = 0;
boolean gameStart = false;
boolean evaluate = false;
int need = 0;
int want = 0;


void setup() {
  Initialization();
}



void loop() {

  delay(50);
  updateTouch();
  CountDown(count);

  
  for (byte i = 0; i < NUMBUTTONS; i++) {
    if (justreleased[i]) {
    
      
      if(evaluate){
        
      }else{
        if(i == 0){
        
        if(gameStart){
          
        }else{
          buzzer('e');
          gameStart = true;
          count = 30;
          countMillis = millis();
          dmd(i);
        }
      }else{
        if(gameStart){
          dmd(i);
          buzzer('p');
          if((i == 3) || (i == 4) || (i == 5) || (i == 15)){
            need++;
          }else{
            want++;
          }
        }
      }
      }
      
    }
  }

  if((millis() - countMillis) >= countUpdate){
    if(gameStart){
      Serial.print("\t\t\t");
      Serial.print("CountDown: ");
      Serial.println(count, DEC);
      if(count == 0){
        gameStart = false;
        buzzer('e');
        Serial.print("\t\t");
        Serial.println("< GAME END >");
        evaluate = true;
        evaluation();
      }else{
        count--;
      }
      
      
    }
    
    countMillis = millis();
  }
  
}

void evaluation(){
  Serial.print("\t\t");
  Serial.println("< EVALUATION START >");
  dmd(30);
  delay(5000);
  
  if((need == 0) && (want == 0)){
    dmd(36); 
  }else if(need == 0){
    dmd(31);
  }else if(want == 0){
    dmd(35);
  }else if(want == need){
    dmd(34);
  }else if(want > need){
    dmd(33);
  }else if(need > want){
    dmd(32);
  }
  
  delay(5000);
  need = 0;
  want = 0;
  Serial.print("\t\t");
  Serial.println("< EVALUATION END >");
  evaluate = false;
  dmd(41);
}

