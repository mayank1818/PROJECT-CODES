#include <Adafruit_Fingerprint.h>

#define FINGERPRINT_RX 2
#define FINGERPRINT_TX 3

SoftwareSerial mySerial(FINGERPRINT_RX, FINGERPRINT_TX);

Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial);

#define RELAY_PIN 8

void setup() {
  Serial.begin(9600);
  finger.begin(57600);
  pinMode(RELAY_PIN, OUTPUT);
}

void loop() {
  getFingerprint();
}

void getFingerprint() {
  uint8_t p = finger.getImage();
  if (p != FINGERPRINT_OK) {
    return;
  }

  p = finger.image2Tz();
  if (p != FINGERPRINT_OK) {
    return;
  }

  p = finger.fingerFastSearch();
  if (p == FINGERPRINT_OK) {
    // Fingerprint is verified
    digitalWrite(RELAY_PIN, HIGH); // Open the door
    delay(5000); // Keep the door open for 5 seconds
    digitalWrite(RELAY_PIN, LOW); // Close the door
  } else {
    // Fingerprint is not recognized
  }
}
