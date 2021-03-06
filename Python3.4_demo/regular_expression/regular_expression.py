#!/usr/bin/env python3
# -*- coding: utf-8 -*-

__author__ = 'Ljian'
import re

# 匹配单字符：
#   \d -- 数字
#   \w -- 字母或数字
#   .  -- 任意字符
#   \s -- 空格，tab也是空格
# 匹配变长字符：
#   *  -- 任意个字符，包括0个
#   +  -- 至少一个字符
#   ?  -- 表示0或1个字符
#   {n} -- 表示n个字符
#   {n, m} -- 表示n-m个字符
#
#   精确匹配
#   [] -- 精确匹配
#   |  -- 或
#   ^  -- 表示行的开头
#   $  -- 表示行的结束
# 小例子：1.\d{3}\s+\d{3,8}: \d{3}--匹配3个数字; \s+匹配至少一个空格; \d{3,8}--匹配3-8个数字
#       2. [0-9a-zA-Z\_]:匹配一个数字，字母或者下划线
#       3. [0-9a-zA-Z\_]+: 匹配一个至少有数字，字母或者下火线的字符
#       4. [a-zA-_][0-9a-zA-Z\_]*: 匹配一个由字母，下划线开头后面接一个由数字，字母或者下划线组成的字符串
#       5. [a-zA-Z\_][0-9a-zA-Z\_]{0, 19}:加上个数限制
#       6. [p|P]ython: 匹配python或Python
#


if __name__ == '__main__':
    r = re.match(r'^\d{3}\-\d{3,8}$', '010-12345')  # match()方法，匹配返回Match对象，失败返回None
    print(r)

    l = re.split(r'[\s\,\;\_]+', 'a, sdf, ;;; _c')
    print(l)

    # 分组,用()表示要提取的分组
    r = re.match(r'^(\d{3})\-(\d{3,8})$', '010-12345')
    print(r.group(0))
    print(r.group(1))
    print(r.group(2))

    # 非贪婪匹配
    r = re.match(r'^(\d+)(0*)$', '123400')      #默认是贪婪匹配，^(\d+)已经把整个给匹配完了
    print(r.groups())

    r = re.match(r'^(\d+?)(0*)$', '123400')
    print(r.groups())

    #编译     re模块先编译正则表达式，然后再匹配，若正则表达式经常使用，则应编译了，直接匹配
    r_complited = re.compile(r'^(\d{3})\-(\d{3,8})$')
    print(r_complited.match('012-123456').groups())