# -*- coding: utf-8 -*-
__author__ = 'Ljian'

class Student2(object):
    pass

s = Student2()

# 添加属性时没有对属性进行参数检查，可以通过设置set_score(), get_score()方法进行检查，但是这样调用起来有不直接，
# 这时就可以通过 @property来方法变成属性，
s.score = 1000

class Student(object):

    #把getter()方法变成属性，此时@property本身传创建了另外的修饰器，@score.setter，扶着把一个setter方法变成属性
    @property
    def score(self):
        return self._score      #这里要添加_

    @score.setter
    def score(self, value):
        if not isinstance(value, int):
            raise ValueError("score must be an integer!")
        if not 0 <= value <= 100:
            raise ValueError("score must between [0, 100]")
        self._score =  value

s = Student()

s.score = 99
print(s.score)

class Screen(object):

    #对外部来说是width,但对内部来说是_width
    __slots__ = ('_width', '_height', '_resolution')

    @property
    def width(self):
        return self._width

    @width.setter
    def width(self, value):
        if not isinstance(value, int):
            raise ValueError("width must be an integer!")
        if not 0 <= value <= 100:
            raise ValueError("width must between [0, 100]")
        self._width =  value

    @property
    def height(self):
        return self._width

    @width.setter
    def height(self, value):
        if not isinstance(value, int):
            raise ValueError("height must be an integer!")
        if not 0 <= value <= 100:
            raise ValueError("height must between [0, 100]")
        self._height =  value

    @property
    def resolution(self):
        return self._width * self._height


screen = Screen()
screen.height = 30
screen.width = 30

print(screen.resolution)
