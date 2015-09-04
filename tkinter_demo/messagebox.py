# -*- coding: utf-8 -*-

__author__ = 'Ljian'

from tkinter import *
import tkinter.messagebox as messagebox

def call_back():
    if messagebox.askyesno('Hi', 'Hi Ljian'):
        print("Clicked Yes")
    else:
        print("Clicked No")

    if messagebox.askyesnocancel('Hi', 'Hi Ljian'):
        print("Clicked Yes")
    else:
        print("Clicked No")

    if messagebox.askokcancel('Hi', 'Hi Ljian'):
        print("Clicked Yes")
    else:
        print("Clicked No")

    if messagebox.askquestion('Hi', 'Hi Ljian'):
        print("Clicked Yes")
    else:
        print("Clicked No")

if __name__ == '__main__':
    root = Tk()

    b = Button(root, text='Button', command=call_back)
    b.pack()
    root.mainloop()

