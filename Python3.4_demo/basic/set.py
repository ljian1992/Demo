# -*- coding: utf-8 -*-
__author__ = 'Ljian'

# #  set是一个无序不重复元素集, 基本功能包括关系测试和消除复元素, 支持 交， 并， 差，对称差 集合操作

# 创建set
s = set((2, 3, 4))
print(s)

s = set(list(range(2, 5)))
print(s)

s =  set((2, 3, 4, 4, 4))
print(s)

# 利用set无重复特性，除去列表中重复的元素
l = [1, 2, 3, 3, 4]
s = set(l)
print("\n去除重复")
print("list:", l)
print("set:", s)


# 集合操作： 并集， 交集， 差值， 对称差值

x = set((1, 3, 4, 7, 9))
y = set((2, 1, 5, 9))

a = x | y       # 并集
b = x & y       # 交集
c = x - y       # 差集
d = x ^ y       # 对称差

print("\n并集， 交集， 差集， 对称差集")


print("x: ", x)
print("y:", y)

print("并(x | y)： ", x | y)
print("交(x & y)： ", x & y)
print("差(x - y)： ", x - y)
print("对称差集s(x ^ y)： ", x ^ y)











