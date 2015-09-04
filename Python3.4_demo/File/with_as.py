# -*- coding: utf-8 -*-
__author__ = 'Ljian'

# <-------------------with--as--语法------------------
# with as 是用来简化finnaly操作的
# with as 语言的实现，借助__enter__(), __exit__()这两个内置方法实现
# 使用，with-as语句时，
#   1.会调用__enter__方法，然后把函数的返回值返回给as指点的变量，
#   2.执行do something语句块
#   3.无论是否发生异常，执行完语句块后调用__exit__方法（出现异常会捕获异常，return True则不抛出，return False 则抛出）
#   适用范围：释放资源（文件资源，）
# class controlled_execution:
#     def __enter__(self):
#         set things up
#         return thing
#     def __exit__(self, type, value, traceback):
#         tear things down
#
# with controlled_execution() as thing:
#         do something


#<-------------__exit__处理，不抛出异常-------------------
class Sample:
    def __enter__(self):
        return self

    def __exit__(self, exc_type, exc_val, exc_tb):
        print("type:", exc_type)            # 接收异常类型，无异常则为Nome
        print("value:", exc_val)            # 接收异常描述, 无异常则为Nome
        print("exc_tb:", exc_tb)            # 接收异常栈
        return True

    def do_something(self):
        var = 10 / 0
        return var

try:
    with Sample() as sample:
        sample.do_something()
except ZeroDivisionError as e:
    print("ZeroDivisionError: ", e)
else:
    print("No Exception!!")


#<------------__exit__抛出异常---------------------------
class SampleNoDeal:
    def __enter__(self):
        return self

    def __exit__(self, exc_type, exc_val, exc_tb):
        return False

    def do_something(self):
        var = 10 / 0
        return var
try:
    with SampleNoDeal() as sample:
        sample.do_something()
except ZeroDivisionError as e:
    print("ZeroDivisionError: ", e)
else:
    print("No Exception!!")


try:
    f = open('The_Zen_of_Python')
except IOError as e:
    print('IOError: ', e)
    exit(-1)

try:
    print(f.read())
except IOError as e:
    print("IOError: ", e)
finally:
    f.close()


try:
    with open('The_Zen_of_Python') as f:
        print(f.read())
except IOError as e:
    print("IOError: ", e)