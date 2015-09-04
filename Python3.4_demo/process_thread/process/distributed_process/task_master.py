#!/usr/bin/env python3
# -*- coding: utf-8 -*-

__author__ = 'Ljian'
import random, time, queue, os
from multiprocessing.managers import  BaseManager
from multiprocessing import freeze_support

task_queue = queue.Queue()      # 发送任务队列

result_queue = queue.Queue()    # 接收结果队列

def return_task_queue():
    global task_queue       # 由于worker需要调用，所以用global
    return task_queue
def return_result_queue():
    global result_queue
    return result_queue

class QueueManager(BaseManager):
    pass


if __name__ == '__main__':
    freeze_support()        # window 平台需要调用freeze_support()

    # 把queue注册到网络上
    QueueManager.register('get_task_queue', callable = return_task_queue)
    QueueManager.register('get_result_queue', callable = return_result_queue)

    # 绑定IP和端口
    manager = QueueManager(address=('127.0.0.1', 5001), authkey=b'abc')

    # 启动服务
    manager.start()

    task = manager.get_task_queue()
    result = manager.get_result_queue()

    for i in range(10):
        n = random.randint(0, 10000)
        print("Put task %r..." % i)
        task.put(n)


    print("Try get results...")
    for i in range(10):
        r = result.get(timeout=10)
        print("Result: %r" % r)

    manager.shutdown()
    print("master exit....")