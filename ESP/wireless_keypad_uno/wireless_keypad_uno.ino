// File: wireless_keypad
// Author: Nicolas Fischer
// Version: 0.0.1.1
// Program: Arduino
// Ext: .ino
// FOR ARDUINO UNO
// ------------------------

// source: https://diyi0t.com/keypad-tutorial-for-arduino-and-esp8266/

#include <Keypad.h> // Add Keypad library

//# pins to use
//#               K   J   H   G
byte KP_ROW[] = {2, 3, 4, 5};
//               D0  D1  D2  D3

//#              F  E   D
byte KP_COL[] = {8, 9, 10};
//               D4 D5 D6 (D7)

const byte KY_ROW = 4;
const byte KY_COL = 3;

char KEYS[KY_ROW][KY_COL] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};

//Keypad keypad = Keypad(makeKeymap(KEYS), KP_ROW, KP_COL, KY_ROW, KY_COL); //Keypad keypad = Keypad(makeKeymap(KEYS), KP_ROW, KP_COL, KY_ROW, KY_COL);

int btn = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  for (int i = 0; i < 3; i++) {
    pinMode(KP_COL[i], OUTPUT);
    digitalWrite(KP_COL[i], HIGH);
  }
  for (int i = 0; i < 4; i++) {
    pinMode(KP_ROW[i], INPUT);
  }

}

void loop() {
  // put your main code here, to run repeatedly:

  for (int col = 0; col < 3; col++) {
    //    Serial.print("Col: ");
    //    Serial.println(col);
    digitalWrite(KP_COL[col], LOW);

    for (int row = 0; row < 4; row++) {
      btn = digitalRead(KP_ROW[row]);
      Serial.println("Row: " + String(row) + /*" Pin " + String(KP_ROW[row]) +*/ " Char: " + String(KEYS[row][col]) + " State: " + String(btn));
//      btn = 0;
      delay(1000);
    }
    digitalWrite(KP_COL[col], HIGH);
    Serial.println();
  }
}
