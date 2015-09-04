# -*- coding: utf-8 -*-
__author__ = 'Ljian'

# 生成器存在的原因：节约空间，当列表的元素可以安装某种算法推算处理时，循环过程中不断的推算出后续元素就不必要传教一个完整的list的，
# 节约大量的空间。
#       没有下一个元素时，抛出StopIteration
# 方法1：改一下列表生成式，把[],改为(), 缺点--无法完成复杂的算法推算
l = [x * x  for x in range(10)]
g = (x * x  for x in range(10))

print(l)

for x in g:
    print("%d, " % x, end='')

print()

# 方法2：yield关键字，把函数变为生成器，优点--可以实现复杂的推算，
# yield实现的原理：通过线程挂起实现

def fib(max):
    n, a, b = 0, 0, 1
    while n < max:
        yield a
        a, b = b, a + b
        n = n + 1
    return 'done'

for n in fib(5):
    print("%d, " % n, end='')
print()
# 拿到生成器的返回值
g = fib(5)
while True:
    try:
        x = next(g)
        print(x)
    except StopIteration as e:
        print ("Generator return value: %r" % e.value )
        break



