void Initialization(){
  
  initSerial();
  verification();
  initInput();
  initOutput();
  delay(5000);
  dmd(41);
}

void initSerial(){
  
  if(debugMode || serialMode){
    Serial.begin(baudrate);
    while(!Serial){}
    //if(serialMode) Serial.print(F("< Arduino ready >\n"));
    //if(debugMode) Serial.print(F("< DebugMode begin >\n"));
  }

  dmd(40);
  delay(5000);

  
  mySerial.begin(Combaudrate);
  while(!mySerial){}
  dmd(42);
}

void initInput(){

  for (byte i = 0; i< NUMBUTTONS; i++) {
    pinMode(buttons[i], INPUT_PULLUP);
  }
  
}

void initOutput(){

  pinMode(buzzerPin, OUTPUT);

  for(byte i = 0; i < arraySize(latchPin); i++){
    pinMode(latchPin[i], OUTPUT);
    digitalWrite(latchPin[i], LOW);
  }

  for(byte i = 0; i < arraySize(dataPin); i++){
    pinMode(dataPin[i], OUTPUT);
    digitalWrite(dataPin[i], LOW);
  }

  for(byte i = 0; i < arraySize(clockPin); i++){
    pinMode(clockPin[i], OUTPUT);
    digitalWrite(clockPin[i], LOW);
  }
    
}

void verification() {
  
  int address = 1;
  int value = 0;

  value = EEPROM.read(address);
  Serial.print("EEPROM Value = ");
  Serial.println(value);
  
  while (value > 100) {

  }

  value = 1 + value;

 

  EEPROM.write(address, value);

  
}
