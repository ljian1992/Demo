#!/usr/bin/env python3
# -*- coding: utf-8 -*-

__author__ = 'Ljian'
import hashlib



db = {}


def to_md5(s):
    md5 = hashlib.md5()
    md5.update(s.encode('utf-8'))
    return md5.hexdigest()

def register(username, password):
    if username not in db:
        db[username] = to_md5(username + password +'Ljian') #通过最佳额外的字符串，来防止简单口令被逆推
    else:
        print("username exit!")


def login(username, password):
    if username in db:
        if db[username] == to_md5(username + password + 'Ljian'):
            print("login success!")
        else:
            print("password error!")
    else:
        print("username error")


if __name__ == '__main__':
    register('Ljian', '123456789')


    login('Ljian', '123456789')
    login('Ljian', 'sadf')
    login('sadf', 'sdf')
