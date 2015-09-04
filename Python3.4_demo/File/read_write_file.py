# -*- coding: utf-8 -*-
__author__ = 'Ljian'

# open()这个函数返回一个具有read()方法的对象，在python中具有read()方法的对象，统称为file-like-Object。（鸭子类型的又一个案例）

with open('The_Zen_of_Python') as f:
    for line in f.readlines():
        print(line.strip())

# 图片，视频等二级制文件，需要用'rb'打开
with open('tifa.jpg', 'rb') as f:
    for line in f.readlines():
        print(line)

# 字符编码,通过encoding参数指定编码格式后，文件utf-8--->内存Unicode--->文件utf-8
with open('The_Zen_of_Python', 'r', encoding='utf-8', errors='ignore') as f:
    pass

