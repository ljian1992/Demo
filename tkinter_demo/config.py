# -*- coding: utf-8 -*-

__author__ = 'Ljian'
from tkinter import *


if __name__ == '__main__':
    root = Tk()
    lable = Label(root, text='hello')

    # 属性配置在类的构造完成后，再进行配置
    # 属性配置：大小，颜色，字体，边界，鼠标，等
    # 相关网站：http://effbot.org/tkinterbook/tkinter-widget-styling.htm
    lable.config(cursor='gumby')
    lable.config(width=80, height=10, fg='red', bg='dark green')
    lable.config(font=('times', '26', 'bold'))
    lable.pack()
    root.mainloop()



