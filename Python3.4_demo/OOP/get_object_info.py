# -*- coding: utf-8 -*-
__author__ = 'Ljian'
import types

# <-----------------获取对象的类型-----------------------

class A(object):
    print("A")



def func():
    pass

# <------------------------type()判断类型---------------------------
# type()方法的实现就是返回类型中的__class__内置变量
def mytype(obj):
    return obj.__class__


print(int('123').__class__)
print(type(123))
print(mytype(123) == int)
print(type(123) == int)
print(type(abs))
print(type(A()))
print(type(A()) == A)
print(mytype(A()) == A)


# <----------------判断对象是否是函数----------------------
# types中提供了各种常量，用于type(xxx) xxx是什么类型
print(type(func) == types.FunctionType)
print(type(func) == types.BuiltinFunctionType)
print(type(abs) == types.BuiltinFunctionType)
print(type(lambda x: x+y) == types.LambdaType)
print(type(x for x in range(1, 10)) == types.GeneratorType)


# <------------------------isinstance()判断类型---------------------------
# isinstance()可以判断对象本身是否位于该类型的父继承链上,可以判断是否是多种类型的其中一个


print("<------------------------isinstance()判断类型---------------------------")
class B(A):pass

class C(B):pass

class D(B):pass

a = A()
b = B()
c = C()
d = D()

print(isinstance(a, A))
print(isinstance(a, B))
print(isinstance(b, A))
print(isinstance(b, A) and isinstance(b, B))

#判断对象是否是多种类型中的一个
print(isinstance(c, D))
print(isinstance(c, (A, B, C, D)))


# <-----------------------------操作一个对象的状态-------------------------
# getattr() -- 获取对象属性
# setattr -- 设置一个对象属性
# hasattr() -- 判断对象是否有该属性
# del -- 可删除对象属性


print("#<-----------------------------操作一个对象的状态-------------------------")
class MyObject(object):
   def __init__(self, number):
       self.number = number

   def print_number(self):
       print("number: %r" % self.number)

obj = MyObject(10)
o
print(hasattr(obj, 'print_number'))
getattr(obj, 'print_number')()

print(getattr(obj, 'name', 'None'))
setattr(obj, 'name', 'Ljian')
print(getattr(obj, 'name', 'None'))

del obj.name
print(getattr(obj, 'name', 'None'))

# 一个正常的用法
def readImage(fp):
    if hasattr(fp, 'read'):
        return fp.read()
    return None