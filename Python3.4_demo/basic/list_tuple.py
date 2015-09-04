# -*- coding: utf-8 -*-
__author__ = 'Ljian'
import os

numbers = list(range(10))


#切片
print(numbers[::3])
print(numbers[1])
print(numbers[-1])

print(numbers[1:8])
print(numbers[-3:-1])
#print(nubmers[-4:-1]), 不支持倒序切片


t = (1,)
#t[1] = 2

# tuple的不改变是指，指向不变, ['L', 'J']是一个列表，列表指向的值是可以改变的
t = ('L', 'J', ['L', 'J'])
print(t)
t[2][0] = 'Liang'
t[2][1] = 'Jian'
print(t)



