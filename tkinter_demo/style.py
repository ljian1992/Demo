# -*- coding: utf-8 -*-

__author__ = 'Ljian'
from tkinter import *

if __name__ == '__main__':

    root = Tk()

    # 属性配置：大小，颜色，字体，边界，鼠标，等
    # 相关网站：http://effbot.org/tkinterbook/tkinter-widget-styling.htm
    button = Button(root, text='Button', padx=10, pady=10)
    button.config(cursor='gumby')
    button.config(bd=8, relief=RAISED)
    button.config(bg='green', fg='yellow')
    button.config(font=("Helvetica", 10, "bold", "italic"))
    button.pack()

    root.mainloop()



