#define LED_PIN 8
#define POT_PIN A0

int anal_sig, pwm;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  pwm = map(analogRead(POT_PIN), 0, 1023, 0, 255);
  analogWrite(LED_PIN, pwm);
  Serial.println(pwm);
}
