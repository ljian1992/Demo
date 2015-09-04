#!/usr/bin/env python3
# -*- coding: utf-8 -*-

__author__ = 'Ljian'

import threading

balance = 0

def change_it(n):
    global balance
    balance = balance + n
    balance = balance - n

def run_thread(lock, n):
    for i in range(100):
        lock.acquire()
        try:
            change_it(n)
        finally:
            lock.release()


if __name__ == '__main__':
    lock = threading.Lock()

    t1 = threading.Thread(target=run_thread, args=(lock, 2))
    t2 = threading.Thread(target=run_thread, args=(lock, 3))
    t1.start()
    t2.start()
    t1.join()
    t2.join()
    print(balance)

