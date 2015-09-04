# -*- coding: utf-8 -*-
__author__ = 'Ljian'

from datetime import datetime
import time
import multiprocessing

def proc(interval):
    print("proc start:", datetime.now())
    time.sleep(interval)
    print("prc, end:", datetime.now())

if __name__ == '__main__':
    # daemon属性 -- 父进程终止后，自动终止，而且子进程不能产生新的进程
    p = multiprocessing.Process(target = proc, args = (4,))
    p.daemon = True
    p.start()
    print("end deamon process")

