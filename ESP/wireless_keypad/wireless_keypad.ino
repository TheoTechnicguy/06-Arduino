// File: wireless_keypad
// Author: Nicolas Fischer
// Version: 0.0.1.1
// Program: Arduino
// Ext: .ino
// ------------------------

// source: https://diyi0t.com/keypad-tutorial-for-arduino-and-esp8266/

//# pins to use
//#                    K   J   H   G
const int KP_ROW[] = {15, 13, 12, 14};
//                    D8  D7  D6  D5

//#                   F  E   D
const int KP_COL[] = {2, 0, 4};
//                   D4 D3 D2

const byte KY_ROW = 4;
const byte KY_COL = 3;

char KEYS[KY_ROW][KY_COL] = {
  {"1", "2", "3"},
  {"4", "5", "6"},
  {"7", "8", "9"},
  {"*", "0", "#"}
};

int btn = 0;
String key = "";

void setup() {
  // put your setup code here, to run once:

  //  init KP col keyputs
  for (int i = 0; i < 3; i++) {
    pinMode(KP_COL[i], OUTPUT);
    digitalWrite(KP_COL[i], HIGH);
  }

  for (int i = 0; i < 4; i++) {
    pinMode(KP_ROW[i], INPUT);
  }

  Serial.begin(15200);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int col = 0; col < 3; col++) {
    digitalWrite(KP_COL[col], LOW);

    for (int row = 0; row < 4; row++) {
      btn = digitalRead(KP_ROW[row]);

      if (btn == LOW) {
        key = KEYS[row][col];

        btn = digitalRead(KP_ROW[row]);

        while (btn == LOW) {
          btn = digitalRead(KP_ROW[row]);
        }
        delay(200);

        Serial.println(key);
      }
    }
  }

  digitalWrite(KP_COL[col], HIGH);
  // --- END get key ---
}
}
}
