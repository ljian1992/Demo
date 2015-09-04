# -*- coding: utf-8 -*-
__author__ = 'Ljian'

from multiprocessing import Process, Lock
import sys


def lock_locked(lock, filename):
    lock.acquire()
    try:
        with open(filename, 'a+') as f:
            count = 5
            while count > 0:
                print("In lock_locked")
                f.write("In lock_locked\n")
                count -= 1
    finally:
        lock.release()

def lock_acquire(lock, filename):
    lock.acquire()
    try:
        with open(filename, 'a+') as f:
            count = 5
            while count > 0:
                print("In lock_acquire")
                f.write("In lock_acquire\n")
                count -= 1
    finally:
        lock.release()

if __name__ == '__main__':
    lock = Lock()
    f = "file1.txt"
    Process(target = lock_locked, args = (lock, f)).start()
    Process(target = lock_acquire, args = (lock, f)).start()





