#!/usr/bin/env python3
# -*- coding: utf-8 -*-

__author__ = 'Ljian'

# python能够改变变量作用域的代码段是def、class、lambda.
# if/elif/else、try/except/finally、for/while 不具备变量作用域的更改的能力
# 变量搜索路径遵循LEGB Rule：local --> enclosing --> global --> built-in

name  = 'global name'


if __name__ == '__main__':
    # def 改变作用域
    def print_name():
        name = "print_name name"
        return name

    assert("print_name name" == print_name())

    # class 改变作用域
    class Name():
        def __init__(self):
            self._name = "class name"

        @property
        def name(self):
            return self._name

    class_name = Name()
    assert("class name" == class_name.name)

    # if/elif/else 不改变作用域
    if True:
        age = 23
    assert(23 == age)

    # try/except/finally 不改变作用域
    try:
        x = 10
        x = x / 0
    except ZeroDivisionError:
        y = 20
    finally:
        z = 30

    assert(10 == x and 20 == y and z == 30)


    # for/while 不改变作用域
    for i in [1]:
        x = i;
        power = 2 * 2
    assert(1 == i and power == 4 and x == i)



