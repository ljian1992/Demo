# -*- coding: utf-8 -*-
__author__ = 'Ljian'

import functools

# <--------------------------闭包------------------------------
# 1.当函数A返回函数B时， 参数和变量都保持在返回函数B中(这种程序结构被称为：闭包), A函数传递的参数称为自由变量，
#  由于自由变量被返回函数B引用了，因此不会被回收， 因此返回函数B中，不应该引用任何循环变量或者是后面会发生变量的变量。
#   这个可以通过，默认参数和偏函数来解决
# 2.返回函数，每次调用都返回一个新的函数
# 3.返回函数并不是立即执行，而是在返回的函数被调用后才执行, 称之为惰性求值

def lazy_sum(*args):
    def sum():
        ax = 0
        for n in args:
            ax += n
        return ax
    return sum

# 函数返回时，参数保存了在f中
f1 = lazy_sum(2, 4, 6, 8)
print(type(f1))
print(f1())
#

#  闭包就是携带状态的函数，并且它的状态可以完全对外隐藏起来
#  在闭包中，返回的函数没有立即执行，而是调用时，才执行
#  因此，在返回函数当中不能引用任何循环变量，或者后面会发生变化的变量
def ret_func():
    arr = []
    for i in range(3):
        arr.append(lambda: i*i)
    return arr

results = ret_func()
func1 = results[0]
func2 = results[1]
func3 = results[2]




# 调用函数时，i已经等于3了，因此都是打印9
print(func1())
print(func2())
print(func3())



# 通过默认参数解决， lambda具有作用域改变的能力，此时i已经不是自由变量那个i了, 每一个i创建了内存空间
def ret_func2():
    arr = []
    for i in range(4):
        arr.append(lambda i=i: i*i)
    return arr

results = ret_func2()
func1 = results[0]
func2 = results[1]
func3 = results[2]



# 调用函数时，i已经等于3了，因此都是打印9
print(func1())
print(func2())
print(func3())

# 通过偏函数解决，原理和通过默认参数解决是一样的
def ret_func3():
    arr = []
    for i in range(4):
        arr.append(functools.partial(lambda i: i*i, i))
    return arr

results = ret_func3()
f1 = results[0]
f2 = results[1]
f3 = results[2]

# 调用函数时，i已经等于3了，因此都是打印9
print(f1())
print(f2())
print(f3())






