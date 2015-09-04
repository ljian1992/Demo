# -*- coding: utf-8 -*-
__author__ = 'Ljian'
import functools

# 偏函数---把函数的默认参数固定下来的函数，可以通过functools.partial()方法来创建一个偏函数
# 当参数参数太多，但部分参数可以固定的时候，创建偏函数来简化函数的调用

int2 = functools.partial(int, base=2)
print(int2('110011'))
