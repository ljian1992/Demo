# coding : utf-8

__author__ = 'Ljian'

# str为不可变对象，
Ljian = 'Ljian'
Ljian2 = Ljian.replace('L', 'l')    #Ljian.replace()创建了一个新的对象并返回该对象的引用
print(Ljian)
print(Ljian2)

# ord() 字符-->整数
print(ord('a'))
print(ord('玲'))

# chr() 整数-->字符
print(chr(97))
print(chr(29618))

# Python的字符串类型str, 在内存中以Unicode表示, 存在磁盘上或在网络上传输,则转换为bytes， 因为Unicode编码消耗空间大
byte = b'Ljian'
string = 'Ljian'

# len(str)--计算字符个数, len(bytes)--计算是字节对象
print("byte: %r len: %d" % (byte, len(byte)))
print("str: %r, len: %d" % (string, len(string)))

print(len('中'.encode('utf-8')))

# encode():从unicode编码为指定的编码格式，
# decode():从制度的编码方式解码为unicode的方式



