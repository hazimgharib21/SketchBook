
void updateState(){

  Countdown(count);
  TouchState = touch.getTouched();
}

void mainProgram(){

  switch(TouchState){

    case 0:
      Serial.println("pin 0 just touched");
      mySerial.write(1);
      break;
    case 1:
      Serial.println("pin 1 just touched");
      mySerial.write(1);
      break;
    case 2:
      Serial.println("pin 2 just touched");
      mySerial.write(2);
      break;
    case 3:
      Serial.println("pin 3 just touched");
      mySerial.write(3);
      break;
    case 4:
      Serial.println("pin 4 just touched");
      mySerial.write(4);
      break;
    case 5:
      Serial.println("pin 5 just touched");
      mySerial.write(5);
      break;
    case 6:
      Serial.println("pin 6 just touched");
      mySerial.write(6);
      break;
    case 7:
      Serial.println("pin 7 just touched");
      mySerial.write(7);
      break;
    case 8:
      Serial.println("pin 8 just touched");
      mySerial.write(8);
      break;
    case 9:
      Serial.println("pin 9 just touched");
      mySerial.write(9);
      break;
    case 10:
      Serial.println("pin 10 just touched");
      mySerial.write(10);
      break;
    case 11:
      Serial.println("pin 11 just touched");
      mySerial.write(11);
      break;
    case 12:
      Serial.println("pin 12 just touched");
      mySerial.write(12);
      break;
    case 13:
      Serial.println("pin 13 just touched");
      mySerial.write(13);
      break;
    case 14:
      Serial.println("pin 14 just touched");
      mySerial.write(14);
      break;
    case 15:
      Serial.println("pin 15 just touched");
      mySerial.write(15);
      break;
    case 16:
      Serial.println("pin 16 just touched");
      mySerial.write(16);
      count = 30;
      countMillis = millis();
      break;
  }

  if((millis() - countMillis) >= countUpdate){
    if(count == 0){
      
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



