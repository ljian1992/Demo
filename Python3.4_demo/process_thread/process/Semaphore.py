# -*- coding: utf-8 -*-
__author__ = 'Ljian'
from datetime import datetime
import time
import multiprocessing
from multiprocessing import Semaphore, Process


def proc(sem, interval):
    sem.acquire()
    try:
        print("Current process: %r, acquire, semaphore value: %r"
              % (multiprocessing.current_process().name, sem.get_value()))

        time.sleep(interval)
    finally:
        sem.release()
        print("Current process: %r, release, semaphore value: %r"
              % (multiprocessing.current_process().name, sem.get_value()))

if __name__ == '__main__':
    sem = Semaphore(2)      # 生成个信号量个数为2的，信号量对象
    print(sem.get_value())
    for i in range(4):
        Process(target = proc, args = (sem, i)).start()