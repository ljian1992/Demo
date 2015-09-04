# -*- coding: utf-8 -*-
__author__ = 'Ljian'

from io import StringIO
from io import BytesIO

# StringIo就是指从内存中读写str, 就是相当于在内存中创建出一个文件,文件，文件

# 字符串数据
f = StringIO()
f.write("hello\n")
f.write("Ljian")

print(f.getvalue())

for line in f.readlines():
    print(line)

# 二进制数据
f = BytesIO()
f.write('中国'.encode('utf-8'))
print(f.getvalue())
