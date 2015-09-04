# -*- coding: utf-8 -*-
__author__ = 'Ljian'
import os

# range() --是创建一个可迭代对象, 3.4中range就是曾经的xrange
g = range(1, 11)
print(type(g))

l = [x * x for x in range(1, 11)]
print(l)

l = [x * x for x in range(1, 11) if x % 2 == 0]
print(l)

l = [d for d in os.listdir('.')]
print(l)

l = ['Ljian', 'LiangJian']
print(l)
l = [s.lower() for s in l]
print(l)





