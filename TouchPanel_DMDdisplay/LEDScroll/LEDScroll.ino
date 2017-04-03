#include <SPI.h>
#include <DMD.h>
#include <SoftwareSerial.h>
#include <TimerOne.h>
#include "SystemFont5x7.h"
#include "Arial_Black_16.h"

SoftwareSerial mySerial(2, 3); // Rxbiru, Txcokelat
							   // Fire up the DMD library as dmd
#define WIDTH 5
#define HEIGHT 1
DMD dmd(WIDTH, HEIGHT);
unsigned long timeEnd = 0;
unsigned long timeNasihat = 0;
boolean gameStart = false;
boolean endGame = false;

// Initialize timer
int endUpdate = 20000;


// Initialize words
char *ayat_mula = "BANK NEGARA MALAYSIA RM1,000,000                    CLICK START TO PLAY";

// Display when user press start
char *ayat_Start = "GAME START!! SPEND YOUR MONEY!!";

/*
* The Price of Things based on inputs
*/
char *ayat_0 = "RM 600,000"; // Bungalow House
char *ayat_1 = "RM 100,000"; // Piano
char *ayat_2 = "RM 600"; // Books
char *ayat_3 = "RM 120"; // Terrace House
char *ayat_4 = "RM 12"; // Hamburger
char *ayat_5 = "RM 7,000"; // Home theatre
char *ayat_6 = "RM 1,500"; // Designer Bags
char *ayat_7 = "RM 300"; // Sports Jersey
char *ayat_8 = "RM 2,000"; // Ensiklopedia
char *ayat_9 = "RM 200,000"; // Mini Van
char *ayat_10 = "RM 800"; // Kucing
char *ayat_11 = "RM 250"; // Foreign Language Class
char *ayat_12 = "RM 200,000"; // Lambo
char *ayat_13 = "RM 800"; // Bicycle
char *ayat_14 = "RM 30"; // 2KG of fruits
char *ayat_15 = "RM 60,000"; // Cincin
char *ayat_noTouch = "RM 0";

/*
* Advice depends on the sum spend by user
*/
char *nasihat1 = "YOU HAD RM 1,000,000 AND HAD SPEND NOTHING";
char *nasihat2 = "YOU WORKED HARD FOR YOUR MONEY OR MAYBE MONEY COMES EASILY FOR YOU, SO YOU SPEND IT ON ITEMS YOU WANT";
char *nasihat3 = "EACH PERSON'S WANTS AND NEEDS MAY DIFFER, BASED ON THEIR BACKGROUND, UPBRINGING AND EARNING POWER";
char *nasihat4 = "YOU KNOW WHAT YOU SHOULD SPEND ON, HOWEVER, YOU STILL WANT TO ENJOY THE GOOD THINGS IN LIFE";
char *nasihat5 = "GOOD JOB! YOU HAVE A GOOD BALANCE BETWEEN NEEDS AND WANTS. YOU KNOW WHAT YOU PRIORITIES ARE";
char *nasihat6 = "CONGRATULATIONS YOU ARE A WISE SPENDER. YOU HAVE CHOSEN ITEMS THAT WOULD ENRICH YOUR LIFE";
char *nasihat7 = "YOU SPEND TO MUCH";

int num = 0;
int input = 0;
long sum = 0;
boolean noRepeat = false;
int nasihatEnd = 25;

// fucntion use for led scroller
void ScanDMD() {
	dmd.scanDisplayBySPI();
}

void setup(void) {
	// Initialize led scroller
	Timer1.initialize(3000);
	Timer1.attachInterrupt(ScanDMD);
	dmd.clearScreen(true);

	// Initialize Serial
	Serial.begin(9600);
	mySerial.begin(2400);

	// Initialize the display
	panelInit(ayat_mula);
}

void loop() {

	panelDisplay();

	if (mySerial.available() > 0) {
		input = mySerial.read();
		delay(1);
	}

	switch (input) {
	case 0:
		panelInit(ayat_0);
		sum += 600000;
		break;
	case 1:
		panelInit(ayat_1);
		sum += 100000;
		break;
	case 2:
		panelInit(ayat_2);
		sum += 600;
		break;
	case 3:
		panelInit(ayat_3);
		sum += 120;
		break;
	case 4:
		panelInit(ayat_4);
		sum += 12;
		break;
	case 5:
		panelInit(ayat_5);
		sum += 7000;
		break;
	case 6:
		panelInit(ayat_6);
		sum += 1500;
		break;
	case 7:
		panelInit(ayat_7);
		sum += 300;
		break;
	case 8:
		panelInit(ayat_8);
		sum += 2000;
		break;
	case 9:
		panelInit(ayat_9);
		sum += 200000;
		break;
	case 10:
		panelInit(ayat_10);
		sum += 800;
		break;
	case 11:
		panelInit(ayat_11);
		sum += 250;
		break;
	case 12:
		panelInit(ayat_12);
		sum += 200000;
		break;
	case 13:
		panelInit(ayat_13);
		sum += 800;
		break;
	case 14:
		panelInit(ayat_14);
		sum += 30;
		break;
	case 15:
		panelInit(ayat_15);
		sum += 60000;
		break;
	case 16:
		panelInit(ayat_Start);
		sum = 0;
		break;
	case 17:
		panelInit(nasihat1);
		break;
	case 18:
		panelInit(nasihat2);
		break;
	case 19:
		panelInit(nasihat3);
		break;
	case 20:
		panelInit(nasihat4);
		break;
	case 21:
		panelInit(nasihat5);
		break;
	case 22:
		panelInit(nasihat6);
		break;
	case 23:
		panelInit(nasihat7);
		break;
	case 24:
		toChar(sum);
	case 25:
		panelInit(ayat_mula);
		break;

	}

}
