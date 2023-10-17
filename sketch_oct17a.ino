const int piezoPin1 = A0; // Define the first analog input pin
const int piezoPin2 = A1; // Define the second analog input pin
const int piezoPin3 = A2; // Define the third analog input pin
const int buzzerPin = 7; // Define the digital output pin for the buzzer

void setup() {
  Serial.begin(9600); // Initialize serial communication
  pinMode(buzzerPin, OUTPUT); // Set the buzzer pin as an output
}

void loop() {
  int sensorValue1 = analogRead(piezoPin1); // Read the first sensor
  int sensorValue2 = analogRead(piezoPin2); // Read the second sensor
  int sensorValue3 = analogRead(piezoPin3); // Read the third sensor

  // Check if any sensor value exceeds a threshold
  if (sensorValue1 > 500 || sensorValue2 > 500 || sensorValue3 > 500) {
    // If any sensor detects force, activate the buzzer
    digitalWrite(buzzerPin, HIGH);
    Serial.println("Force detected!");
  } else {
    // If no sensor detects force, turn off the buzzer
    digitalWrite(buzzerPin, LOW);
  }

  // Print sensor values to the serial monitor
  Serial.print("Sensor 1: ");
  Serial.print(sensorValue1);
  Serial.print("\tSensor 2: ");
  Serial.print(sensorValue2);
  Serial.print("\tSensor 3: ");
  Serial.println(sensorValue3);

  delay(1000); // Delay for 1 second (adjust as needed)
}
