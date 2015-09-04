# -*- coding: utf-8 -*-
__author__ = 'Ljian'
import traceback
import logging
logging.basicConfig(level=logging.INFO)

# python的异常体系：官方帮助：https://docs.python.org/3/library/exceptions.html
# 所有的异常都是继承了BaseException的子类，

# <-------------------try....except....finally...---------------------

# <---------------------输出异常栈到控制台--------
try:
    r = 10 / 0
except ZeroDivisionError as e:
    print("ZeroDivisionError: ", e)
    traceback.print_exc()
else:
    print("No Error")
finally:
    print("End")


# <---------------------输出异常栈到文本--------
try:
    r = 10 / 0
except ZeroDivisionError as e:
    print("ZeroDivisionError: ", e)
    traceback.print_exc(file=open('exception.log', 'w+'))
else:
    print("No Error")
finally:
    print("End")


