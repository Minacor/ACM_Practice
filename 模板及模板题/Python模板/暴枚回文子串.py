import math
from decimal import Decimal
import random
import string
import copy


# 输出所有的回文子串

s = 'abcba'
l = len(s)

for pos in xrange(0,l):
    i,j = pos,pos
    while i >= 0 and j < l :
        if s[i] == s[j] :
            print s[i:j+1]
            i-=1
            j+=1
        else :
            break
    i,j = pos,pos+1
    while i >= 0 and j < l :
        if s[i] == s[j] :
            print s[i:j+1]
            i-=1
            j+=1
        else :
            break
        
        