void initialization(){
  initSerial();
  initOutput();
  initInput();
}

void initSerial(){

  Serial.begin(9600);
  mySerial.begin(2400);
  while(!Serial){
    delay(10);
  }
  
}

void initOutput(){
  
}

void initInput(){

  
}
