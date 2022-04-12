import tkinter as tk
import RPi.GPIO as GPIO
from time import sleep

GPIO3 = 2
GPIO5 = 3
GPIO7 = 4

GPIO.setmode(GPIO.BCM)
GPIO.setup(GPIO3, GPIO.OUT)
GPIO.setup(GPIO5, GPIO.OUT)
GPIO.setup(GPIO7, GPIO.OUT)

master = tk.Tk()
master.title("LED Toggling")
master.geometry("400x300")

GPIO3_state = True
GPIO5_state = True
GPIO7_state = True

def GPIO3Button():
	global GPIO3_state
	if GPIO3_state == True:
		GPIO.output(GPIO3,GPIO3_state)
		GPIO3_state  = False
		ONlabel = tk.Label(master,text="Turned ON",fg ="green")
		ONlabel.grid(row = 0,column =1)
	else: 
		GPIO.output(GPIO3,GPIO3_state)
		GPIO3_state  = True
		OFFlabel = tk.Label(master,text="Turned OFF",fg ="red")
		OFFlabel.grid(row = 0,column =1)

def GPIO5Button():
	global GPIO5_state
	if GPIO5_state == True:
		GPIO.output(GPIO5,GPIO5_state)
		GPIO5_state  = False
		ONlabel = tk.Label(master,text="Turned ON",fg ="green")
		ONlabel.grid(row = 1,column =1)
	else: 
		GPIO.output(GPIO5,GPIO5_state)
		GPIO5_state  = True
		OFFlabel = tk.Label(master,text="Turned OFF",fg ="red")
		OFFlabel.grid(row = 1,column =1)

def GPIO7Button():
	global GPIO7_state
	if GPIO7_state == True:
		GPIO.output(GPIO7,GPIO7_state)
		GPIO7_state  = False
		ONlabel = tk.Label(master,text="Turned ON",fg ="green")
		ONlabel.grid(row = 2,column =1)
	else: 
		GPIO.output(GPIO7,GPIO7_state)
		GPIO7_state  = True
		OFFlabel = tk.Label(master,text="Turned OFF",fg ="red")
		OFFlabel.grid(row = 2,column =1)

ONbutton = tk.Button(master, text="BLUE LIGHT", bg = "BLUE", command = GPIO3Button)
ONbutton.grid(row=0, column=0)

ONbutton = tk.Button(master, text="GREEN LIGHT", bg = "GREEN", command = GPIO5Button)
ONbutton.grid(row=1, column=0)

ONbutton = tk.Button(master, text="RED LIGHT", bg = "RED", command = GPIO7Button)
ONbutton.grid(row=2, column=0)

Exitbutton = tk.Button(master, text ="EXIT", bg = "RED", command = master.destroy)
Exitbutton.grid(row=3, column=0)

master.mainloop()
