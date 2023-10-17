import RPi.GPIO as GPIO
import time

# Set the GPIO mode to BCM
GPIO.setmode(GPIO.BCM)

# Set the GPIO pin number for the IR sensor OUT
ir_sensor_pin = 23  # Replace with your actual GPIO pin number

# Set the GPIO pin number for the buzzer
buzzer_pin = 17  # Replace with the GPIO pin connected to the buzzer

# Configure the GPIO pin as input for the IR sensor
GPIO.setup(ir_sensor_pin, GPIO.IN)

# Configure the GPIO pin as output for the buzzer
GPIO.setup(buzzer_pin, GPIO.OUT)

try:
    while True:
        ir_state = GPIO.input(ir_sensor_pin)
        
        if ir_state:
            print("IR Signal Detected (Short Distance)")
            GPIO.output(buzzer_pin, GPIO.HIGH)  # Turn on the buzzer
        else:
            print("No IR Signal (Short Distance)")
            GPIO.output(buzzer_pin, GPIO.LOW)  # Turn off the buzzer

        time.sleep(0.1)  # Adjust the sleep time as needed

except KeyboardInterrupt:
    print("Exiting due to keyboard interrupt.")
    GPIO.cleanup()
