#!/usr/bin/env python3
# -*- coding: utf-8 -*-
__author__ = 'Ljian'

import time
from multiprocessing import Process, Pipe

# Pipe([duplex]): duplex = True(default), 则为全双工管道，duplex = False, 则为单工通信conn1接受，conn2发送
# 常用方法：send()  --  发送
#         recv()  --  接受，没有消息接受，则会一直阻塞，若管道被关闭，会抛出EOFError错误

def pipe_send(pipe):
    for i in range(100):
        pipe.send(i)
        print("send: ", i)
        time.sleep(1)

def pipe_rev(pipe):
    while True:
        print("rev: ", pipe.recv())
        time.sleep(1)

if __name__ == '__main__':
    pipe = Pipe()
    Process(target = pipe_send, args = (pipe[0],)).start()
    Process(target = pipe_rev, args = (pipe[1],)).start()





