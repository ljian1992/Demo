# -*- coding: utf-8 -*-
__author__ = 'Ljian'


#<-------------------------------默认参数--------------------------------------
# 函数的默认参数，有点类似于C函数中的static 变量。一直存在于函数当中
# 默认参数应该设置为: None, Str，tupole 等不可改变的对象
def print_default_para(L=[]):
    L.append(1)
    print(L)

print_default_para()
print_default_para()
print_default_para()


#<------------------------------- 可变参数--------------------------------------
# 可变参数：参数的个数是可变的，可以是0个或多个,在函数调用数会自动封装成为一个tuple
def cal_sum(*numbers):
    sum = 0
    for n in numbers:
        sum += n

    return sum

# 传参：直接传入参数
print(cal_sum())
print(cal_sum(1,2,3))

# 传参：通过*把list, tuple等变为可变参数传递
print(cal_sum(*list(range(1, 5))))


#<------------------------------- 关键字参数--------------------------------------
#关键字参数:参数个数是可变的，在函数调用时，会自动封装成为一个dict
def person(name, age, **kw):
    print('name:', name, 'age:', age, 'other:', kw)

person('Ljian', 23)
person('Ljian', 23, gender = 'male')

#<-------------------------------命名关键字参数--------------------------------------
#限制关键字参数的名称, 可结合默认参数
def person(name, age, *, gender='female'):
    print(name, age, gender)


person('Ljian', 23, gender='male')
person('Ljian', 23)
#person('Ljian', 23, gende='male')


#<-------------------------------参数定义参数类型的顺序--------------------------------------
#参数定义的顺序必须是：必选参数、默认参数、可变参数/命名关键字参数和关键字参数

