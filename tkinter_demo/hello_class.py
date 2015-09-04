# -*- coding: utf-8 -*-

__author__ = 'Ljian'
from tkinter import *

class App(object):
    def __init__(self, master):
        frame = Frame(master)
        frame.pack()
        self.button = Button(frame, text='exit', fg='red', command=frame.quit)

        self.button.pack()

        self.hiButton = Button(frame, text='Hi', command=self.say_hi)
        self.hiButton.pack()

    def say_hi(selfself):
        print("Hi Ljian")

if __name__ == '__main__':
    root = Tk()
    app = App(root)
    root.mainloop()

