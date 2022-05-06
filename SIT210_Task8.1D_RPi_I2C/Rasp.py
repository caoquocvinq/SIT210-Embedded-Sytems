from signal import signal, SIGTERM, SIGHUP, pause
from time import sleep
from threading import Thread
from gpiozero import DistanceSensor
from rpi_lcd import LCD


running = True
distance_message = ""

lcd = LCD()
sensor = DistanceSensor(echo=4, trigger=17)

def safe_exit():
    exit(1)

def read_distance():
    global distance_message
    while running:
        if(sensor.value > 1.0):
            distance_message = f'Distance: {sensor.value:1.2f} m Too Far'
            print(distance_message)
            sleep(0.1)
        if(sensor.value > 0.4 && sensor.value < 1):
            distance_message = f'Distance: {sensor.value:1.2f} m Close Enough'
            print(distance_message)
            sleep(0.1)
        if(sensor.value < 0.4):
            distance_message = f'Distance: {sensor.value:1.2f} m Too close'
            print(distance_message)
            sleep(0.1)

def update_display():
    global distance_message
    while running:
        lcd.text(distance_message, 1)
        sleep(0.25)

def main():
    try:
        signal(SIGTERM, safe_exit)
        signal(SIGHUP, safe_exit)
        reader = Thread(target=read_distance, daemon=True)
        display = Thread(target=update_display, daemon=True)
        reader.start()
        display.start()
        pause()
    except KeyboardInterrupt:
        pass
    finally:
        global running
        running = False
        reader.join()
        display.join()
        lcd.clear()
        sensor.close()

if __name__ == '__main__':
    main()