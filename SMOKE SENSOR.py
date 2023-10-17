import RPi.GPIO as GPIO
import time

# GPIO pins
SMOKE_SENSOR_PIN = 17
BUZZER_PIN = 18

def setup_gpio():
    GPIO.setwarnings(False)
    GPIO.setmode(GPIO.BCM)
    GPIO.setup(SMOKE_SENSOR_PIN, GPIO.IN)
    GPIO.setup(BUZZER_PIN, GPIO.OUT)

def smoke_detected(channel):
    print("Smoke detected! Alarm activated.")
    GPIO.output(BUZZER_PIN, GPIO.HIGH)
    time.sleep(5)  # Buzzer sounds for 5 seconds
    GPIO.output(BUZZER_PIN, GPIO.LOW)

def main():
    setup_gpio()
    GPIO.add_event_detect(SMOKE_SENSOR_PIN, GPIO.RISING, callback=smoke_detected)
    
    print("Smoke detection system is running. Press Ctrl+C to exit.")
    
    try:
        while True:
            time.sleep(1)
    except KeyboardInterrupt:
        GPIO.cleanup()
        print("Exiting.")

if __name__ == "__main__":
    main()
