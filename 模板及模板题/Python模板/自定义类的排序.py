# coding=utf-8
import math
from decimal import Decimal
import random
import string
import copy
import operator
import re

class n:
    def __init__(self , a,b):
        self.nn = a;
        self.mm = b;
    def __str__(self):
        return str(self.nn) + '*' + str(self.mm)
    def __cmp__(self,other):        #����nn�Ӵ�С��Ȼ��mm��С����
        if self.nn == other.nn:
            return -1 if self.mm < other.mm else 0 if self.mm == other.mm else 1
        else :
            return 1 if self.nn < other.nn else -1
        
aaa = []

for i in range(10):
    aaa.append(n((i+1)/2,random.randint(1,100)))

for i in range(10) :
    print aaa[i],
print

aaa.sort(cmp=None, key=None, reverse=False)
for i in range(10) :
    print aaa[i],

    

    
    
    
