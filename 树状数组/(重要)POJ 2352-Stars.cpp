/*
 * 题意：给一群星星的坐标，定义星星等级：x，y坐标均不大于它的星星的个数，输出各等级的星星的个数
 *
 * 思路：用线段树或树状数组，
 * 由于是按y递增的坐标给出的， 所以新加入一个点只需判断区间[1，x]共有多少个点， 并更新后面包含他区间的点的个数
 * tree[i]表示x坐标区间[1,x]中的星星的个数(树状数组的功能是求和，把星星的权值设为1就相当于计数了)
 */

#include "iostream"
#include "cstring"
#include "algorithm"
#include "cmath"
#include "cstdio"
#include "sstream"
#include "queue"
#include "vector"
#include "string"
#include "stack"
#include "cstdlib"
#include "deque"
#include "fstream"
#include "map"
#include "set"
using namespace std;
typedef long long LL;
const int INF = 0xfffffff;

int tree[32100];
int cnt[15100];
int n;

int lowbit(int x)
{
    return (-x)&x;
}

int getsum(int pos)
{
    int t=0;
    for(; pos > 0 ; pos -= lowbit(pos))
        t += tree[pos];

    return t;
}

void modify(int pos , int delta)
{
    for( ; pos <= 32010 ; pos += lowbit(pos))   //向上更新，以后出现的x比pos大的都得提前更新lv，注意树状数组维护的是什么，范围不要错写成n
        tree[pos] += delta;
}

int main()
{
    scanf("%d",&n);

    for(int i = 0 ; i < n ; i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);

        a++;                //树状数组从1标号，位操作的需要

        int lv = getsum(a);
        cnt[lv]++;
        modify(a,1);

    }

    for(int i = 0 ; i < n ; i++)
    {
        printf("%d\n",cnt[i]);
    }

    return 0;
}
