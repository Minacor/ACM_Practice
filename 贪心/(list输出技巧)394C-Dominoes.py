# coding=utf-8
import math
from decimal import Decimal
import random
import string
import copy
import operator

''' 
    题意:
    有若干个01,11,10,00，每个串可以旋转180°
    要求重排矩阵使得矩阵每一列的和的最大值最小

    思路：
    贪心策略：先安排11，再安排01(或10)，最后安排00，奇数行翻转
    依据：
    上下安排的组合有这样几种
    00 或 01 或  10
    11   00    00
    这几种无论怎么翻转或替换，都不会使最大值增大
    11 或 11
    01   10
    这两者替换也是
    10
    01
    镜像安排是最优的，所以奇数行放一种，偶数行放另一种
    
    首先11肯定是要平均分摊到每一列的，显然
    然后多出来的不足m个'11'串的那几列得尽量用'00'去抵消，所以不能在放完11之后优先放00，防止00个数不够
'''

n,m = map(int,raw_input().split())

out = {}
a,b,c = 0,0,0
for i in xrange(n):
    list = raw_input().split()
    a += list.count('11')
    b += list.count('00')
c = n*m-a-b

for i in xrange(n):
    out=[]
    for j in xrange(m):
        if a > 0:
            a -= 1
            out.append('11')
        elif c > 0:
            c -=1
            out.append('01')
        else :
            out.append('00')
    print (' '.join(out))[::-1 if i&1 else (i&1)==0] #list的输出技巧

    