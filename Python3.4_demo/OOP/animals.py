# -*- coding: utf-8 -*-
__author__ = 'Ljian'

#!/usr/bin/env python3
# -*- coding: utf-8 -*-

class Animal(object):
    def run(self):
        print('Animal is running...')

class Dog(Animal):
    def run(self):
        print('Dog is running...')

class Cat(Animal):
    def run(self):
        print('Cat is running...')

def run_twice(animal):
    animal.run()
    animal.run()

a = Animal()
d = Dog()
c = Cat()

print('a is Animal?', isinstance(a, Animal))
print('a is Dog?', isinstance(a, Dog))
print('a is Cat?', isinstance(a, Cat))

print('d is Animal?', isinstance(d, Animal))
print('d is Dog?', isinstance(d, Dog))
print('d is Cat?', isinstance(d, Cat))

run_twice(c)


# 动态语言的鸭子类型，只要对象看起来像鸭子，那它就是鸭子
# class Timer有call Animal同样的方法run(), 在run_twice()开来，class Timer的对象就是class Animal的对象
class Timer(object):
    def run(self):
        print("Start...")

run_twice(Timer())

