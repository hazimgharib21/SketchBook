#include <EEPROM.h>

//######## PIN NUMBER################
//LINE SENSOR
int in1=A0; //pin IR 2ndleft
int in2=A1; //pin IR 1stleft
int in3=A2; //pin IR center
int in4=A3; //pin IR 2ndright

//Motor
int R_motor1=3;
int R_motor2=2;
int L_motor1=4;
int L_motor2=5;
int pwmR = 9;
int pwmL = 10;

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
float kp=0.;
float ki=0;
float kd=0;
float out=0;
unsigned long dt=0; 
unsigned long t0=0; 
unsigned long t1=0;  

//################################


void setup()
{
  Serial.begin(9600);
  pinMode(R_motor1,OUTPUT);
  pinMode(R_motor2,OUTPUT);
  pinMode(L_motor1,OUTPUT);
  pinMode(L_motor2,OUTPUT);

  black = EEPROM.read(25);
  white = EEPROM.read(50);
  target = (black + white)/2;
}

void loop(){

  data1 = map(analogRead(in2), 0, 1023, 0, 255);
  error = target - data1;
  integral = integral + error;
  derivative = error - prev_error;
  P = kp * error;
  I = ki * integral;
  D = kd * derivative;
  out = P + I + D;
  speed_R = 110-out;
  speed_L = 70-(0.3*out);
  Serial.print(m_L);
  Serial.print("\t");
  Serial.print(error);
  Serial.print("\t");
  Serial.println(m_R);

  if(speed_R>0){
    m_R=constrain(speed_R, 0, 255);
    digitalWrite(R_motor1, LOW);
    digitalWrite(R_motor2, HIGH); 
    analogWrite(pwmR,m_R);  //20
    
  }
      else{
          m_R=-speed_R;
          digitalWrite(R_motor1, HIGH);
          digitalWrite(R_motor2, LOW); 
          analogWrite(pwmR,m_R);  //20
        }
  if(speed_L>0){
    m_L=constrain(speed_L, 0, 255);
    digitalWrite(L_motor1, LOW);
    digitalWrite(L_motor2, HIGH); 
    analogWrite(pwmL,m_L);  //20
  }
      else{
        m_L=-speed_L;
        digitalWrite(L_motor1, HIGH);
        digitalWrite(L_motor2, LOW); 
        analogWrite(pwmL,m_L);  //20
      }
  
}


