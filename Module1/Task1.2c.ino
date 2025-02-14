#define PIR_SENSOR_PIN 2   // PIR motion sensor digital pin
#define TMP_SENSOR_PIN A0  // TMP temperature sensor analog pin
#define LED_PIN 13         // Built-in LED

volatile bool motionDetected = false;

void motionISR() {
  motionDetected = true;
}

void setup() {
  pinMode(PIR_SENSOR_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  
  Serial.begin(9600);

  // Attach interrupt for motion detection
  attachInterrupt(digitalPinToInterrupt(PIR_SENSOR_PIN), motionISR, RISING);
}

void loop() {
  // Read temperature from TMP sensor
  int rawValue = analogRead(TMP_SENSOR_PIN);
  float voltage = rawValue * (5.0 / 1023.0);  // Convert to voltage
  float temperatureC = (voltage - 0.5) * 100.0;  // Convert to °C (depends on sensor type)

  Serial.print("Temperature: ");
  Serial.print(temperatureC);
  Serial.println(" °C");

  // Check for motion
  if (motionDetected) {
    Serial.println("Motion Detected!");
    digitalWrite(LED_PIN, HIGH);
    delay(500);
    digitalWrite(LED_PIN, LOW);
    motionDetected = false;
  }

  delay(1000);  // Read temperature every second
}
