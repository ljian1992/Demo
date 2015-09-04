# -*- coding: utf-8 -*-
__author__ = 'Ljian'

import time
import os
import traceback
from multiprocessing import Process, Queue
from queue import Empty, Full


# Queue([maxsize]): 多进程安全队列，可用于进程间传递数据, 类似于Linux C中的消息队列
# 常用方法：qsize() --  获取queue大致上的大小
#         empty() --  判断queue中是否存在数据
#         full()  --  判断queue中是否满数据
#
#         put(obj[,block[,timeout]]) -- 把object加入queue中， 参数默认值 block = True, timeount = None
#            block=True and timeout > 0 --->阻塞timeount时间，直到队列有空间，超时则爬出queue.Full异常
#            block=False --->queue已满，立即判处queue.Full异常(要import queue)
#
#         get([block[,timeout]])  -- 从queue中读取并删除一个元素, 参数默认值 block = True, timeount = None
#            block=True and timeout > 0 --->阻塞timeount时间，直到队列不为空，超时则爬出queue.Empty异常
#            block=False --->queue为空，立即抛出queue.Empty异常

def proc_write(queue):
    try:
        count = 5
        while count > 0:
            queue.put("Ljian", block = False)
            count -= 1
    except Full:
        print("queue.Full: ")
        traceback.print_exc()


def proc_read(queue):
     try:
        while True:
            print(queue.get(block = False))

     except Empty:
        print("queue.Empty: ")
        traceback.print_exc()


if __name__ == '__main__':
     queue = Queue()
     Process(target = proc_write, args = (queue, )).start()
     time.sleep(3)
     Process(target = proc_read, args = (queue, )).start()