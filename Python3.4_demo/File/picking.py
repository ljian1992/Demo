# -*- coding: utf-8 -*-
__author__ = 'Ljian'

import pickle
import io

# 序列化: 将对象的状态信息转换为可以存储或传输的形式的过程
# 反序列化: 从存储区读取，从新创建对象
# picking:
# unpicking:

with open('pickle.txt', 'wb+') as f:
    d = {'name': 'Ljian'}
    pickle.dump(d, f)

with open('pickle.txt', 'rb+') as f:
    d = pickle.load(f)
    print(d)





