// File: wireless_keypad
// Author: Nicolas Fischer
// Version: 0.0.1.1
// Program: Arduino
// Ext: .ino
// ------------------------

// source: https://diyi0t.com/keypad-tutorial-for-arduino-and-esp8266/

#include <Keypad.h>

const byte ROWS = 4; //four rows
const byte COLS = 3; //four columns
//define the cymbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};
byte rowPins[ROWS] = {D6, D5, D4, D3}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {D2, D1, D0}; //connect to the column pinouts of the keypad

//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

void setup(){
  Serial.begin(115200);
  Serial.println("Hello World");
}
  
void loop(){
  char customKey = customKeypad.getKey();
  
  if (customKey){
    Serial.println(customKey);
    }
}
