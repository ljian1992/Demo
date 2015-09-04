# -*- coding: utf-8 -*-
__author__ = 'Ljian'
import multiprocessing
import os
import time

# 在Windows没有fork调用，要在Windows用Python编写多进程，需要multiprocessing模块中的Process类
# multiprocessing支持子进程、通信和共享数据、执行不同形式的同步，提供了Process、Queue、Pipe、Lock等组件。

# <--------------------Process---------------------------
# 常用方法：is_alive(), join(), run(),start() terminate()
# 进程属性：daemon--父进程终止后，自动终止，而且子进程不能产生新的进程
def print_hello(name):
    print("hello ", name)
    print("child pid: ", os.getpid())




# 继承Process类，并覆写run方法
class HelloClass(multiprocessing.Process):
    def __init__(self, name):
        #super(HelloClass, self).__init__(self)
        multiprocessing.Process.__init__(self)
        self.name = name

    def run(self):
        print("hello ", self.name)
        print("child pid: ", os.getpid())


if __name__ == '__main__':
    p = multiprocessing.Process(target = print_hello, args = ('Ljian',))
    print("father pid: ", os.getpid())
    print("start child process")
    p.start()
    p.join()
    print("end child process")



    p = HelloClass('Ljian')
    p.start()




