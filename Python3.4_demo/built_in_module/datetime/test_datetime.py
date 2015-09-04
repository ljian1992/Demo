#!/usr/bin/env python3
# -*- coding: utf-8 -*-

__author__ = 'Ljian'

from datetime import datetime, timedelta, timezone
import sys



if __name__ == '__main__':
    # 获取当前时间
    now = datetime.now()
    print(now)
    print(type(now))

    # 创建一个datetime对象
    dt = datetime(2015, 8, 20, 20, 35)
    print(dt)

    # datatime-->timestamp
    # epoch time: 从1970-01-01 00:00:00 UTC
    # timestamp: 当前时间对于epoch time到现在的秒数,它和时区是没有关系的,在Python中，小数代表毫秒一下的时间
    now = datetime.now()
    print(now.timestamp())

    # timestamp --> datatime, utctime
    # datetime是与时区有关的， fromtimestamp()采用了当前操作系统的时区
    # 本地时间 = UTC + 时区差（东正，西负）
    ts = 1430009545
    print(datetime.fromtimestamp(ts))   # 本地时间
    print(datetime.utcfromtimestamp(ts)) # UTC时间

    # str --> datetime
    dt = datetime.strptime('2015-3-20 0:0:0', '%Y-%m-%d %H:%M:%S')
    print(dt)

    # datetime --> str
    now = datetime.now()
    tstr = now.strftime('%Y-%m-%d %H:%M:%S年')
    print(tstr)

    # datetime加减运算
    # 通过timedelta可加减的时间：microseconds milliseconds seconds minutes hours days weeks
    now = datetime.now()
    print("now: ", now)
    print("now + 1hour + 23minutes + 50 seconds: ", now + timedelta(hours = 1, minutes = 23, seconds = 50))

    # 本地时间 --> UTC时间
    # timezone: 设置datetime类的时区
    utc_8 = timezone(timedelta(hours = 8))
    now = datetime.now()
    print(now)
    dt = now.replace(tzinfo = utc_8)    #更改时区
    print(dt)
    print(datetime.utcnow())

    # 时区转换, 需用用到astimezone()方法
    utc_dt = datetime.utcnow().replace(tzinfo=timezone.utc)
    print(utc_dt)

    # utc --> utc+08:00
    bj_dt = utc_dt.astimezone(timezone(timedelta(hours = 8)))
    print(bj_dt)

    # utc --> utc+09:00
    tokyo_dt = utc_dt.astimezone(timezone(timedelta(hours = 9)))
    print(tokyo_dt)

    # utc+09:00 --> utc+08:00       转换是以utc为基准的
    print(tokyo_dt.astimezone(timezone(timedelta(hours = 8))))