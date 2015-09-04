# -*- coding: utf-8 -*-
__author__ = 'Ljian'
from collections import Iterator
from collections import Iterable
from functools import reduce

# map(function_object, iterable_object), 把函数作用于可迭代对象上， 返回一个迭代器
def f(x):
    return x * x

print(isinstance(map(f, [1, 2, 3, 4, 5, 6, 7]), Iterator))


l = list(map(f, [1, 2, 3, 4, 5, 6, 7]))
print(l)


for i in map(f, [1, 2, 3, 4, 5, 6, 7]):
    print ("%r " % i, end='')

print()

# reduce() reduce(f, [x1, x2, x3, x4]) = f(f(f(x1, x2), x3), x4)
def add(x, y):
    return x + y

print(reduce(add, range(1,10,2)))

print(isinstance(reduce(add, range(1,10,2)), Iterator))
print(isinstance(reduce(add, range(1,10,2)), Iterable))

def str2int(s):

    def fn(x, y):
        return x * 10 + y

    def char2num(s):
        return {'0': 0, '1': 1,'2': 2, '3': 3, '4': 4, '5': 5,'6': 6, '7': 7,'8': 8, '9': 9}[s]

    return reduce(fn, map(char2num, '123456789'))

print(type(str2int('123456789')))

def normalize(name):
    return  name.capitalize()

L1 = ['adam', 'LISA', 'barT']
L2 = list(map(normalize, L1))
print(L2)

def prod(L):
    def f(x, y):
        return x * y
    return reduce(f, L)

print('3 * 5 * 7 * 9 =', prod([3, 5, 7, 9]))



def str2float(s):

    fn = lambda x, y: x * 10 + y
    char2num = lambda ch:  {'0': 0, '1': 1,'2': 2, '3': 3, '4': 4, '5': 5,'6': 6, '7': 7,'8': 8, '9': 9}[ch]
    integer, decimal = s.split('.')
    return reduce(fn, map(char2num, integer)) + reduce(fn, map(char2num, decimal)) / (10**len(decimal))

print("str2float('123.456') =", str2float('123.456'))

