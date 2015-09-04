#!/usr/bin/env python3
# -*- coding: utf-8 -*-

__author__ = 'Ljian'
import time, sys, queue
from multiprocessing.managers import BaseManager

class QueueManager(BaseManager):
    pass



if __name__ == '__main__':

    server_addr = '127.0.0.1'

    # 从网络上获取queue, 名字要和主机注册时一致
    QueueManager.register('get_task_queue')
    QueueManager.register('get_result_queue')

    print("Connect to server %s..." % server_addr)

    # 绑定服务器IP和端口号
    m = QueueManager(address=(server_addr, 5001), authkey=b'abc')

    # 连接
    m.connect()

    task = m.get_task_queue()
    result = m.get_result_queue()

    for i in range(10):
        try:
            n = task.get(timeout=1)
            print('run task %d * %d...' %(n, n))
            r = '%d * %d = %d ' % (n, n, n*n)
            time.sleep(1)
            result.put(r)
        except queue.Empty:
            print("task queue is empty.")

    print("worker exit")