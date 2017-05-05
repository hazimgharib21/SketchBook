// Initialize words
char *initializes = "INITIALIZING...";
char *com = "COM ESTABLISH...";
char *ayat_mula = "BANK NEGARA MALAYSIA RM1,000,000                    CLICK START TO PLAY";

// Display when user press start
char *ayat_Start = "GAME START!! SPEND YOUR MONEY!!";

const long bungalow = 600000;
const long piano = 100000;
const long books = 600;
const long terrace = 120;
const long hamburger = 12;
const long hometheatre = 7000;
const long bags = 1500;
const long jersey = 300;
const long ensiklopedia = 2000;
const long van = 200000;
const long cat = 800;
const long languageclass = 250;
const long lambogini = 200000;
const long bicycle = 800;
const long fruits = 30;
const long ring = 60000;

char *ayat_1 = "RM 600,000"; // Bungalow House
char *ayat_2 = "RM 100,000"; // Piano
char *ayat_3 = "RM 600"; // Books
char *ayat_4 = "RM 120"; // Terrace House
char *ayat_5 = "RM 12"; // Hamburger
char *ayat_6 = "RM 7,000"; // Home theatre
char *ayat_7 = "RM 1,500"; // Designer Bags
char *ayat_8 = "RM 300"; // Sports Jersey
char *ayat_9 = "RM 2,000"; // Ensiklopedia
char *ayat_10 = "RM 200,000"; // Mini Van
char *ayat_11 = "RM 800"; // Kucing
char *ayat_12 = "RM 250"; // Foreign Language Class
char *ayat_13 = "RM 200,000"; // Lambo
char *ayat_14 = "RM 800"; // Bicycle
char *ayat_15 = "RM 30"; // 2KG of fruits
char *ayat_16 = "RM 60,000"; // Cincin
char *ayat_noTouch = "RM 0";

/*
 * Advice depends on the sum spend by user
 */
char *nasihatNothing = "YOU HAD RM 1,000,000 AND HAD SPEND NOTHING";
char *nasihat1 = "YOU WORKED HARD FOR YOUR MONEY OR MAYBE MONEY COMES EASILY FOR YOU, SO YOU SPEND IT ON ITEMS YOU WANT"; 
char *nasihat2 = "EACH PERSON'S WANTS AND NEEDS MAY DIFFER, BASED ON THEIR BACKGROUND, UPBRINGING AND EARNING POWER";
char *nasihat3 = "YOU KNOW WHAT YOU SHOULD SPEND ON, HOWEVER, YOU STILL WANT TO ENJOY THE GOOD THINGS IN LIFE";
char *nasihat4 = "GOOD JOB! YOU HAVE A GOOD BALANCE BETWEEN NEEDS AND WANTS. YOU KNOW WHAT YOU PRIORITIES ARE";
char *nasihat5 = "CONGRATULATIONS YOU ARE A WISE SPENDER. YOU HAVE CHOSEN ITEMS THAT WOULD ENRICH YOUR LIFE";
char *nasihatTooMuch = "YOU SPEND TOO MUCH";

long  sum = 0;

void dmd(byte touch){
  
  Serial.print("SUM = ");
  Serial.println(sum);
  switch(touch){
        
        case 0:
          mySerial.write(touch);
          Serial.println(ayat_Start);
          sum = 0;
          break;
        case 1:
          mySerial.write(touch);
          Serial.println(ayat_1);
          sum += bungalow;
          break;
        case 2:
          mySerial.write(touch);
          Serial.println(ayat_2);
          sum += piano;
          break;
        case 3:
          mySerial.write(touch);
          Serial.println(ayat_3);
          sum += books;
          break;
        case 4:
          mySerial.write(touch);
          Serial.println(ayat_4);
          sum += terrace;
          break;
        case 5:
          mySerial.write(touch);
          Serial.println(ayat_5);
          sum += hamburger;
          break;
        case 6:
          mySerial.write(touch);
          Serial.println(ayat_6);
          sum += hometheatre;
          break;
        case 7:
          mySerial.write(touch);
          Serial.println(ayat_7);
          sum += bags;
          break;
        case 8:
          mySerial.write(touch);
          Serial.println(ayat_8);
          sum += jersey;
          break;
        case 9:
          mySerial.write(touch);
          Serial.println(ayat_9);
          sum += ensiklopedia;
          break;
        case 10:
          mySerial.write(touch);
          Serial.println(ayat_10);
          sum += van;
          break;
        case 11:
          mySerial.write(touch);
          Serial.println(ayat_11);
          sum += cat;
          break;
        case 12:
          mySerial.write(touch);
          Serial.println(ayat_12);
          sum += languageclass;
          break;
        case 13:
          mySerial.write(touch);
          Serial.println(ayat_13);
          sum += lambogini;
          break;
        case 14:
          mySerial.write(touch);
          Serial.println(ayat_14);
          sum += bicycle;
          break;
        case 15:
          mySerial.write(touch);
          Serial.println(ayat_15);
          sum += fruits;
          break;
        case 16:
          mySerial.write(touch);
          Serial.println(ayat_16);
          sum += ring;
          break;
        case 30:
          mySerial.write(touch);
          Serial.print("You just spend : RM");
          Serial.println(sum);
          break;
        case 31:
          mySerial.write(touch);
          if(sum <= 1000000){
            Serial.println(nasihat1);
          }else{
            Serial.println(nasihatTooMuch);
          }
          break;
        case 32:
          mySerial.write(touch);
          if(sum <= 1000000){
            Serial.println(nasihat2);
          }else{
            Serial.println(nasihatTooMuch);
          }
          break;
        case 33:
          mySerial.write(touch);
          if(sum <= 1000000){
            Serial.println(nasihat3);
          }else{
            Serial.println(nasihatTooMuch);
          }
          break;
        case 34:
          mySerial.write(touch);
          if(sum <= 1000000){
            Serial.println(nasihat4);
          }else{
            Serial.println(nasihatTooMuch);
          }
          break;
        case 35:
          mySerial.write(touch);
          if(sum <= 1000000){
            Serial.println(nasihat5);
          }else{
            Serial.println(nasihatTooMuch);
          }
          break;
        case 36: // nothing
          mySerial.write(36);
          Serial.println(nasihatNothing);
          break;
        case 41:
          mySerial.write(41);
          Serial.println(ayat_mula);
          break;
        case 40:
          mySerial.write(40);
          Serial.println(initializes);
          break;
        case 42:
          mySerial.write(42);
          Serial.println(com);
          break;
        
  }
}
