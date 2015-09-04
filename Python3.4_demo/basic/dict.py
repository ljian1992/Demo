# -*- coding: utf-8 -*-
__author__ = 'Ljian'

# dict中的key要为不可变对象
#Ljian = {['name']:'ljian'}

#key重复时，默认取最后一个value
Ljian = {'name':'Ljian', 'name':'Ok'}
name = Ljian.get('name')
print(name)



Ljian = {'name' : 'Ljian', 'age' : 23, 'sex' : 'male'}

name = Ljian.get('nmae', 'no key "nmae"')
print(name)

for key in Ljian:
    print(Ljian[key])

for key, value in Ljian.items():
    print(key, value)

Ljian['name'] = 'ljian'

print(Ljian)

