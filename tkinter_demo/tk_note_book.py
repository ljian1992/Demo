# -*- coding: utf-8 -*-

__author__ = 'Ljian'
from tkinter import *
import tkinter.messagebox as messagebox
import tkinter.filedialog as filedialog
import os

filename = ''
root = Tk()

def author():
    messagebox.showinfo('作者信息', 'Ljian1992')

def version():
    messagebox.showinfo('版本', 'V1.0')

def open_file():
    global filename, root
    filename = filedialog.askopenfilename(defaultextension='.txt')
    print('filename:', filename)

    if filename:
        root.title('FileName:'+os.path.basename(filename))
        text_pad.delete(1.0, END)
        with open(filename, 'r', encoding='utf-8') as f:
            text_pad.insert(1.0, f.read())
    else:
         filename = None

def new_file():
    global filename, root
    root.title('未命名文件')
    filename = None
    text_pad.delete(1.0, END)


def save_as_file():
    global filename, root
    f = filedialog.asksaveasfilename(initialfile='未命名文件.txt', defaultextension='.txt')
    with open(f, 'w', encoding='utf-8') as fh:
        msg = text_pad.get(1.0, END)
        fh.write(msg)
    root.title('fioenName:'+os.path.basename(f))

def save_file():
    global filename, root
    try:
        with open(filename, 'w', encoding='utf-8') as f:
            msg = text_pad.get(1.0, END)
            f.write(msg)
    except Exception:
        save_as_file()

def cut():
    text_pad.event_generate('<<Cut>>')

def copy():
    text_pad.event_generate('<<Copy>>')

def paste():
    text_pad.event_generate('<<Paste>>')

def redo():
    text_pad.event_generate('<<Redo>>')

def undo():
    text_pad.event_generate('<<Undo>>')

def select_all():
    text_pad.tag_add('sel', '1.0', END)





def search():
    def do_search():
        obj_str = find_entry.get()
        start_pos = '1.0'
        is_first = True
        tag_name = 'obj_tag'

        text_pad.tag_delete(tag_name)
        while True:
            pos = text_pad.search(obj_str, start_pos, stopindex=END)

            if not pos:
                if is_first:
                    messagebox.showwarning(message='没有找到')
                break

            if is_first:
                is_first = False

            # 设置下一个起始位置
            start_pos = str(round(float(pos)+len(obj_str)/10, 1))

            print('pos:', pos)
            print('start_pos:', start_pos)
            text_pad.tag_add(tag_name, pos, start_pos)
        text_pad.tag_config(tag_name, background="yellow")


    top_search = Toplevel(root)
    top_search.geometry('250x40+400+400')

    find_label = Label(top_search, text='Find')
    find_label.grid(row=0, column=0, padx=5)
    find_entry = Entry(top_search, width=20)
    find_entry.grid(row=0, column=1, padx=5)
    find_button = Button(top_search, text='查找', command=do_search)
    find_button.grid(row=0, column=2)


if __name__ == '__main__':

    root.title('Note')

    # 构建一个几何窗体, 960x600大小， 左上角点为:(200，200)
    root.geometry('960x600+200+200')

    # --------------菜单设置--------------
    menu_bar = Menu(root)
    root.config(menu=menu_bar)

    # 文件菜单
    file_menu = Menu(menu_bar)
    file_menu.add_command(label='新建', accelerator='Ctrl + N', command=new_file)
    file_menu.add_command(label='打开', accelerator='Ctrl + O', command=open_file)
    file_menu.add_command(label='保存', accelerator='Ctrl + S', command=save_file)
    file_menu.add_command(label='另存为', accelerator='Ctrl + Shift + S', command=save_as_file)
    menu_bar.add_cascade(label='文件', menu=file_menu)


    # 编辑菜单
    edit_menu = Menu(menu_bar)
    edit_menu.add_command(label='撤销', accelerator='Ctrl + Z', command=undo)
    edit_menu.add_command(label='重做', accelerator='Ctrl + Y', command=redo)
    edit_menu.add_separator()

    edit_menu.add_command(label='剪切', accelerator='Ctrl + X', command=cut)
    edit_menu.add_command(label='复制', accelerator='Ctrl + C', command=copy)
    edit_menu.add_command(label='粘贴', accelerator='Ctrl + V', command=paste)
    edit_menu.add_separator()

    edit_menu.add_command(label='查找', accelerator='Ctrl + F', command=search)
    edit_menu.add_command(label='全选', accelerator='Ctrl + A', command=select_all)
    menu_bar.add_cascade(label='编辑', menu=edit_menu)

    # 关于菜单
    about_menu = Menu(menu_bar)
    about_menu.add_command(label='作者', command=author)
    about_menu.add_command(label='版本', command=version)
    menu_bar.add_cascade(label='关于', menu=about_menu)


    # --------------状态栏--------------
    status_bar = Label(root, text='Ln20', bd=1, relief=SUNKEN, anchor=W)
    status_bar.pack(side=BOTTOM, fill=X)


    # --------------文本--------------
    # 左侧
    line_label = Label(root, width=2, bg='antique white')
    line_label.pack(side=LEFT, fill=Y)

    # 文本域
    text_pad = Text(root, undo=True)
    text_pad.pack(expand=YES, fill=BOTH)

    # 右侧划动条
    scroll = Scrollbar(text_pad)
    scroll.pack(side=RIGHT, fill=Y)
    scroll.config(command=text_pad.yview)
    text_pad.config(yscrollcommand=scroll.set)


    root.mainloop()
