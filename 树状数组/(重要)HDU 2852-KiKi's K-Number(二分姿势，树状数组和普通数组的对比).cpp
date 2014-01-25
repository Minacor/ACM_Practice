/*
 * 题意：
 * 3种操作：
 * p = 0 ，将数e加入集合
 * p = 1 ，将数e从集合中删除，如果没有这个数，输出指定字符串
 * p = 2 ，找出比a大k的数，注意这里的"大"指的是将集合中的数从小到大排列最后一个a之后的第k个数，所以n个相同的数也是要计n次的
 *
 * 思路：
 * 准备两个数组，树状数组tree维护各个数字出现次数，原数组origin也是记录出现次数
 * 只不过树状数组用来快速计算次数之和以便查询，origin是方便元素的添加和删除
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
#define lson(x) (x<<1)
#define rson(x) (x<<1|1)
#define FR (freopen("in.txt","r",stdin))
using namespace std;
typedef long long LL;
const int INF = 0xfffffff;
const int inf = 50000000;

int n;
int tree[100000+100];
int origin[100000+100];

int lowbit(int n)
{
    return n&-n;
}

int getsum(int pos)
{
    int t=0;
    for( ; pos > 0 ; pos -= lowbit(pos))
        t += tree[pos];
    return t;
}

void modify(int pos , int delta)
{
    for( ; pos <= 100000 ; pos += lowbit(pos))
        tree[pos] += delta;
}

void query(int a, int k)                //二分的姿势，以后就用这种姿势吧~
{
    if(getsum(100000)-getsum(a) < k)
    {
        puts("Not Find!");
        return;
    }

    int l=a , r = 100000;
    int mid;

    do
    {
        mid = (l + r) >> 1;

        int tmp = getsum(mid)-getsum(a);

        if(tmp >= k)            //等号很重要，别漏
            r = mid-1;
        else
            l = mid+1;
    }while(l <= r);

    printf("%d\n",l);
}

int main()
{
    FR;

    while(~scanf("%d",&n))
    {
        memset(origin,0,sizeof origin);
        memset(tree,0,sizeof tree);

        int op;

        for(int i = 0 ; i < n ; i++)
        {
            scanf("%d",&op);

            if(op == 0)             //添加和删除在原数组中操作的同时更新树状数组，其实这两个数组内容是一样的，只不过功能不同
            {
                int e;
                scanf("%d",&e);

                origin[e]++;
                modify(e,1);
            }
            else if(op == 1)
            {
                int e;
                scanf("%d",&e);

                if(origin[e] == 0) puts("No Elment!");
                else
                {
                    origin[e]--;
                    modify(e,-1);
                }
            }
            else
            {
                int a,k;
                scanf("%d%d",&a,&k);

                query(a,k);
            }
        }
    }

    return 0;
}
