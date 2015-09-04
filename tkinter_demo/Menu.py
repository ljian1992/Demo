#!/usr/bin/env python3
# -*- coding: utf-8 -*-

__author__ = 'Ljian'
from tkinter import *


# 菜单:
#   父菜单:
#   子菜单:add_cascade()
#   分割线:add_separator()
#   命令： add_command()
#   更多：http://effbot.org/tkinterbook/menu.htm

def call_back():
    print("called the menu")

if __name__ == '__main__':

    root = Tk()

    # 添加一级菜单
    menu = Menu(root)
    root.config(menu=menu)

    # 添加子菜单
    filemenu = Menu(menu)
    menu.add_cascade(label='File', menu=filemenu)

    # 添加命令
    filemenu.add_command(label='New', command=call_back)
    filemenu.add_command(label='Open', command=call_back)

    filemenu.add_checkbutton()

    # 添加分割线
    filemenu.add_separator()
    filemenu.add_command(label='Exit', command=call_back)

    helpmenu = Menu(menu)
    menu.add_cascade(label='Help', menu=helpmenu)
    helpmenu.add_command(label='About', command=call_back)

    # 添加三级菜单
    editmenu = Menu(menu)
    menu.add_cascade(label='Edit', menu=editmenu)

    edit_find_menu = Menu(editmenu)
    editmenu.add_cascade(label='Find', menu=edit_find_menu)

    edit_find_menu.add_command(label='find', command=call_back)
    edit_find_menu.add_command(label='replace', command=call_back)




    root.mainloop()



