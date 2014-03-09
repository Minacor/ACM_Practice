/*
 * 题意：
 * 给n条线段，这些线段都是垂直x轴的，y1,y2,x分别是线段的下y坐标，上y坐标，x坐标
 * 现在定义可达：对于线段a(y坐标[ay1,ay2])和b([by1,by2]) ,在它们的交集中取一点y，若线段(x1,y),(x2,y)仅与ab相交，那么ab就相互可达
 * 求任意取三条线段满足两两可达，这样的线段对有多少
 *
 * 思路：
 * 先按照x对线段排序是一定的
 * 然后线段树维护区间l，r内的线段id：每一条线段都有自己的id，区间值=id就表示这个区间被id这条直线覆盖了
 * 然后进行query , 如果查询到一个区间的值为v，说明当前这条线段与v这条线段是可达的
 *
 * 本题要注意的是，线段端点能够到达另一条线段，也算是可达，所以要将y坐标*2，以处理类似[3,4],[2,4]和[5,4]这种情况
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
#define MID(x,y) ((x+y)>>1)
#define FR (freopen("in.txt","r",stdin))
#define clr(a,b) memset(a,b,sizeof(a))
#define lowbit(t) (t&-t)
using namespace std;
typedef long long LL;
const int MAX = 8000+10;
const int inf = 522133279;
const int mod = 1000000007;

struct seg
{
    int x;
    int y1,y2;

    bool operator <(const seg& b)const
    {
        return x<b.x;
    }
}s[MAX];

struct
{
    int l;
    int r;
    int v;
}tree[MAX*8];

int n;
int rr;
bool g[MAX][MAX];

void build(int root , int l , int r)
{
    tree[root].l=l;
    tree[root].r=r;
    tree[root].v=0;

    if(l==r) return ;

    int mid(MID(l,r));

    build(lson(root),l,mid);
    build(rson(root),mid+1,r);
}

void modify(int root , int l , int r , int v)
{
    if(tree[root].l >= l && tree[root].r <= r)
    {
        tree[root].v=v;
        return ;
    }

    if(tree[root].v)
    {
        tree[lson(root)].v = tree[rson(root)].v = tree[root].v;
        tree[root].v=0;
    }

    int mid = (MID(tree[root].l,tree[root].r));

    if(l <= mid)
        modify(lson(root),l,r,v);
    if(r > mid)
        modify(rson(root),l,r,v);
}

void query(int root , int l, int r , int id)
{
    if(tree[root].v)        //查询到了这个值，说明以这个值为id的线段并未被先前的线段覆盖，是可达的
    {
        g[tree[root].v][id]=g[id][tree[root].v] = true;
        return;
    }

    if(tree[root].l==tree[root].r)
        return ;

    int mid = (MID(tree[root].l,tree[root].r));

    if(l<=mid)
        query(lson(root),l,r,id);
    if(r>mid)
        query(rson(root),l,r,id);
}

int main()
{
    int t;
    scanf("%d",&t);

    while(t--)
    {
        clr(tree,0);
        clr(g,false);
        rr=0;

        scanf("%d",&n);
        for(int i = 1 ; i <= n ; i++)
        {
            scanf("%d%d%d",&s[i].y1,&s[i].y2,&s[i].x);
            s[i].y1*=2;
            s[i].y2*=2;
            s[i].y1++;
            s[i].y2++;
            rr=max(rr,s[i].y2);
        }

        sort(s+1,s+1+n);
        build(1,1,rr);

        for(int i = 1 ; i <= n ; i++)
        {
            query(1,s[i].y1,s[i].y2,i);
            modify(1,s[i].y1,s[i].y2,i);
        }

        int cnt=0;
        for(int i = 1 ; i <= n ; i++)
            for(int j = i+1 ; j <= n ; j++)
                if(g[i][j])
                    for(int k = j+1; k <= n ; k++)
                        if(g[j][k]&&g[k][i])
                            cnt++;
        printf("%d\n",cnt);
    }
    return 0;
}
