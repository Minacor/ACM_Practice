/*
 * 题意：
 * 给一个数列，有这样一种操作：一次交换任意两个相邻的数，若干次操作后这个数列就变成升序了
 * 求最少的操作次数
 *
 * 思路：
 * 最优做法就是：把一个数交换到后面的数都比它大为止，这就是冒泡的思想，答案也就是冒泡的次数
 * 但是这题数据量50W，冒泡就呵呵了
 *
 * 但是考虑到，对于一个数，它的交换次数就是由它和它后面的数组成的逆序对数
 * (逆序对就是序列中，满足 i<j 且 Ai > Aj 的数对(Ai,Aj) , 逆序数就是序列中逆序对的总数)
 *
 * 所以本题就是求逆序数，树状数组解决，即反过来求，每一次求的是当前数前面比他大的数的数量，再加起来
 *
 * 但由于数据范围0~999999999，树状数组的pos不可能定位到那么大，所以需要离散化
 * 离散化的作用是将数据量缩小，仅保持他们之间的大小关系，使得能够被树状数组维护
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

int tree[500000+100];
int ok;
int n;

struct node
{
    int v;
    int id;

    bool operator < (const node& b)const
    {
        if(!ok)
            return v<b.v;
        else
            return id<b.id;
    }

}num[500000+100];

int lowbit(int t)
{
    return t & -t;
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
    for( ; pos <= n ; pos += lowbit(pos))
        tree[pos] += delta;
}

int main()
{
    while(~scanf("%d",&n) && n)
    {
        ok=0;
        memset(tree,0,sizeof tree);

        for(int i = 1 ; i <= n ; i++)
        {
            scanf("%d",&num[i].v);
            num[i].v++;
            num[i].id=i;
        }

        sort(num+1,num+1+n);    //按照v的大小排序使得能够根据他们的大小关系离散化，缩小数据量

        num[1].v=1;
        for(int i = 2 ; i <= n ; i++)
        {
            if(num[i].v != num[i-1].v)
                num[i].v=i;
        }

        ok=1;
        sort(num+1,num+1+n);    //还原原序

        LL ans=0;
        for(int i = 1 ; i <= n ; i++)
        {
            modify(num[i].v,1);
            ans += getsum(n) - getsum(num[i].v);
        }

        printf("%I64d\n",ans);

    }

    return 0;
}
