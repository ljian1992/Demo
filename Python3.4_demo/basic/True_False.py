# -*- coding: utf-8 -*-
__author__ = 'Ljian'

# True False为class bool 唯一的两个对象并且class bool为class int 的子类
# True == 1, False == 0
print(1 == True)
print(-2 == True)
print(2 == True)

print (0 == False)
print(-2 == False)
print(2 == False)

def is_sub_string(s1, s2):
    return [False, True][s2.find(s1) != -1]

s1 = 'ABCD'
s2 = 'ABCDEFG'
s3 = 'BCDEFG'

print(is_sub_string(s1, s2))
print(is_sub_string(s1, s3))




# 在ptyhon中： '', (), [], {}, None, set() 为False, 否则为True
# False:  '', (), [], {}, None, set()
# True: 非'', (), [], {}, None, set()
def print_true_false(condition):
    print ('True' if condition else 'False')

condition1 = ''
condition2 = ' '
print_true_false(condition1)
print_true_false(condition2)

condition1 = ()
condition2 = (1,)
print_true_false(condition1)
print_true_false(condition2)

condition1 = []
condition2 = [1,]
print_true_false(condition1)
print_true_false(condition2)

condition1 = {}
condition2 = {'1': 1}
print_true_false(condition1)
print_true_false(condition2)

condition1 = None
print_true_false(condition1)

condition1 = set()
condition2 = set(range(10))
print_true_false(condition1)
print_true_false(condition2)



