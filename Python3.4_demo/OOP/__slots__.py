# -*- coding: utf-8 -*-
__author__ = 'Ljian'
from types import MethodType


class Student(object):
    pass

#<----------------------绑定实例属性-------------
s = Student()
s.name = 'Ljian'
print(s.name)

#<---------------------绑定类属性----------------
Student.name2 = 'Ljian2'
print(s.name2)

#<---------------------绑定实例方法----------------
def set_age(self, age):
    self.age = age

s.set_age = MethodType(set_age, s)
s.set_age(23)
print(s.age)

#<-------------------绑定类方法--------------------
def set_score(self, score):
    self.score = score

Student.set_score = MethodType(set_score, Student)

s.set_score(30)
print(s.score)

# <-----------------------------__slots__限制实例的属性-------------------
# 用tuple限制运行绑定的实例属性, __slots__只对当前类实例器作用，对基础子类不起作用
# 但是不能限制类进行属性绑定，可以通过绑定类方法，类方法中添加属性这种方法，突破__slots__的限制，但最好自觉点不要这么做
class Student(object):
    __slots__ = ('name')        #在类中添加了__slots__属性后类的实例将不会有__dict__属性

class Teacher(object):
   def __init__(self, name):
       self.name = name

s = Student()
#s.score = 78

#print(s.score)

t = Teacher('ljian')


if not ['__dict__'] in dir(s):
    print("no __dict__")


if  '__dict__' in dir(t):
    print("has __dict__")



# 子类定义__slots__限制绑定的属性为，子类的限制的属性为：__slots__限制的和父类__slots__限制的的并集
class OldStudent(Student):
    __slots__ = ('score')
    pass

s = OldStudent()
s.score = 78
print(s.score)

s.name = 'Ljian'
print(s.name)

#s.abc = 'abc'
#print(s.abc)

#<----------------------突破__slots__的限制-----------------------------
class Student(object):
    __slots__ = ('name', 'number','score', 'age')
    pass

def set_gender(self, gender):
    self.gender = gender


Student.set_gender = MethodType(set_gender, Student)
s = Student()
s.set_gender('male')

print(s.gender)



