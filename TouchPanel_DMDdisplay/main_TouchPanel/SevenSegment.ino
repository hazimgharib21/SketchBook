
void CountDown(byte num){

  byte temp;

  byte num1 = num / 10;
  byte num2 = num - (num1 * 10);

  digitalWrite(latchPin[0], LOW);
  shiftOut(dataPin[0], clockPin[0], MSBFIRST, numHex[num1]);
  digitalWrite(latchPin[0], HIGH);

  digitalWrite(latchPin[1], LOW);
  shiftOut(dataPin[1], clockPin[1], MSBFIRST, numHex[num2]);
  digitalWrite(latchPin[1], HIGH);
}

