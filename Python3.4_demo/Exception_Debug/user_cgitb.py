# -*- coding: utf-8 -*-
__author__ = 'Ljian'

def func(a, b):
   return a / b


import cgitb

import sys
import traceback

cgitb.enable(format ='text')

func(1, 0)