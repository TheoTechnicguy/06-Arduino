void setup() {
  // put your setup code here, to run once:
  int LED_Y = 12;
  int LED_R = 7;
  int LED_G = 8;
  pinMode(LED_R, OUTPUT);
  pinMode(LED_G, OUTPUT);
  pinMode(LED_Y, OUTPUT);
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
  delay(5000);
  digitalWrite(LED_Y, HIGH);
  delay(2000);
  digitalWrite(LED_R, LOW);
  digitalWrite(LED_Y, LOW);
}
