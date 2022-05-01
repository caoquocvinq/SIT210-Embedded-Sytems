import RPi.GPIO as GPIO
from tkinter import *
from time import sleep
from tkinter import messagebox


GPIO.setmode(GPIO.BOARD)
GPIO.setup(8, GPIO.OUT, initial=GPIO.LOW)


root = Tk()
root.title("Blink your text in Morse Code")

entry = Entry(root,width=60)
entry.pack()

def dot():
    GPIO.output(8, GPIO.HIGH)
    sleep(0.5)
    GPIO.output(8, GPIO.LOW)
    sleep(1)

def dash():
import RPi.GPIO as GPIO
from tkinter import *
from time import sleep
from tkinter import messagebox


GPIO.setmode(GPIO.BOARD)
GPIO.setup(8, GPIO.OUT, initial=GPIO.LOW)


root = Tk()
root.title("Blink your text in Morse Code")

entry = Entry(root,width=60)
entry.pack()

def dot():
    GPIO.output(8, GPIO.HIGH)
    sleep(0.5)
    GPIO.output(8, GPIO.LOW)
    sleep(1)

def dash():
    GPIO.output(8, GPIO.HIGH)
    sleep(1)
    GPIO.output(8, GPIO.LOW)
    sleep(1)

def clicked():
    if(len(entry.get()) > 12):
      messagebox.showinfo(message="> 12 characters only") 
    morse = encrypt(entry.get().upper()[:12]) #use upper case to match with the morse code dictionary
    print("Your input in morse code: {}" .format(morse)) 
    for i in range(0,len(morse)):
        if(morse[i]=="."): #dot
            dot()
        elif(morse[i]=="-"): #dash
            dash()
        else:
            sleep(1) #space


myButton = Button(root, text="Only 12 characters", command=clicked)
myButton.pack()

#reference: https://www.geeksforgeeks.org/morse-code-translator-python/
#this reference is used for encrypting what the user input into morse code
#in order for the above function to scan through every single item
#in the string which can be dot or dash or space and then tell the led
#to blink accordingly.

MORSE_CODE_DICT = { 'A':'.-', 'B':'-...',
                    'C':'-.-.', 'D':'-..', 'E':'.',
                    'F':'..-.', 'G':'--.', 'H':'....',
                    'I':'..', 'J':'.---', 'K':'-.-',
                    'L':'.-..', 'M':'--', 'N':'-.',
                    'O':'---', 'P':'.--.', 'Q':'--.-',
                    'R':'.-.', 'S':'...', 'T':'-',
                    'U':'..-', 'V':'...-', 'W':'.--',
                    'X':'-..-', 'Y':'-.--', 'Z':'--..',
                    '1':'.----', '2':'..---', '3':'...--',
                    '4':'....-', '5':'.....', '6':'-....',
                    '7':'--...', '8':'---..', '9':'----.',
                    '0':'-----', ', ':'--..--', '.':'.-.-.-',
                    '?':'..--..', '/':'-..-.', '-':'-....-',
                    '(':'-.--.', ')':'-.--.-'}
 
def encrypt(message):
    cipher = ''
    for letter in message:
        if letter != ' ':
            cipher += MORSE_CODE_DICT[letter] + ' '
        else:
            cipher += ' '
    return cipher

mainloop()