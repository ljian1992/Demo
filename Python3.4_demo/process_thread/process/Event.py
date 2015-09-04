# -*- coding: utf-8 -*-
__author__ = 'Ljian'

import time
import os
from multiprocessing import Process, Event

# Event: 进程间的简单的通信机制，进程A, B, C...等待event, 进程X发送event
# Event和Linux C中条件变量有点类似,但它不像Linux C中的条件变量依赖于互斥锁，
# 常用方法：is_set()---判断是否内部标识是否被设置
#         set()---内部标识 = True
#         clear()---内部标识 = False
#         wait(timeout=None)   等待内部标识为真


def wait_for_event(event):
    print("Pid: %r  start wait_for_event" % os.getpid())
    event.wait()
    print("Pid: %r  internal flag = %r" % (os.getpid(), event.is_set()))

def wait_for_event_timeout(event, timeount):
    print("Pid: %r  start wait_for_event_timeout" % os.getpid())
    event.wait(timeount)
    print("Pid: %r internal flag = %r" % (os.getpid(), event.is_set()))

if __name__ == "__main__":
    event = Event()

    for i in range(4):
        Process(target = wait_for_event, args = (event, )).start()
    Process(target = wait_for_event_timeout, args = (event, 3)).start()

    time.sleep(5)

    event.set()
    print("called event.set()")
