# coding=utf-8
import math
from decimal import Decimal
import random
import string
import copy
import operator

''' 
    ����:
    �����ɸ�01,11,10,00��ÿ����������ת180��
    Ҫ�����ž���ʹ�þ���ÿһ�еĺ͵����ֵ��С

    ˼·��
    ̰�Ĳ��ԣ��Ȱ���11���ٰ���01(��10)�������00�������з�ת
    ���ݣ�
    ���°��ŵ��������������
    00 �� 01 ��  10
    11   00    00
    �⼸��������ô��ת���滻��������ʹ���ֵ����
    11 �� 11
    01   10
    �������滻Ҳ��
    10
    01
    �����������ŵģ����������з�һ�֣�ż���з���һ��
    
    ����11�϶���Ҫƽ����̯��ÿһ�еģ���Ȼ
    Ȼ�������Ĳ���m��'11'�����Ǽ��еþ�����'00'ȥ���������Բ����ڷ���11֮�����ȷ�00����ֹ00��������
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
    print (' '.join(out))[::-1 if i&1 else (i&1)==0] #list���������

    