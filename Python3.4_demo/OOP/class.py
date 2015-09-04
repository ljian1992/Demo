# -*- coding: utf-8 -*-
__author__ = 'Ljian'




class Student(object):
    # 类变量, 就是C++中的static 变量, 该变量属于整个类
    class_name = 'Student'
    name = 'Student'

    # 实例对象中的变量, 实例对象中的变量优先级比类变量中的要高，同名会屏蔽掉类变量
    def __init__(self, name, age, gender='female'):
        self.name = name
        self.age = age
        self.gender = gender

stu = Student('Ljian', 23, 'male')

print(Student.class_name)
print(stu.name)
del stu.name
print(stu.name)
