# -*- coding: utf-8 -*-

__author__ = 'Ljian'

def multipliers():
    return [lambda x : i * x for i in range(4)]


if __name__ == '__main__':
    print([m(2) for m in multipliers()])

    l = multipliers()

    for i in l:
        print(type(i))


