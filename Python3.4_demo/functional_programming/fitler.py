# -*- coding: utf-8 -*-
__author__ = 'Ljian'
from collections import Iterator


# filter()把传入的函数依次作用于每个元素，然后根据返回值是True还是False决定保留还是丢弃该元素。
def is_odd(n):
    return n % 2 == 1

print(list(filter(is_odd, range(10))))
print(isinstance(filter(is_odd, range(10)), Iterator))


def not_empty(s):
    return s and s.strip()

print(list(filter(not_empty, ['A', '', 'B', None, 'C', '  '])))


# 埃氏筛法求素数
def primes():
    def _odd_iter():
        n = 1
        while True:
            n += 2
            yield n

    def _not_divisible(n):
        return lambda x: x % n != 0

    yield 2

    it = _odd_iter()
    while True:
        n = next(it)
        yield n
        it = filter(_not_divisible(n), it)

for n in primes():
    if  n < 10:
        print(n, end=' ')
    else:
        print()
        break
