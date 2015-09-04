# -*- coding: utf-8 -*-
__author__ = 'Ljian'

# 函数名即是变量
print(abs(-10))
myabs = abs
print(myabs(-10))


# 函数名可以被赋值
print(type(abs))
abs = 10
print(type(abs))

# del 可以恢复函数本来的用法
del abs

# 函数参数接受函数, 类似于函数指针
def add(a, b, f):
    return f(a) + f(b)

print(add(-10, -20, abs))