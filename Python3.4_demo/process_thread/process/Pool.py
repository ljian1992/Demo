#!/usr/bin/env python3
# -*- coding: utf-8 -*-

__author__ = 'Ljian'

from multiprocessing import Pool
import time, os

# Pool
#   常用方法：apply_async(func[, args[, kwds[, callback[, error_callback]]]])--添加进程，非阻塞
#           apply(func[, args[, kwds]]): 添加进程，阻塞
#           close():  关闭pool,使其不接受新的任务
#           terminate(): 结束工作进程，处理任务未完成的也结束
#           join():等待Pool中的进程退出，在close()或terminate()后调用
#

def pool_func():
    print("Pid: %r" % os.getpid())
    time.sleep(1)
    print("end Pid: %r" % os.getpid())

def pool_func_return(number):
    print("Pid: %r" % os.getpid())
    time.sleep(1)
    print("end Pid: %r" % os.getpid())
    return number

if __name__ == '__main__':
    pool = Pool(processes = 2)

    print("---------------阻塞-----------------")
    for i in range(3):
        pool.apply(pool_func)

    print("Waiting for all subprocesses done")
    pool.close()
    pool.join()
    print("All subprocesses done")


    pool = Pool(processes = 2)
    print("------------------非阻塞----------------")
    for i in range(3):
        pool.apply_async(pool_func)

    print("Waiting for all subprocesses done")
    pool.close()
    pool.join()
    print("All subprocesses done")

    print("------------------获取进程的返回值--------------")
    pool = Pool(processes = 2)
    result = []
    for i in range(3):
        result.append(pool.apply_async(pool_func_return, (i,)))     # 返回结果为一个ApplyResultd对象，通过get方法可以获取对象值

    print("Waiting for all subprocesses done")
    pool.close()
    pool.join()
    print("All subprocesses done")

    for res in result:
        print(type(res))
        print("return value: ", res.get())  # 获取返回结果的get()方法是阻塞的，


