/*
 * ���⣺
 * M��ÿM���ӿ���һ���ɴ�
 * N��ÿN���ӿ���һ�����͵�
 * ֻ���ڴ��͵㿪��ʱ���ܴ���һ���ɴ��������ڼ�ɴ��ȵ��Ļ��͵õ�һ��ʱ��
 * ��ɴ��ȴ���ƽ��ʱ��
 *
 * ˼·��
 * ��Ȼ�ȴ�ʱ���������Եģ�����ֻ�����һ�������ڵ�ƽ��ֵ
 * ����n�ҷɴ��ĵȴ�ʱ����N-(n*M)%N
 * �ɸ���ԭ����(M,N)==1ʱ,(n*M)%Nȡ���ҽ�һ��ȡ��[0,N-1]�е�����ֵ
 * ��(M,N)!=1ʱͬ�����ߵ����Լ���ͻ�����
 * ���������߻��ʣ���һ�������ڵ�ƽ���ȴ�ʱ�����(0+1+...+N-1)/N = (N-1)/2
 * �����ʵĻ�������gcd���Ǵ���
 * ��ʵ����(n*M)%Nȡ���ҽ�һ��ȡ��gcd(N,M)*[0,N-1]�е�����ֵ
 */

#line 2 "Starport.cpp"
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <sstream>
#define OUT(x) cerr << #x << ": " << (x) << endl
#define SZ(x) ((int)x.size())
using namespace std;
typedef long long LL;

class Starport {
public:
    LL gcd(LL a , LL b)
    {
        if(b == 0)
            return a;
        return gcd(b,a%b);
    }

    double getExpectedTime(int N, int M) {
        LL g = gcd(N,M);
        return double((N/g-1)/2.0 *g);
    }
};
