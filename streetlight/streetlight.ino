int LED_Y = 12;
int LED_R = 7;
int LED_G = 8;
int BTN = 2;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_R, OUTPUT);
  pinMode(LED_G, OUTPUT);
  pinMode(LED_Y, OUTPUT);
  pinMode(BTN, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int LED_Y = 12;
  int LED_R = 7;
  int LED_G = 8;

  digitalWrite(LED_G, HIGH);
  delay(5000);
  digitalWrite(LED_G, LOW);
  for (int i = 0; i <= 3; i++) {
    digitalWrite(LED_G, HIGH);
    delay(1000);
    digitalWrite(LED_G, LOW);
    delay(300);
  }
  digitalWrite(LED_G, LOW);
  digitalWrite(LED_Y, HIGH);
  delay(2000);
  digitalWrite(LED_Y, LOW);
  digitalWrite(LED_R, HIGH);
  int c = 0;
  for (int i = 0; i <= 100; i++) {
    int btnstate=digitalRead(BTN);
    if (btnstate == HIGH) {
      c=101;
    }
    delay(100);
    c += 1;
  }
  digitalWrite(LED_Y, HIGH);
  delay(2000);
  digitalWrite(LED_R, LOW);
  digitalWrite(LED_Y, LOW);
}
