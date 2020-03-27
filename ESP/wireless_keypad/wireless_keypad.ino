//# pins to use
//#                    K   J   H   G
const int KP_ROW[] = {15, 13, 12, 14};
//                    D8  D7  D6  D5

//#                   F  E   D
const int KP_COL[] = {2, 0, 4};
//                   D4 D3 D2

const int LED = 16;

int btn = 0;
String key = "";
String out = "";
bool do_loop = true;
int c=0;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);

  //  init KP col keyputs
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
  while (do_loop) {
    for (int col = 0; col < 3; col++) {
      digitalWrite(KP_COL[col], LOW);

      for (int row = 0; row < 4; row++) {
        btn = digitalRead(KP_ROW[row]);

        if (btn == LOW) {
          if (col == 0) {
            if (row == 0) {
              key = "1";
            } else if (row == 1) {
              key = "4";
            } else if (row == 2) {
              key = "7";
            } else if (row == 3) {
              key = "*";
            }

          } else if (col == 1) {
            if (row == 0) {
              key = "2";
            } else if (row == 1) {
              key = "5";
            } else if (row == 2) {
              key = "8";
            } else if (row == 3) {
              key = "0";
            }

          } else if (col == 2) {
            if (row == 0) {
              key = "3";
            } else if (row == 1) {
              key = "6";
            } else if (row == 2) {
              key = "9";
            } else if (row == 3) {
              key = "#";
            }

          }
          btn = digitalRead(KP_ROW[row]);
          while (btn == LOW) {
            btn = digitalRead(KP_ROW[row]);
          }
          delay(200);

          if (key == "*") {
            out = "";
            digitalWrite(LED, HIGH);
            delay(3000);
            digitalWrite(LED, LOW);
          } else if (key == "#") {
            do_loop = false;
            digitalWrite(LED, HIGH);
            delay(1000);
            digitalWrite(LED, LOW);
            delay(500);
            digitalWrite(LED, HIGH);
            delay(1000);
            digitalWrite(LED, LOW);
          } else {
            out += key;

            c=0;
            while (key.toInt() >= c){
              digitalWrite(LED, HIGH);
              delay(500);
              digitalWrite(LED, LOW);
              c++; 
            }
          }
        }

      }

      digitalWrite(KP_COL[col], HIGH);
      // --- END get key ---
    }
  }
}
