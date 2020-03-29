#include "Keypad.h"
const byte ROWS = 4; //four rows
const byte COLS = 3; //four columns

char keys[ROWS][COLS] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};
byte rowPins[ROWS] = {D8, D7, D6, D5};
byte colPins[COLS] = {D4, D3, D2};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup() {
  Serial.begin(115200);
  for (int i=0; i<3; i++){
    pinMode(rowPins[i], INPUT);
  }
  for (int i=0; i<4; i++){
    pinMode(colPins[i], OUTPUT);
  }
}

void loop() {
  char key = keypad.getKey();

   if (key != NULL){
    Serial.print("Key pressed: ");
    Serial.println(key);
  }
}
