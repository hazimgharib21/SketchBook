#include <EEPROM.h>

//######## PIN NUMBER################
//LINE SENSOR
int in1=A0; //pin IR 2ndleft
int in2=A1; //pin IR 1stleft
int in3=A2; //pin IR center
int in4=A3; //pin IR 2ndright

//Motor
int ma1=2;
int ma2=3;
int mb1=4;
int mb2=5;

//#####Data Storage################
//Line Data
int data1=0; //data 2ndleft
int data2=0; //data 1stleft
int data3=0; //data center
int data4=0; //data 2ndright
int data5=0; //data 1stright
//Line Setting
int black=0; //data black
int white=0; //data white
//direction
float offset=-0.1;
float dir=0;
float speed_L=0;
float speed_R=0;
float m_L=0;
float m_R=0;
//control
bool state=LOW;
//PID
float error=0;
float prev_error=0;
float integral=0;
float derivative=0;
int target=0;
float P=0;
float I=0;
float D=0;
float kp=0.8;
float ki=0;
float kd=0;
float out=0;

//################################

void setup()
{
  Serial.begin(9600);
  pinMode(ma1,OUTPUT);
  pinMode(ma2,OUTPUT);
  pinMode(mb1,OUTPUT);
  pinMode(mb2,OUTPUT);
}

void loop(){

    analogWrite(ma1,0);
    analogWrite(ma2,0);  //20
    analogWrite(mb1,0); //20
    analogWrite(mb2,0);

  
while(Serial.available()){
    
    if(Serial.read()=='a'){
      data1 = map(analogRead(in2), 0, 1023, 0, 255);
      EEPROM.write(25, data1);
    }
    if(Serial.read()=='b'){
      data1 = map(analogRead(in2), 0, 1023, 0, 255);
      EEPROM.write(50, data1);
    }
  }
  data1 = map(analogRead(in2), 0, 1023, 0, 255);
  black = EEPROM.read(25);
  white = EEPROM.read(50);
  target = (black + white)/2;
  error = target - data1;
  Serial.print(error);
  Serial.print("\t");
  Serial.println(target);
}
