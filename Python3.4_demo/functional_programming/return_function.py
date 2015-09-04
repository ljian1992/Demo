# -*- coding: utf-8 -*-
__author__ = 'Ljian'

#<--------------------------返回函数------------------------------
#1.当函数返回函数时， 想的参数和变量都保持在返回函数中(这种程序结构被称为：闭包),因此不能再传递参数给返回函数
#2.返回函数，每次调用都返回一个新的函数
#3.返回函数并不是立即执行，而是在返回的函数被调用后才执行
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
    for i in range(4):
        arr.append(lambda: i*i)
    return arr

results = ret_func()
f1 = results[0]
f2 = results[1]
f3 = results[2]

# 调用函数时，i已经等于3了，因此都是打印9
print(f1())
print(f2())
print(f3())


def ret_func2():
    arr = []
    for i in range(4):
        arr.append(lambda: ((lambda x: x*x)(i)))
    return arr

results2 = ret_func2()
f4 = results2[0]
f5 = results2[1]
f6 = results2[2]

# 调用函数时，i已经等于3了，因此都是打印9
print(f4())
print(f5())
print(f6())


print((lambda x: x*x)(8))
