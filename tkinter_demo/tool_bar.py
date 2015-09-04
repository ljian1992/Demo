# -*- coding: utf-8 -*-

__author__ = 'Ljian'
from tkinter import *

def call_back():
    print("clicked tool bar button")

if __name__ == '__main__':
    root = Tk()
    tool_bar = Frame(root)

    b = Button(tool_bar, text='new', width=6, command=call_back)
    b.pack(side=LEFT, padx=2, pady=2)

    c = Button(tool_bar, text='open', width=6, command=call_back)
    c.pack(side=LEFT, padx=2, pady=2)

    tool_bar.pack(side=TOP, fill=X)
    root.mainloop()






