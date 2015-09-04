# -*- coding: utf-8 -*-
__author__ = 'Ljian'

from enum import Enum, unique


# 这有点类似于dict: 'Jan':1, 'Feb':2 ....
week_day = Enum('WeekDay', ('Sun', 'Mon', 'Tue', 'Wed', 'Thu', 'Fri', 'Sat'))

#
for name, member in week_day.__members__.items():
    print("name: %r, member: %r" % (name, member))



print(week_day.Sun)
#week_day.Sun = 'Sunday'
#print(week_day.Sun)

@unique         #装饰器unique,检查有没有重复的值
class WeekDay(Enum):
    Sun = 0
    Mon = 1
    Tue = 2
    Wed = 3
    Thu = 4
    Fri = 5
    Sat = 6
