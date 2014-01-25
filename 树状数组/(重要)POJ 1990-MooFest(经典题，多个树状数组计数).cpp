/*
 * 题意：
 * 有n头牛排在一条直线上，每头牛都有他的x坐标值x和一个听力阈值v，
 * 两头牛i,j能够交流的条件是以vol = max(vi,vj)的声音等级哞哞，并且产生的音量是vol*dis(i,j) = vol*|xi-xj|
 * 求每一对牛产生的总音量
 *
 * 思路：
 * 本题最重要的就是计数问题，先把牛按照v值从大到小排序
 * 那么当遍历到牛i时，能保证前i-1头牛的v值都小于它的v，这样前几头牛与i交流的声音等级就是vi了
 * 所以对于每一个i，我们只要获得前i头牛和它产生的音量之和，再累加到总音量，答案就出来了
 * 那么如何获得音量之和，换句话说，什么数据结构能在处理i时快速得到之前对当前有影响的和值？那就是树状数组了
 * 用两个树状数组，一个记录坐标值总和，一个记录牛的头数
 * 当然在所有比i的v值小的牛中，会有x值比i大或小的牛，此时就要分左右计算，但算法其实相似
 * 左边getsum(0)获得比i的x小的牛的x值总和lsum，getsum(1)获得这些牛的头数lcnt，那么他们到i的距离之和就是lcnt*i.x-lsum,分左右就是因为正负的关系
 * 右边类似，不过rcnt可以直接计算:我们已经用了i-1头牛，左边lcnt头，右边就是i-1-lcnt了
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
struct niu
{
    int x;
    int v;

    bool operator < (const niu&b)const
    {
        return v < b.v;
    }

}moo[20100];

int tree[2][20100]; //0:维护坐标值总和，1:维护牛的数量

int lowbit(int t)
{
    return t&-t;
}

int getsum(int op , int pos)
{
    int t=0;
    for( ; pos > 0 ; pos -= lowbit(pos))
        t += tree[op][pos];
    return t;
}

void modify(int op ,int pos , int delta)
{
    for( ; pos <= 20100 ; pos += lowbit(pos))
        tree[op][pos] += delta;
}

int main()
{
    //FR;
    while(~scanf("%d",&n))
    {
        memset(tree,0,sizeof tree);
        for(int i = 1 ; i <= n ; i++)
            scanf("%d%d",&moo[i].v , &moo[i].x);
        sort(moo+1,moo+1+n);

        LL res=0;
        for(int i = 1 ; i <= n ; i++)
        {
            LL lsum=getsum(0,moo[i].x),lcnt=getsum(1,moo[i].x);     //比当前牛坐标值小的牛的坐标值总和,牛的数量
            LL rsum = getsum(0,20010)-lsum,rcnt=i-1-lcnt;           //比当前牛坐标值大的牛的坐标值总和,牛的数量
            res += ((lcnt*moo[i].x-lsum) + (rsum-rcnt*moo[i].x))*moo[i].v;
            modify(0,moo[i].x,moo[i].x);        //计数更新的delta是1，那么坐标值的直接加上坐标值即可
            modify(1,moo[i].x,1);
        }

        printf("%I64d\n",res);
    }

    return 0;
}
