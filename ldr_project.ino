const int ldrPin = A0;
const int ledPin = 9;

int lightValue = 0;
int threshold = 500;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  lightValue = analogRead(ldrPin);

  Serial.print("LDR Value: ");
  Serial.println(lightValue);

  if (lightValue > threshold) {
    digitalWrite(ledPin, HIGH);  // No shadow / bright: LED ON
  } else {
    digitalWrite(ledPin, LOW);   // Shadow / dark: LED OFF
  }

  delay(100);
}const int ldrPin = A0;
const int ledPin = 9;

int lightValue = 0;
int threshold = 500;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  lightValue = analogRead(ldrPin);

  Serial.print("LDR Value: ");
  Serial.println(lightValue);

  if (lightValue > threshold) {
    digitalWrite(ledPin, HIGH);  // No shadow / bright: LED ON
  } else {
    digitalWrite(ledPin, LOW);   // Shadow / dark: LED OFF
  }

  delay(100);
}