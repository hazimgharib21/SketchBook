
long timer = 0;

/*
 * Dont touch this part of the code.
 * Use to initiate marquee effect with the message as an argument
 * The message must be in char pointer or char array
 */
void panelInit(char *lol){
  dmd.clearScreen(true);
  dmd.selectFont(Arial_Black_16);
  char *MSG = lol;
  dmd.drawMarquee(MSG,strlen(MSG),(32*WIDTH)-1,1);  
}

void panelDisplay(){
  if((timer + 3) < millis()){
    dmd.stepMarquee(-1,0);
    timer = millis();
  }
}
/*
 * Change the sum to char array for display in led scroller
 */
void toChar(long num){

      /*
        char sumChar[25];
        String myString = "YOU SPEND RM ";
        myString+=String(num);
        myString.toCharArray(sumChar, sizeof(sumChar));
        Serial.println(sumChar);
        panelInit(sumChar);
       */

       String numString = "";
       String num1String = "";
       String num2String = "";
       String num3String = "";
       String num4String = "";
       

        int num1 = num / 1000000000;
        
        int num2 = (num % 1000000000) / 1000000;
        if(num2 == 0){
            num2String = "000";
        }else if(num2 < 10){
          num2String = "00" + (String)num2;
        }else if(num2 < 100){
          num2String = "0" + (String)num2;
        }else{
          num2String = (String)num2;
        }
        int num3 = (num % 1000000) / 1000;
        if(num3 == 0){
          num3String = "000";
        }else if(num3 < 10){
          num3String = "00" + (String)num3;
        }else if(num3 < 100){
          num3String = "0" + (String)num3;
        }else{
          num3String = (String)num3;
        }
        int num4 = (num % 1000); 
        if(num4 == 0){
          num4String = "000";
        }else if(num4 < 10){
          num4String = "00" + (String)num4;
        }else if(num4 < 100){
          num4String = "0" + (String)num4;
        }else{
          num4String = (String)num4;
        }
        Serial.print(num4String);
        Serial.print("\t");
        
        if(num1 == 0 && num2 == 0 && num3 == 0 && num4 == 0){
          numString = "0";
        }else if(num1 == 0 && num2 == 0 && num3 == 0){
          numString = String(num4);
        }else if(num1 == 0 && num2 == 0){
          numString = String(num3) + "," + num4String;
        }else if(num1 == 0){
          numString = String(num2) + "," + num3String + "," + num4String; 
        }else{
          numString = String(num1) + "," + num2String + "," + num3String + "," + num4String; 
        }

       char sumChar[28];
       String myString = "YOU SPEND RM ";
       myString += numString;
       myString.toCharArray(sumChar, sizeof(sumChar));
       Serial.println(sumChar);
       panelInit(sumChar);
       
}
