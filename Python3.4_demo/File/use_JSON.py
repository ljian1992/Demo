# -*- coding: utf-8 -*-
__author__ = 'Ljian'
import json



# <-------------------------------处理基本数据类型-----------------------
# Python基本数据类型-->JSON
# Python  --->  JSON
# dict	        object
# list, tuple	array
# str	        string
# int, float,   int- & float-derived Enums	number
# True	        true
# False	        false
# None	        null

obj = [{'key1': False, 'key2': True}, [1, 1, 2], (1, 1, 2), 'Ljian', 112, 112.112, None]
encodejson = json.dumps(obj)
print(obj)
print(encodejson)
print(type(encodejson))

# JSON--->Python基本数据类型
# JSON	 --->   Python
# object	    dict
# array	        list    array是转换成list，不能转换成tuple
# string	    str
# number (int)	int
# number (real)	float
# true	        True
# false	        False
# null	        None

decodejson = json.loads(encodejson)
print(decodejson)


# 编码时的数据处理，json.dumps() sort_keys, indent, separators
data1 = {'1': 1, '2': 2, '3': 3}
data2 = {'2': 2, '1': 1, '3': 3}

# sort_keys 参数使得dict数据，按照(a到z)排序存储，这样就可以对json对象进行比较了
d1 = json.dumps(data1, sort_keys = True)
d2 = json.dumps(data1)
d3 = json.dumps(data2, sort_keys = True)

print("%r\n %r\n %r\n" % (d1, d2, d3))

print("d1 == d2?: ", d1 == d2)
print("d1 == d3?: ", d1 == d3)

# indent, 缩进使道数据存储的格式好看点，可读性高点，但是却增加了数据量。

data = {'a': 1, 'b': 2, 'c': 3}

d1 = json.dumps(data)
d2 = json.dumps(data, indent = 4)
d3 = json.dumps(data, separators = (',', ':'))


print(d1)
print("dumps(data): ", len(d1))

print(d2)
print("dumps(data, intent = 4): ", len(d2))

print(d3)
print("dumps(data, separators)", len(d3))

# <-------------------------------处理自建数据类型-----------------------
# json.dumps()不支持直接转换object为JSON文件，需要把object对象转化为JSON可以处理的基本数据类型
# dumps: object-->dict-->json
# loads: json-->dict-->object
class Student(object):
    def __init__(self, name, age):
        self.name = name
        self.age = age

# 方法1. 自己把转换函数给写了
# 在转换的过程中，不但要把对象变量给转换了，也要把对象所属的类和模块给转换，以确实JSON中的信息是哪种
# 类对象的信息，这样的才能恢复成原来的对象
def object2dict(obj):
    d = {}
    d['__class__'] = obj.__class__.__name__
    d['__module__'] = obj.__module__

     # 这里需要注意的是不是所有的对象都__dict__属性的，在类中添加了__slots__属性后类的实例将不会有__dict__属性
    d.update(obj.__dict__)
    return d

def dict2object(d):
    if '__class__' in d:
        class_name = d.get('__class__')
        module_name = d.get('__module__')
        module = __import__(module_name)
        class_ = getattr(module, class_name)
        args = d.copy()
        args.pop('__class__')
        args.pop('__module__')
        inst = class_(**args)
    else:
        inst = d

    return inst


s = Student('Ljian', 23)
sdump = json.dumps(s, default = object2dict)

print(type(sdump))

sobj = json.loads(sdump, object_hook = dict2object)
print(type(sobj))

# 方法2：基础JSONEncoder和JSONDecoder类，覆写相关方法



class MyEncoder(json.JSONEncoder):
    def default(self, obj):
        d = {}
        d['__class__'] = obj.__class__.__name__
        d['__module__'] = obj.__module__

        d.update(obj.__dict__)
        return d

class MyDecoder(json.JSONDecoder):
    def __ini__(self):
        super(MyDecoder, self).__init__(self, object_hook = self.dict2object)

    def dict2object(self, d):
        if '__class__' in d:
            class_name = d.get('__class__')
            module_name = d.get('__module__')
            module = __import__(module_name)
            class_ = getattr(module, class_name)
            args = d.copy()
            args.pop('__class__')
            args.pop('__module__')
            inst = class_(**args)
        else:
            inst = d
        return inst

s = Student('Ljian', 23)
sdump = MyEncoder().encode(s)
sobj = MyDecoder().decode(sdump)