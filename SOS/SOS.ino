void setup() {
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  for (int i = 0; i < 3; i += 1) {
    ON();
    delay(500);
    digitalWrite(LED_BUILTIN, LOW);
    delay(500);
  }
  delay(500);
  for (int i = 0; i < 3; i += 1) {
    ON();
    delay(1000);
    digitalWrite(LED_BUILTIN, LOW);
    delay(500);
  } 
  delay(500);
  for (int i = 0; i < 3; i += 1) {
    ON();
    delay(500);
    digitalWrite(LED_BUILTIN, LOW);
    delay(500);
  } delay(500);
  delay(5000);

}

void ON() {
  digitalWrite(LED_BUILTIN, HIGH);
}
