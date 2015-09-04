# -*- coding: utf-8 -*-
__author__ = 'Ljian'

from metaclass_test import Hello

h = Hello()
print(type(Hello))
print(type(h))


# <------------------------------类的动态创建---------------------------
# type()既可以返回一个对象，又可以创建出新的类型
# python解析器遇到class定义时，调用type()函数创建出class

# 通过type()创新新的类型
# 1.类型名
# 2.继承的父类集合
# 3.方法名称和属性变量与函数绑定和变量绑定

def print_hello_world(self):
    print("Hello World")

Hello = type('Hello', (object,), dict(print_hello_world = print_hello_world, name = 'Hello Class'))
h = Hello()
h.print_hello_world()
print(h.name)

print(type(Hello))
print(type(h))

# <------------------------------通过metaclass控制类的创建行为---------------------------
# 创建metaclass--->创建类--->创建实例


