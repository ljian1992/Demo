# -*- coding: utf-8 -*-
__author__ = 'Ljian'



L = [3, 5, -13, 56,-12, 78]
print(L)
print(sorted(L))


# 排序过程，现在安装key=abs作用于L后的结果排序，在安装对应关系返回list中的元素
print(sorted(L, key=abs))

L = [('Bob', 75), ('Adam', 92), ('Bart', 66), ('Lisa', 88)]

print(sorted(L))
print(sorted(L, key = lambda x: x[1]))





