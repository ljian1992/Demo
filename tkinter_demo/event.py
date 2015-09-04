#!/usr/bin/env python3
# -*- coding: utf-8 -*-

__author__ = 'Ljian'

from tkinter import *
import tkinter.messagebox as messagebox

# 事件类型：点击事件, 状态事件, 窗体事件
# 实现事件方式：command, bind, protocol, event_generator

def button_click():
    print("button clicked")


def call_back(event):
    frame.focus_set()
    print("clicked at:", event.x, event.y)

def key(event):
    print("pressed: ", event.char)


def close_window():
    if messagebox.askokcancel("Quit", "Do you really wish to quit?"):
        root.destroy()

if __name__ == '__main__':

    root = Tk()

    # command方式
    button = Button(text='hello', command=button_click)
    button.pack()

    # bind
    frame = Frame(root, width=100, height=100)
    frame.bind('<Button-1>', call_back)
    frame.bind('<Key>', key)
    frame.pack()

    # protocol
    root.protocol('WM_DELETE_WINDOW', close_window)

    root.mainloop()


