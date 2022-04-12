import RPi.GPIO as GPIO
import time
from gpiozero import PWMLED

GPIO.setmode(GPIO.BCM)

led = PWMLED(17)
GPIO_TRIGGER = 24
GPIO_ECHO = 8
GPIO.setup(GPIO_TRIGGER, GPIO.OUT)
GPIO.setup(GPIO_ECHO, GPIO.IN)

def distance():
	
	GPIO.output(GPIO_TRIGGER, True)
	
	time.sleep(0.00001)
	GPIO.output(GPIO_TRIGGER, False)
	
	StartTime = time.time()
	StopTime = time.time()
	
	while GPIO.input(GPIO_ECHO) == 0:
		StartTime = time.time()
	
	while GPIO.input(GPIO_ECHO) == 1:
		StopTime = time.time()
	
	TimeElapsed = StopTime - StartTime
	distance = (TimeElapsed * 34300) / 2
	
	return distance
	
if __name__ == '__main__':
    try:

        led.on()
        while True:
            dist = distance()
            print("Measured Distance = %.1f cm" % dist)
            duty_cycle = round(1- dist/100,1)
            if duty_cycle <0:
                duty_cycle = 0.0
            print("duty = %.1f " % duty_cycle)
            led.value = duty_cycle
            time.sleep(0.1)
    except KeyboardInterrupt:
        print("Measurement stopped by User")
        GPIO.cleanup()
