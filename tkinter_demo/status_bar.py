# -*- coding: utf-8 -*-

__author__ = 'Ljian'
from tkinter import *

if __name__ == '__main__':
    root = Tk()
    status = Label(root, text='Ln20', bd=1, relief=SUNKEN, anchor=W)
    status.pack(side=BOTTOM, fill=X)
    root.mainloop()

