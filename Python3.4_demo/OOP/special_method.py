# -*- coding: utf-8 -*-
__author__ = 'Ljian'

# 定制类可以用来表现一下特殊行为，响应某些内建函数，响应操作符
# 实现的机制：”鸭子类型“机制，例如，Fib类具有__iter__（）方法，那么就是一个可迭代对象

class Fib(object):
    def __init__(self, max_number):
        self.a, self.b = 0, 1
        self.max_number = max_number

    def __iter__(self):         # 实现可迭代
        return self

    def __next__(self):         # 获取迭代值
        self.a, self.b = self.b, self.a + self.b
        if self.a > self.max_number:
            raise StopIteration
        return self.a

    def __getitem__(self, n):   # 可被下标取值, 这里没有对切片进行处理
        a, b = 1, 1
        for x in range(n):
            a, b = b, a + b
        return a

    def __getattr__(self, attr):   # 属性或方法不存在时，调用__getattr__()去获取得属性
        if attr == 'name':         #  不设置，默认是返回None
            return 'name'          #

    def __call__(self):             #直接对实例自调
        print("call Fib")


fib = Fib(1000)

print(fib.name)

print(fib.name2)

fib()   # 实例自己调用自己

for n in Fib(1000):
    print(n)

print(Fib(1000)[5])

#
# 基本定制型                                              描述
# C.__init__(self[, arg1, ...])              构造器(带一些可选的参数)
# C.__new__(self[, arg1, ...])            构造器(带一些可选的参数);通常用在设置不变数据类型的子类。
# C.__del__(self)                              解构器
# C.__str__(self)                               可打印的字符输出;内建 str()及 print 语句
# C.__repr__(self)                            运行时的字符串输出;内建 repr() 和‘‘ 操作符
# C.__unicode__(self)                      Unicode 字符串输出;内建 unicode()
# C.__call__(self, *args)                   表示可调用的实例
# C.__nonzero__(self)                     为 object 定义 False 值;内建 bool() (从 2.2 版开始)
# C.__len__(self)                             “长度”(可用于类);内建 len()
#
#
#
# 对象(值)比较
# C.__cmp__(self, obj)                     对象比较;内建 cmp()
# C.__lt__(self, obj) and                   小于/小于或等于;对应<及<=操作符
# C.__gt__(self, obj) and                  大于/大于或等于;对应>及>=操作符
# C.__eq__(self, obj) and                 等于/不等于;对应==,!=及<>操作符
#
# 属性
# C.__getattr__(self, attr)                 获取属性;内建 getattr();仅当属性没有找到时调用
# C.__setattr__(self, attr, val)          设置属性
# C.__delattr__(self, attr)                 删除属性
# C.__getattribute__(self, attr)         获取属性;内建 getattr();总是被调用
# C.__get__(self, attr)                      (描述符)获取属性
# C.__set__(self, attr, val)                (描述符)设置属性
# C.__delete__(self, attr)                 (描述符)删除属性
#
#
#
# 定制类/模拟类型
# 数值类型:二进制操作符
# C.__*add__(self, obj)                    加;+操作符
# C.__*sub__(self, obj)                    减;-操作符
# C.__*mul__(self, obj)                    乘;*操作符
# C.__*div__(self, obj)                     除;/操作符
# C.__*truediv__(self, obj)               True 除;/操作符
# C.__*floordiv__(self, obj)              Floor 除;//操作符
# C.__*mod__(self, obj)                  取模/取余;%操作符
# C.__*divmod__(self, obj)             除和取模;内建 divmod()
# C.__*pow__(self, obj[, mod])       乘幂;内建 pow();**操作符
# C.__*lshift__(self, obj)                 左移位;<<操作符
# C.__*rshift__(self, obj)                 右移;>>操作符
# C.__*and__(self, obj)                   按位与;&操作符
# C.__*or__(self, obj)                     按位或;|操作符
# C.__*xor__(self, obj)                   按位与或;^操作符
#
#
#
# 数值类型:一元操作符
# C.__neg__(self)                           一元负
# C.__pos__(self)                           一元正
# C.__abs__(self)                           绝对值;内建 abs()
# C.__invert__(self)                        按位求反;~操作符
#
# 数值类型:数值转换
# C.__complex__(self, com)          转为 complex(复数);内建 complex()
# C.__int__(self)                            转为 int;内建 int()
# C.__long__(self)                         转为 long;内建 long()
# C.__float__(self)                         转为 float;内建 float()
#
# 数值类型:基本表示法(String)
# C.__oct__(self)                           八进制表示;内建 oct()
# C.__hex__(self)                         十六进制表示;内建 hex()
#
# 数值类型:数值压缩
# C.__coerce__(self, num)           压缩成同样的数值类型;内建 coerce()
# C.__index__(self)                      在有必要时,压缩可选的数值类型为整型(比如:用于切片索引等等)
#
#
# 序列类型
# C.__len__(self)                         序列中项的数目
# C.__getitem__(self, ind)           得到单个序列元素
# C.__setitem__(self, ind,val)     设置单个序列元素
# C.__delitem__(self, ind)           删除单个序列元素
# C.__getslice__(self, ind1,ind2) 得到序列片断
# C.__setslice__(self, i1, i2,val)   设置序列片断
# C.__delslice__(self, ind1,ind2)  删除序列片断
# C.__contains__(self, val)          测试序列成员;内建 in 关键字
#
# C.__*add__(self,obj)                串连;+操作符
# C.__*mul__(self,obj)                重复;*操作符
# C.__iter__(self)                        创建迭代类;内建 iter()
#
#
# 映射类型
# C.__len__(self)                         mapping中的项的数目
# C.__hash__(self)                      散列(hash)函数值
# C.__getitem__(self,key)           得到给定键(key)的值
# C.__setitem__(self,key,val)     设置给定键(key)的值
# C.__delitem__(self,key)           删除给定键(key)的值
# C.__missing__(self,key)          给定键如果不存在字典中,则提供一个默认值


