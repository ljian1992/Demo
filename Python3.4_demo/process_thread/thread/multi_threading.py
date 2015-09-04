#!/usr/bin/env python3
# -*- coding: utf-8 -*-

__author__ = 'Ljian'

import time, threading

# 解释器执行代码时，有一个GIL锁：Global Interpreter Lock，任何Python线程执行前，
# 必须先获得GIL锁，也就是说，任意时刻智能信息单个Python线程执行。Python中的线程不能利用到
# 多核CPU


def thread():
    print("thread %r is running........" % threading.current_thread().name)
    time.sleep(2)
    print("thread %r is end........" % threading.current_thread().name)

if __name__ == '__main__':
    print("thread %r is running........" % threading.current_thread().name)
    t1 = threading.Thread(target = thread, name = 'thread1')
    t2 = threading.Thread(target = thread, name = 'thread2')
    t1.start()
    t2.start()
    t1.join()
    t2.join()
    print("thread %r is end........" % threading.current_thread().name)

