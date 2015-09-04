# -*- coding: utf-8 -*-
__author__ = 'Ljian'

def is_sub_string(s1, s2):
    tag = False
    if s2.find(s1) != -1:
        tag = True
    return tag

def isSubstring1(s1, s2):
    return True if s2.find(s1) != -1 else False


# 在Python中 False == 0, True==1
def is_sub_string2(s1, s2):
    return [False, True][s2.find(s1) != -1]

