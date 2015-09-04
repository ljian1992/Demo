#!/usr/bin/env python3
# -*- coding: utf-8 -*-

__author__ = 'Ljian'

import threading

local_school = threading.local()

# thread调用函数时，传递该参数给处理函数
def process_student2(name):
     print('Hello, %s (in %s)' % (name, threading.current_thread().name))


# 在process_student()函数中查找thread传递过来的变量
def process_student():
    # 获取当前线程关联的student:
    std = local_school.student
    print('Hello, %s (in %s)' % (std, threading.current_thread().name))

def process_thread(name):
    # 绑定ThreadLocal的student:
    local_school.student = name
    process_student()
    process_student2(name)

if __name__ == '__main__':
    t1 = threading.Thread(target= process_thread, args=('Alice',), name='Thread-A')
    t2 = threading.Thread(target= process_thread, args=('Bob',), name='Thread-B')
    t1.start()
    t2.start()
    t1.join()
    t2.join()

