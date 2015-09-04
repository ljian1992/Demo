# -*- coding: utf-8 -*-
__author__ = 'Ljian'

from collections import Iterable
from collections import Iterator


#可迭代对象--可以直接用于for循环的
#迭代器--可以被next()函数调用并返回下一个值得对象

print("isinstance([], Iterable): ", isinstance([], Iterable))
print(" isinstance({}, Iterable): ", isinstance({}, Iterable))
print("isinstance('Ljian', Iterable): ", isinstance('Ljian', Iterable))
print("isinstance(1234, Iterable): ",isinstance(1234, Iterable))

print("isinstance((x**2 for x in range(0, 10)), Iterable): ",isinstance((x**2 for x in range(0, 10)), Iterable))

print("\n\n")
print("isinstance([], Iterator): ", isinstance([], Iterator))
print("isinstance({}, Iterator): ",isinstance({}, Iterator))
print("isinstance('Ljian', Iterator): ", isinstance('Ljian', Iterator))
print("isinstance(1234, Iterator): ",isinstance(1234, Iterator))

print("isinstance((x**2 for x in range(0, 10)), Iterator): ", isinstance((x**2 for x in range(0, 10)), Iterator))


print("isinstance(iter('Ljian'), Iterator): ", isinstance(iter('Ljian'), Iterator))

