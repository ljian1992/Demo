# -*- coding: utf-8 -*-
__author__ = 'Ljian'


# <-----------------------------MixIn---------------------------
class RunnableMixIn(object):
    def run(self):
        print('Running...')

class FlyableMixIn(object):
    def fly(self):
        print('Flying...')

class Animal(object):
    pass

class Dog(Animal, RunnableMixIn):
    pass

class Bird(Animal, FlyableMixIn):
    pass

dog = Dog()
dog.run()




# <-----------------------------多继承的菱形问题------------------------
# 需要多继承的原因：现实的对象具有多个类的特征和行为，例如：我是个程序员，有同时是单身狗。


# 多继承的菱形问题：子类继承多个父类的时候，父类中有同名变量或方法，而子类又没有覆盖定义变量或方法，这造成了调用上的歧义
# 解决办法的思路：消除歧义，使其具有唯一性
# python中的解决办法：确定方法解析顺序（MRO）, 通过算法（C3算法）来确定属性和方法查找的顺序进而解决多继承带来的歧义
# java的解决办法：禁止多继承，采用接口提供”多继承“。
#                   接口的特性：1.接口具有抽象方法，继承类中必须实现该方法，多个接口中的方法同名，但实现只有一份，具有唯一性，不产生歧义
#                             2.接口只能具有静态变量，待思考
# C++的解决办法：
#
class A(object):
    name = 'A'
    def func(self):
        print("In Class A")

class B(A):
     name = 'B'

     def func(self):
        print("In Class B")

class C(A):
     name = 'C'
     def func(self):
        print("In Class C")

# 继承的方法解析顺序(MRO)在python中是通过C3算法查找, 可以通过__mro__这个特殊变量，查看解析顺序
class D(C, B):
    pass

class E(B, C):
    pass

print(D.__mro__)

d = D()

print(d.name)
e = E()
d.func()
e.func()



