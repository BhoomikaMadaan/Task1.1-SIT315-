
// C++ code
//
const int motionSensorPin = 2;  // HC-SR505 connected to D2
const int ledPin = 13;          // Built-in LED on Arduino

void setup() {
    pinMode(motionSensorPin, INPUT);  // Sensor input
    pinMode(ledPin, OUTPUT);          // LED output
    Serial.begin(9600);               // Start serial monitor
}

void loop() {
    int motionState = digitalRead(motionSensorPin); // Read motion sensor

    if (motionState == HIGH) {  // If motion detected
        digitalWrite(ledPin, HIGH);  // Turn built-in LED ON
        Serial.println("Motion detected! LED ON");
    } else {  // If no motion detected
        digitalWrite(ledPin, LOW);   // Turn built-in LED OFF
        Serial.println("No motion detected. LED OFF");
    }
    delay(500);  // Delay to prevent excessive logging
}
