/*
 * ���⣺
 * �����г���Ϊn���ַ���(���Ǵ�д��ĸ���)�������������ַ�������
 * ������һ���ַ��������г���Ϊm�Ļ��Ĵ��� >= k
 *
 * ˼·:
 * ����n��������dfs����ģʽ��
 * ģʽ���������������:1 2 1 3...ǰk���������������������ֲ�ͬ��ʾ��λ�õ���ĸ��ͬ
 * ���ʵ�ʴ��ĸ�����C(26,ģʽ���в�ͬ���ֵ�������)
 * Ѱ�һ��Ĵ�����ż��������
 */

#line 2 "PalindromfulString.cpp"
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

class PalindromfulString {
public:
    int n,m,k;
    LL sum;
    int cnt;

    LL calc(int a[20])
    {
        LL z=1,tmp=26;
        map<int,int> lis;
        lis.clear();
        for(int i = 0 ; i < n ; i++)
            lis[a[i]]++;
        int len = lis.size();
        while(len--)
            z*=(tmp--);

        return z;
    }

    LL gao(int a[20])
    {
        cnt=0;
        for(int pos = 0 ; pos < n ; pos++)
        {
            for(int i = pos,j = pos+1 ; i>=0 && j <n && a[i]==a[j] ; i--,j++)
                if(j-i+1==m)
                {
                    cnt++;break;
                }
            for(int i = pos , j = pos ; i>=0 && j < n && a[i]==a[j] ; i--,j++)
                if(j-i+1==m)
                {
                    cnt++;break;
                }
        }

        if(cnt >= k)
        {
            return calc(a);
        }
        return 0;
    }

    void dfs(int a[20],int id,int maxid,int cnt)
    {
        maxid=max(maxid,id);
        a[cnt] = id;
        if(cnt==n-1)
        {
            sum += gao(a);
            return ;
        }

        for(int i = 1 ; i <= maxid+1 ; i++)
            dfs(a,i,maxid,cnt+1);
    }

    long long count(int N, int M, int K)
    {
        n=N,m=M,k=K; sum=0;
        int a[20];
        memset(a,0,sizeof a);
        dfs(a,1,1,0);

        return sum;
    }
}