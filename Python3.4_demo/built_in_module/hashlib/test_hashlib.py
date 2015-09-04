#!/usr/bin/env python3
# -*- coding: utf-8 -*-

__author__ = 'Ljian'
import hashlib

# 摘要算法:对任意长度的数据计算尺固定长度的摘要，计算出来的摘要与数据相关，即便改变一个bit,摘要结果都会完全不同
# 通常用来做数据验证
# 常见的摘要算法：
#       MD5: 128bits的摘要
#       SHA1: 160bits的摘要

if __name__ == '__main__':

    # 一次性计算
    md5 = hashlib.md5()
    md5.update('Ljian'.encode('utf-8'))

    namemd5 = hashlib.md5()
    namemd5.update('ljian'.encode('utf-8'))

    if md5.hexdigest() != namemd5.hexdigest():
        print("unequal")

    # 多次计算
    md5_cp = hashlib.md5()
    md5_cp.update('Lj'.encode('utf-8'))
    md5_cp.update('ian'.encode('utf-8'))

    if md5.hexdigest() == md5_cp.hexdigest():
        print("equal")

    print(md5_cp.hexdigest())







