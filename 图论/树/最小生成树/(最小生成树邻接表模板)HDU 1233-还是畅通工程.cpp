/*
 * 题意：
 * 给一副完全图，求最小生成树
 */

//#pragma comment(linker, "/STACK:1024000000,1024000000")
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
#define mkp make_pair
using namespace std;
typedef long long LL;
const int MAXN = 100000+10;
const int inf = 522133279;
const int mod = 1000000007;

int n;

struct edge
{
    int s;
    int t;
    int v;
    int next;
}e[110*110*2];

int head[110],vis[110],low[110],cnt;

void init()
{
    clr(head,-1);
    clr(vis,0);
    clr(low,0x1f);
    cnt=0;
}

void add(int s , int t , int v)
{
    e[cnt].s=s;
    e[cnt].t=t;
    e[cnt].v=v;
    e[cnt].next = head[s];
    head[s] = cnt++;
}

int prim()
{
    int res=0;
    low[1]=0;
    vis[1]=1;
    for(int i = head[1] ; ~i ; i=e[i].next)
        low[e[i].t] = e[i].v;

    for(int i = 1 ; i < n ; i++)
    {
        int minc = inf,pos=-1;
        for(int j = 1 ; j <= n ; j++)
            if(!vis[j] && low[j] < minc)
                minc = low[j],pos=j;
        vis[pos]=1;
        res += minc;

        for(int j = head[pos] ; ~j ; j=e[j].next)
            if(!vis[e[j].t] && low[e[j].t] > e[j].v)
                low[e[j].t] = e[j].v;
    }
    return res;
}

int main()
{
    while(~scanf("%d",&n) && n)
    {
        int m = (n-1)*n/2;
        init();

        while(m--)
        {
            int s,t,v;
            scanf("%d%d%d",&s,&t,&v);
            add(s,t,v);
            add(t,s,v);
        }

        printf("%d\n",prim());
    }

    return 0;
}

