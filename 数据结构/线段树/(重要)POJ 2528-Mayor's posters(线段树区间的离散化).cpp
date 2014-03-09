/*
 * 题意：
 * 往一个墙上贴海报，贴的位置为[l,r]，问依次贴完之后还能看见几张海报
 *
 * 思路：
 * 区间的离散化
 * 然后线段树维护一个区间内的颜色(用数字表示)，统计所有区间有多少不同的数字种类就行了
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
//const int MAXN = 100000+10;
const int inf = 522133279;
const int mod = 1000000007;

map<int , int> mir;
map<int,int> cnt;
int tmpmir[20010];
int pos;
int t;
int rr,n;

struct node
{
    int v;
    int lr;         //lr区分左右区间
    bool operator < (const node& b)const
    {
        return v<b.v;
    }
}q[40010];

int qu[10010][2];

struct seg
{
    int l;
    int r;
    int v;
}tree[100010];

void init()
{
    clr(tree,0);
    clr(q,0);
    cnt.clear();
    mir.clear();
    pos=0;
}

void gao()
{
    scanf("%d",&n);
    for(int i = 1 ; i <= n ; i++)
    {
        scanf("%d%d",&qu[i][0],&qu[i][1]);
        q[pos].v = qu[i][0];
        q[pos++].lr=-i;
        q[pos].v = qu[i][1];
        q[pos++].lr=i;
    }
    sort(q,q+pos);

    rr=1;
    int tmp = q[0].v;
    for(int i = 0 ; i < pos ; i++)
    {
        if(tmp != q[i].v) tmp=q[i].v,rr++;
        if(q[i].lr<0)
            qu[-q[i].lr][0]=rr;
        else qu[q[i].lr][1]=rr;
    }
}

void build(int root , int l , int r)
{
    tree[root].l=l;
    tree[root].r=r;
    tree[root].v=0;

    if(l==r)
        return;
    int mid = MID(l,r);

    build(lson(root),l,mid);
    build(rson(root),mid+1,r);
}

void modify(int root , int l , int r , int v)
{
    if(tree[root].l >= l && tree[root].r <= r)
    {
        tree[root].v=v;
        return;
    }

    if(tree[root].v)
    {
        tree[lson(root)].v=tree[root].v;
        tree[rson(root)].v=tree[root].v;
        tree[root].v=0;
    }

    int mid = MID(tree[root].l,tree[root].r);

    if(mid >= l)
        modify(lson(root),l,r,v);
    if(mid < r)
        modify(rson(root),l,r,v);
}

void solve(int root)
{
    if(tree[root].v)
    {
        cnt[tree[root].v]++;
        return;
    }

    int mid = MID(tree[root].l,tree[root].r);

    solve(lson(root));
    solve(rson(root));
}

int main()
{
    scanf("%d",&t);
    while(t--)
    {
        init();
        gao();
        build(1,1,rr);

        for(int i = 1 ; i <= n ; i++)
        {
            //printf("* %d * %d *\n",q[i].l,q[i].r);
            modify(1,qu[i][0],qu[i][1],i);
        }
        solve(1);
        printf("%d\n",cnt.size());
    }
    return 0;
}
