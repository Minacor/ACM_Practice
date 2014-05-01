/*
 * 题意：
 * 给一副连通图，求至少加多少条边使得图双联通
 *
 * 思路：
 * 首先图缩点成树，然后用定理：
 *
 * 定理：
 * 若要使得任意一棵树，在增加若干条边后，变成一个双连通图，那么
 * 至少增加的边数 =（ 这棵树总度数为1的结点数 + 1 ）/ 2
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
#include "list"
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
#define PI acos(-1.0)
#define mkp make_pair
using namespace std;
typedef long long LL;
const int MAXN = 10000+10;
const int inf = 522133279;
const int mod = 1000000007;

struct edge
{
    int s;
    int t;
    int next;
    int isb;
    int chongbian;
}e[20100];

int n,m;
int head[5010],cnt;
int clo,low[5010],dfn[5010];
int totpart,part[5010];
int sum,du[5010];

void add(int s, int t)
{
    for(int i = head[s] ; ~i ; i=e[i].next)
    {
        if(e[i].t == t)
        {
            e[i].chongbian=e[i^1].chongbian=1;
            return ;
        }
    }

    e[cnt].s = s;
    e[cnt].t = t;
    e[cnt].next = head[s];
    e[cnt].chongbian = e[cnt].isb = 0;
    head[s] = cnt++;

    e[cnt].s=t;
    e[cnt].t=s;
    e[cnt].next = head[t];
    e[cnt].chongbian = e[cnt].isb = 0;
    head[t] = cnt++;
}

void init()
{
    clr(head,-1);
    clr(dfn,0);
    clr(part,0);
    sum=clo=cnt=totpart=0;
    clr(du,0);
}

void tarjan(int cur , int fa)
{
    low[cur] = dfn[cur] = ++clo;

    for(int i = head[cur] ; ~i ; i=e[i].next)
    {
        int next = e[i].t;
        if(!dfn[next])
        {
            tarjan(next,cur);
            low[cur] = min(low[cur],low[next]);

            if(low[next] > dfn[cur] && e[i].chongbian == 0)
                e[i].isb = e[i^1].isb = 1;
        }
        else if(fa!=next)
            low[cur] = min(low[cur],dfn[next]);
    }
}

void find_bg(int cur,int type)
{
    part[cur] = type;
    for(int i = head[cur] ; ~i ; i=e[i].next)
    {
        int next = e[i].t;
        if(!part[next] && !e[i].isb)
            find_bg(next,type);
    }
}

int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        init();
        for(int i = 0 ; i < m ; i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            add(a,b);
        }
        tarjan(1,-1);

        for(int i = 1 ; i <= n ; i++)
        {
            if(!part[i])
                find_bg(i,++totpart);
        }

        for(int i = 0 ; i < cnt ; i+=2)
            if(part[e[i].s] != part[e[i].t])
                du[part[e[i].s]]++,du[part[e[i].t]]++;
        for(int i = 1 ; i <=totpart ; i++)
            sum += (du[i] == 1);
        printf("%d\n",(sum+1)/2);
    }
    return 0;
}

