# -*- coding: utf-8 -*-
__author__ = 'Ljian'
import functools


# <-------------------------装饰器--------------------------
# 装饰器：就是把函数再包装，添加功能，把函数赋值为包装过后的函数
# 装饰器就是闭包运用


#<--------------------无参数修饰器--------------------------
def log_no_args(func):
    @functools.wraps(func)
    def wrapper(*args, **kw):
        print("call %r" % func.__name__)
        return func(*args, **kw)
    return wrapper



# 相当于：my_func = log(my_func)
@log_no_args
def my_func(a=10, b=20):
    return a + b

my_func()
f = my_func
print(f.__name__)

#<------------------有参数修饰器----------------------------
def log_args(*text):
   def decorator(func):
       @functools.wraps(func)          #相当于wrapper.__name__ = func.__name__
       def wrapper(*args, **kw):
            print("begin call %r, text: %r" %(func.__name__, text))
            func(*args, **kw)
            print("end call %r " % func.__name__)
       return wrapper
   return decorator


#相当于：my_func2 = log_args('Hi')(my_func2)
@log_args('Hi')
def my_func2():pass

my_func2()






def log(*text):
   def decorator(func):
       @functools.wraps(func)
       def wrapper(*args, **kw):
           if text:
                print("begin call %r, text: %r" % (func.__name__, text))
                ret = func(*args, **kw)
                print("end call %r " % func.__name__)
                return ret
           else:
                print("begin call %r" % func.__name__)
                ret = func(*args, **kw)
                print("end call %r " % func.__name__)
                return ret
       return wrapper
   return decorator


@log()
def my_func3():pass

my_func3()

@log("Hi, my_func4")
def my_func4():pass
my_func4()