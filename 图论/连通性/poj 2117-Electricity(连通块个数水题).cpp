
/*
 * 题意：
 * 给一个图(不一定连通),求去掉一个点之后最多有多少连通块
 *
 * 思路：
 * 先求出原来连通块的数量，然后求出那一个块去掉一个点之后能够得到最多的块
 * 注意一定是会去掉一个点的！也就是说n 0的情况下答案是n-1而非n
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

int n,m;

struct edge
{
    int s;
    int t;
    int next;
}e[1000000*2+100];

int cnt,head[10010];
int dfn[10010],low[10010],clo;
int subnet[10010];
int block;

void init()
{
    cnt=clo=block=0;
    clr(dfn,0);
    clr(subnet,0);
    clr(head,-1);
}

void add(int s,int t)
{
    e[cnt].s=s;
    e[cnt].t=t;
    e[cnt].next = head[s];
    head[s] = cnt++;

    e[cnt].s=t;
    e[cnt].t=s;
    e[cnt].next = head[t];
    head[t] = cnt++;
}

void tarjan(int cur,int fa)
{
    dfn[cur] = low[cur] = ++clo;

    for(int i = head[cur] ; ~i ; i=e[i].next)
    {
        int next = e[i].t;
        if(!dfn[next])
        {
            tarjan(next,cur);
            low[cur] = min(low[cur],low[next]);

            if(low[next] >= dfn[cur])
                subnet[cur]++;
        }
        else
            low[cur] = min(dfn[next],low[cur]);
    }
}
int main()
{
    while(~scanf("%d%d",&n,&m) && (n||m))
    {
        init();
        for(int i = 0 ; i < m ; i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            add(a,b);
        }

        for(int i = 0 ; i < n ; i++)
            if(!dfn[i])
            {
                subnet[i]=-1;
                tarjan(i,-1);
                block++;
            }
        int ans = *max_element(subnet,subnet+n);
        printf("%d\n",ans+block);
    }
    return 0;
}
