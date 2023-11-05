#include <LiquidCrystal.h>

//#include "SoftwareSerial.h"

 

// initialize the library by associating any needed LCD interface pin

// with the arduino pin number it is connected to

const int rs = A0, en = A1, d4 = A2, d5 = A3, d6 = A4, d7 = A5;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

String firstLine = "    -      -       ";

String secondLine = "       u       ";

String thirdLine = "    o      o       ";

String fourthLine = "       v       ";

String fifthLine = "    >      <       ";

String sixLine = "       c       ";

 

 

// Pin connections to the 4-digit seven-segment display

int digitPins[] = {10, 11, 12, 13}; // Anodes (digit selection pins)

int segmentPins[] = {2,3,5,6,7,8,9}; // Cathodes (segment control pins)

 

// bluetooth

//SoftwareSerial EEBlue(0,1);// RX | TX

 

// Define the common cathode 7-segment display characters

byte numbers[] = {

  B01101111, // 0

  B00000011, // 1

  B01011101, // 2

  B01010111, // 3

  B00110011, // 4

 B01110110, // 5

  B01111110, // 6

  B01000011, // 7

  B01111111, // 8

  B01110111  // 9

};

 

// Function to display a character on a specific digit

void displayDigit(int digit, int value) {

  // Activate the desired digit

  for (int i = 0; i < 4; i++) {

    digitalWrite(digitPins[i], i == digit ? LOW : HIGH);

  }

 

  // Display the value on the segments

  for (int i = 0; i < 7; i++) {

    digitalWrite(segmentPins[i], bitRead(numbers[value], i));

  }

}

 

// Function to clear the display

void clearDisplay() {

  for (int i = 0; i < 4; i++) {

    digitalWrite(digitPins[i], HIGH);

  }

}

 

void setup() {

  lcd.begin(16, 2);  // Set the LCD size (columns x rows)

 

  // Initialize hex pins

  for (int i = 0; i < 4; i++) {

    pinMode(digitPins[i], OUTPUT);

  }

  for (int i = 0; i < 7; i++) {

    pinMode(segmentPins[i], OUTPUT);

  }

  Serial.begin(9600);

//  EEBlue.begin(9600);


}

 

 

static unsigned long previousMillis = 0;

static int second = 0;

static int minute = 0;

static int hour = 0;

 

 

static unsigned long displayMillis = 0;

static int gagasecond = 0;

bool gagaState = 0;

 

void displayEmotion() {

 

  if (gagaState == 1) {

    gagaState = 0;

    lcd.setCursor(0, 0);

    lcd.print(firstLine);

    lcd.setCursor(0, 1);

    lcd.print(secondLine);

  } else {

    gagaState = 1;

    lcd.setCursor(0, 0);

    lcd.print(fifthLine);

    lcd.setCursor(0, 1);

    lcd.print(sixLine);

  }

}

 

int displayValues[] = {0, 0, 0, 0};

 

void displayAll() {

  unsigned long starttime = millis();

  unsigned long endtime = starttime;

  while ((endtime - starttime) <=1000) {

    for (int digit = 0; digit < 4; digit++) {

      displayDigit(digit, displayValues[digit]);

      delay(5); // Short delay between digit updates

      clearDisplay(); // Clear the display to avoid ghosting

    }

    endtime = millis();

  }

}

 

void addOne() {

  int c = 0;

 

  // 1st to the right

  if (displayValues[3] + 1 + c == 10) {

    displayValues[3] = 0;

    c = 1;

  } else {

    displayValues[3] = displayValues[3] + 1;

    c = 0;

  }

 

  // 2nd to the right

  if (displayValues[2] + c == 6) {

    displayValues[2] = 0;

    c = 1;

  } else {

    displayValues[2] = displayValues[2] + c;

    c = 0;

  }

 

  // 3rd to the right

  if (displayValues[0] != 2) {

    if (displayValues[1] + c == 10) {

      displayValues[1] = 0;

      c = 1;

    } else {

      displayValues[1] = displayValues[1] + c;

      c = 0;

    }

  } else {

    if (displayValues[1] + c == 4) {

      displayValues[1] = 0;

      c = 1;

    } else {

      displayValues[1] = displayValues[1] + c;

      c = 0;

    }

  }

 

  // 4th to the right

  if (displayValues[0] + c == 3) {

    displayValues[0] = 0;

    c = 0;

  } else {

    displayValues[0] = displayValues[0] + c;

    c = 0;

  }

 

}

 

static int count = 0;

 

void loop(){

  // debugging

  // Serial.println("hi winnie, I love youuu");

   //Serial.println(millis());

   int index = 0;

 

  // bluetooth

 

//  if (EEBlue.available() > 0) {
//
//    displayValues[index] = EEBlue.read(); // Read the integers from Bluetooth
//
//  }

 

  // displays

  displayEmotion();

  displayAll();

  count++;

  if (count == 60) {

    addOne();

  }

}
