

#include<LiquidCrystal.h>
#include <SoftwareSerial.h>
#include <TinyGPS.h>

#define led1 12
#define led2 13

LiquidCrystal lcd(7, 6, 5, 4, 3, 2);
SoftwareSerial mySerial(10, 11);
SoftwareSerial message(8,9);
TinyGPS gps;

char msg;
long lat;
long lon;
float flat;
float flon;
bool temp = false;
bool newdata = false;
bool msgReceive = false;

void gpsdump(TinyGPS &gps);
void printFloat(double f, int digits = 2);

void setup()  
{
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  lcd.begin(16,2);
  Serial.begin(9600);
  delay(1000);
  mySerial.begin(9600);
  delay(1000);
  message.begin(9600);
  lcd.print("Vehicle Tracking");
  lcd.setCursor(0,1);
  lcd.print("System using gps");
  delay(1000);
  Serial.println("uBlox Neo 6M");
  Serial.print("Testing TinyGPS library v. "); Serial.println(TinyGPS::library_version());
  Serial.println("by Mikal Hart");
  Serial.println();
  Serial.print("Sizeof(gpsobject) = "); 
  Serial.println(sizeof(TinyGPS));
  Serial.println(); 
  lcd.clear();
  lcd.print("System Ready");
  ReceiveMessage();
}

void loop() // run over and over
{
  serialEvent();
  ledIndicator();
  //get_gps();
  if(temp){
    get_gps();
    if (newdata) 
      {
      Serial.println("Acquired Data");
      Serial.println("-------------");
      gpsdump(gps);
      Serial.println("-------------");
      Serial.println();
      SendMessage();
      temp = false;
      newdata = false;
    }else{
      Serial.println("no data");
      temp = false;
    }
    //get_gps();
    temp =false;
  }
  
}

void serialEvent()
{
  message.listen();
  if(message.available()>0){
    
    
    if(message.find("Track Vehicle")){
      msgReceive = true;
      Serial.println("Track");
      temp = true;
    }
    else if(message.find("Reset")){ // PROBLEM LA
      msgReceive = false;
      Serial.println("Reset");
    }
    else{
      Serial.println(" not Track");
      temp = false;
    }
  }
}

void get_gps(){

  unsigned long start = millis();
  while (millis() - start < 5000) 
  {
    mySerial.listen();
    if (mySerial.available()) 
    
    {
      char c = mySerial.read();
      //Serial.print(c);  // uncomment to see raw GPS data
      if (gps.encode(c)) 
      {
        newdata = true;
        break;  // uncomment to print new data immediately!
      }
    }
  }
}

void gpsdump(TinyGPS &gps)
{
  //long lat, lon;
  //float flat, flon;
  unsigned long age, date, time, chars;
  int year;
  byte month, day, hour, minute, second, hundredths;
  unsigned short sentences, failed;

  gps.get_position(&lat, &lon, &age);
  Serial.print("Lat/Long(10^-5 deg): "); Serial.print(lat); Serial.print(", "); Serial.print(lon); 
  Serial.print(" Fix age: "); Serial.print(age); Serial.println("ms.");
  
  // On Arduino, GPS characters may be lost during lengthy Serial.print()
  // On Teensy, Serial prints to USB, which has large output buffering and
  //   runs very fast, so it's not necessary to worry about missing 4800
  //   baud GPS characters.

  gps.f_get_position(&flat, &flon, &age);
  Serial.print("Lat/Long(float): "); printFloat(flat, 5); Serial.print(", "); printFloat(flon, 5);
    Serial.print(" Fix age: "); Serial.print(age); Serial.println("ms.");

  gps.get_datetime(&date, &time, &age);
  Serial.print("Date(ddmmyy): "); Serial.print(date); Serial.print(" Time(hhmmsscc): ");
    Serial.print(time);
  Serial.print(" Fix age: "); Serial.print(age); Serial.println("ms.");

  gps.crack_datetime(&year, &month, &day, &hour, &minute, &second, &hundredths, &age);
  Serial.print("Date: "); Serial.print(static_cast<int>(month)); Serial.print("/"); 
    Serial.print(static_cast<int>(day)); Serial.print("/"); Serial.print(year);
  Serial.print("  Time: "); Serial.print(static_cast<int>(hour+8));  Serial.print(":"); //Serial.print("UTC +08:00 Malaysia");
    Serial.print(static_cast<int>(minute)); Serial.print(":"); Serial.print(static_cast<int>(second));
    Serial.print("."); Serial.print(static_cast<int>(hundredths)); Serial.print(" UTC +08:00 Malaysia");
  Serial.print("  Fix age: ");  Serial.print(age); Serial.println("ms.");

  Serial.print("Alt(cm): "); Serial.print(gps.altitude()); Serial.print(" Course(10^-2 deg): ");
    Serial.print(gps.course()); Serial.print(" Speed(10^-2 knots): "); Serial.println(gps.speed());
  Serial.print("Alt(float): "); printFloat(gps.f_altitude()); Serial.print(" Course(float): ");
    printFloat(gps.f_course()); Serial.println();
  Serial.print("Speed(knots): "); printFloat(gps.f_speed_knots()); Serial.print(" (mph): ");
    printFloat(gps.f_speed_mph());
  Serial.print(" (mps): "); printFloat(gps.f_speed_mps()); Serial.print(" (kmph): ");
    printFloat(gps.f_speed_kmph()); Serial.println();

  gps.stats(&chars, &sentences, &failed);
  Serial.print("Stats: characters: "); Serial.print(chars); Serial.print(" sentences: ");
    Serial.print(sentences); Serial.print(" failed checksum: "); Serial.println(failed);
}

void printFloat(double number, int digits)
{
  // Handle negative numbers
  if (number < 0.0) 
  {
     Serial.print('-');
     number = -number;
  }

  // Round correctly so that print(1.999, 2) prints as "2.00"
  double rounding = 0.5;
  for (uint8_t i=0; i<digits; ++i)
    rounding /= 10.0;
  
  number += rounding;

  // Extract the integer part of the number and print it
  unsigned long int_part = (unsigned long)number;
  double remainder = number - (double)int_part;
  Serial.print(int_part);

  // Print the decimal point, but only if there are digits beyond
  if (digits > 0)
    Serial.print("."); 

  // Extract digits from the remainder one at a time
  while (digits-- > 0) 
  {
    remainder *= 10.0;
    int toPrint = int(remainder);
    Serial.print(toPrint);
    remainder -= toPrint;
  }
}

void SendMessage()
{
  message.listen();
  lcd.clear();
  lcd.print("Sending Message");
  
  message.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
  delay(1000);  // Delay of 1000 milli seconds or 1 second
  message.println("AT+CMGS=\"+60182810245\"\r"); // Replace x with mobile number
  delay(1000);
  message.println("Vehicle Tracking System");// The SMS text you want to send
  message.println("Latitude");
  message.println(flat);
  message.println("Longitude");
  message.println(flon);
  delay(100);
  message.println((char)26);// ASCII code of CTRL+Z
  delay(1000);
   
  delay(1000);
  lcd.clear();
  lcd.print("Message Sent");
  delay(2000);
  ReceiveMessage();
  lcd.clear();
  lcd.print("System Ready");
}

void ReceiveMessage()
{
  message.listen();
  message.println("AT+CNMI=2,2,0,0,0"); // AT Command to recieve a live SMS
  delay(1000);
  if (message.available()>0)
  {
    msg=message.read();
    Serial.print(msg);
  }
}

void ledIndicator(){

  if(msgReceive){
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
  }else{
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
  }
}

