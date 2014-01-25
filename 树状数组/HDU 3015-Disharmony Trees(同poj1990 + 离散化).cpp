/*
 * 题意:
 * 给一堆树排成一排，他们有各自的高度和x坐标，以x升序排定一个rank，h升序排定一个rank，然后定义一个差别度
 * 最后求的是差别度的和
 *
 * 思路:
 * 和poj1990差不多，只是多了离散化的步骤
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
int order=1;

struct node
{
    int h;
    int x;
    int lvh;
    int lvx;

    bool operator<(const node& b)const
    {
        if(order==1)
            return x < b.x;
        else if(order == 2)
            return h < b.h;
        else
            return lvh > b.lvh;
    }
}t[100000+100];

LL tree[2][100000+100];

int lowbit(int x)
{
    return x&-x;
}

int getsum(int op , int pos)
{
    LL x=0;
    for( ; pos > 0 ; pos -= lowbit(pos))
        x += tree[op][pos];
    return x;
}

void modify(int op , int pos , int delta)
{
    for( ; pos <= n ; pos += lowbit(pos))
        tree[op][pos] += delta;
}

int main()
{
    //FR;

    while(~scanf("%d",&n))
    {
        order=1;
        memset(tree,0,sizeof tree);

        for(int i = 1 ; i <= n ; i++)
        {
            scanf("%d%d",&t[i].x,&t[i].h);
        }

        sort(t+1,t+1+n);

        t[1].lvx=1;
        LL ans=0;

        for(int i = 2 ; i <= n ; i++)
        {
            if(t[i-1].x != t[i].x)
                t[i].lvx = i;           //千万要注意rank是怎么安排的！！并不是连续的！！
            else
                t[i].lvx = t[i-1].lvx;
        }

        order=2;
        sort(t+1,t+1+n);

        t[1].lvh=1;

        for(int i = 2 ; i <= n ; i++)
        {
            if(t[i-1].h != t[i].h)
                t[i].lvh = i;
            else
                t[i].lvh = t[i-1].lvh;
        }


        for(int i = n ; i >= 1 ; i--)
        {
            LL lsum = getsum(0,t[i].lvx) , lcnt = getsum(1,t[i].lvx);
            LL rsum = getsum(0,n)-lsum , rcnt = n-i-lcnt;

            ans += ((lcnt*t[i].lvx-lsum) + (rsum - rcnt*t[i].lvx))*t[i].lvh;

            modify(0,t[i].lvx,t[i].lvx);
            modify(1,t[i].lvx,1);
        }

        printf("%I64d\n",ans);
    }

    return 0;
}
