
unsigned long countMillis = 0;
int countUpdate = 1000;
int TouchState = 99;
int count = 0;
bool gameStart = false;

void updateState(){

  Countdown(count);
  TouchState = touch.getTouched();
  if (TouchState == 16) {
	  gameStart = true;
	  count = 30;
	  countMillis = millis();
  }
}

void mainProgram(){

	if (gameStart) {
		Serial.println(TouchState);
		mySerial.println(TouchState);
	}
	
  if((millis() - countMillis) >= countUpdate){
    if(count == 0){
		gameStart = false;
      
    }else{
		Serial.println(count);
      count--;
    }

    countMillis = millis();
  }
}

void Countdown(int num){

  int temp;

  int num1 = num / 10;
  int num2 = num - (num1 * 10);

  ss1.displayNum(num1);
  ss2.displayNum(num2);
  
}



